
#include "stdAfx.h"
//#include "userDefWnd.h"

//设置窗体的透明度
void SetWindowTransparent(HWND hWnd, BYTE bAlpha) 
{ 
	SetWindowLong(hWnd, GWL_EXSTYLE,  
		GetWindowLong(hWnd, GWL_EXSTYLE)^0x80000); 
	
	HINSTANCE hInst = LoadLibrary(_T("User32.DLL")); 
	if(hInst) 
	{ 
		typedef BOOL (WINAPI *MYFUNC) (HWND, COLORREF, BYTE, DWORD); 
		MYFUNC fun = NULL; 
		fun = (MYFUNC) GetProcAddress(hInst, _T("SetLayeredWindowAttributes")); 
		if(fun)  fun(hWnd, 0, bAlpha, 2); 
		FreeLibrary(hInst); 
	} 
	
} 



//根据图片形状设定窗体的区域。。。。。。。。这个函数是Jean-Edouard、Lachand-Robert 写的
HRGN BitmapToRegion(HBITMAP hBmp, COLORREF cTransparentColor, COLORREF cTolerance) 
{ 
	//这里说明一下这三个参数   
	//第一个参数是   加载的是导入的Bitmap位图,VC++6.0里面的类型是CBitmap，需强制转化为HBITMAP
	//第二个参数是   COLORREF 是一个 32-bit 整型数值，它代表了一种颜色。我们可以用RGB(r,g,b)函数来进行赋值;它表示的是
	//我们设定的图片的背景色，默认值为0,黑色。
	//第三个参数是   颜色偏差默认值为0，从cTolerance的地方我们可以看出它的作用是减小颜色偏差，可能不同机器的RGB();得到的颜色不一样
	//我们设为0就可以了
	HRGN hRgn = NULL; 
	
	if (hBmp) 
	{ 
		
		HDC hMemDC = CreateCompatibleDC(NULL); 
		if (hMemDC) 
		{ 
			
			BITMAP bm; 
			GetObject(hBmp, sizeof(bm), &bm); 
			
			// Create a 32 bits depth bitmap and select it into the memory DC  
			BITMAPINFOHEADER RGB32BITSBITMAPINFO = { 
				sizeof(BITMAPINFOHEADER), // biSize  
					bm.bmWidth,     // biWidth;  
					bm.bmHeight,    // biHeight;  
					1,       // biPlanes;  
					32,       // biBitCount  
					BI_RGB,      // biCompression;  
					0,       // biSizeImage;  
					0,       // biXPelsPerMeter;  
					0,       // biYPelsPerMeter;  
					0,       // biClrUsed;  
					0       // biClrImportant;  
			}; 
			
			
			
			VOID * pbits32;  
			HBITMAP hbm32 = CreateDIBSection(hMemDC,(BITMAPINFO *)&RGB32BITSBITMAPINFO, DIB_RGB_COLORS, &pbits32, NULL,0); 
			if (hbm32) 
			{ 
				HBITMAP holdBmp = (HBITMAP)SelectObject(hMemDC, hbm32); 
				
				// Create a DC just to copy the bitmap into the memory DC 
				HDC hDC = CreateCompatibleDC(hMemDC); 
				if (hDC) 
				{ 
					
					BITMAP bm32; 
					GetObject(hbm32, sizeof(bm32), &bm32); 
					while (bm32.bmWidthBytes % 4) 
						bm32.bmWidthBytes++; 
					
					// Copy the bitmap into the memory DC 
					HBITMAP holdBmp = (HBITMAP)SelectObject(hDC, hBmp); 
					BitBlt(hMemDC, 0, 0, bm.bmWidth, bm.bmHeight, hDC, 0, 0, SRCCOPY); 
					
					
                    #define ALLOC_UNIT 100 
					DWORD maxRects = ALLOC_UNIT; 
					HANDLE hData = GlobalAlloc(GMEM_MOVEABLE, sizeof(RGNDATAHEADER)+(sizeof(RECT) * maxRects)); 
					RGNDATA *pData = (RGNDATA *)GlobalLock(hData); 
					pData->rdh.dwSize = sizeof(RGNDATAHEADER); 
					pData->rdh.iType = RDH_RECTANGLES; 
					pData->rdh.nCount = pData->rdh.nRgnSize = 0; 
					SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0); 
					BYTE lr = GetRValue(cTransparentColor); 
					BYTE lg = GetGValue(cTransparentColor); 
					BYTE lb = GetBValue(cTransparentColor); 
					BYTE hr = min(0xff, lr + GetRValue(cTolerance)); //cTolerance出现
					BYTE hg = min(0xff, lg + GetGValue(cTolerance)); 
					BYTE hb = min(0xff, lb + GetBValue(cTolerance)); 
					
					
					BYTE *p32 = (BYTE *)bm32.bmBits + (bm32.bmHeight - 1) *bm32.bmWidthBytes; 
					for (int y = 0; y < bm.bmHeight; y++) 
					{ 
						// Scan each bitmap pixel from left to right 
						for (int x = 0; x < bm.bmWidth; x++) 
						{ 
							
							int x0 = x; 
							LONG *p = (LONG *)p32 + x; 
							while (x < bm.bmWidth) 
							{ 
								BYTE b = GetRValue(*p); 
								if (b >= lr && b <= hr) 
								{ 
									b = GetGValue(*p); 
									if (b >= lg && b <= hg) 
									{ 
										b = GetBValue(*p); 
										if (b >= lb && b <= hb) 
											// This pixel is "transparent" 
											break; 
									} 
								} 
								p++; 
								x++; 
							} 
							
							if (x > x0) 
							{ 
								
								if (pData->rdh.nCount >= maxRects) 
									
								{ 
									GlobalUnlock(hData); 
									maxRects += ALLOC_UNIT; 
									hData  =  GlobalReAlloc(hData,sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), GMEM_MOVEABLE); 
									pData = (RGNDATA *)GlobalLock(hData); 
								} 
								RECT *pr = (RECT *)&pData->Buffer; 
								SetRect(&pr[pData->rdh.nCount], x0, y, x, y+1); 
								if (x0 < pData->rdh.rcBound.left) 
									pData->rdh.rcBound.left = x0; 
								if (y < pData->rdh.rcBound.top) 
									pData->rdh.rcBound.top = y; 
								if (x > pData->rdh.rcBound.right) 
									pData->rdh.rcBound.right = x; 
								if (y+1 > pData->rdh.rcBound.bottom) 
									pData->rdh.rcBound.bottom = y+1; 
								pData->rdh.nCount++; 
								
								if (pData->rdh.nCount == 2000) 
								{ 
									HRGN  h  =  ExtCreateRegion(NULL,sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), pData); 
									if (hRgn) 
									{ 
										CombineRgn(hRgn, hRgn, h, RGN_OR); 
										DeleteObject(h); 
									} 
									else 
										hRgn = h; 
									pData->rdh.nCount = 0; 
									SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG,0, 0); 
								} 
							} 
						} 
						
						// Go to next row (remember, the bitmap is inverted vertically) 
						p32 -= bm32.bmWidthBytes; 
					} 
					
					// Create or extend the region with the remaining rectangles 
					HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) +(sizeof(RECT) * maxRects), pData); 
					if (hRgn) 
					{ 
						CombineRgn(hRgn, hRgn, h, RGN_OR);
						DeleteObject(h); 
					} 
					else 
						hRgn = h; 
					
					// Clean up 
					GlobalFree(hData); 
					
					SelectObject(hDC, holdBmp); 
					DeleteDC(hDC); 
    } 
	
    DeleteObject(SelectObject(hMemDC, holdBmp)); 
   } 
   
   DeleteDC(hMemDC); 
  } 
 } 
 
 return hRgn; 
} 