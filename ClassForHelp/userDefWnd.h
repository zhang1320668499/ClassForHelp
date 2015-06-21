void SetWindowTransparent(HWND hWnd, BYTE bAlpha = 128);  // 函数声明 
//透明度范围0~255默认为128
HRGN BitmapToRegion(HBITMAP hBmp, COLORREF cTransparentColor = 0, COLORREF cTolerance = 0);  // 函数声明 
//图片的背景色默认为黑色，颜色偏差为0