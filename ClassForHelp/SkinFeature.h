#ifndef _SKINFEATURE_H__
#define _SKINFEATURE_H__

//Application    Interface
#ifdef __cplusplus  
extern "C"
{
#endif
	
#define  ERROR_UNKNOWNFILEFORMAT  0x00001
#define  ERROR_WRONGPASSWORD	  0x00002
	////////////////////////////////////////////////////////////////////////////
	
	//初始化skinfeature界面库
	BOOL __stdcall InitializeSkin();
	
	//加载一个皮肤文件(.rss 文件) pszFileName 为要装载的skinfeature皮肤文件
	BOOL __stdcall LoadSkinFile(LPCTSTR  pszFileName, LPCTSTR pszPassWord = NULL);
	
	//从资源加载皮肤
	BOOL __stdcall LoadSkinFromResource(HINSTANCE hInstance, LPCTSTR pszResourceName,
		LPCTSTR pszResourceType, LPCTSTR pszFileName, LPCTSTR pszPassWord = NULL);
	
	//移除皮肤
	BOOL __stdcall RemoveSkin();
	
	//退出skinfeature界面库，释放内存资源。
	BOOL __stdcall UnLoadSkin();
	
	//设置异型窗体的资源ID
	BOOL __stdcall SetShapeWindowSkin(HWND hWnd,int nResID);
	
	//设置皮肤色调 参数为要转换成的皮肤颜色
	void __stdcall SetThemeColour( COLORREF color );
	
	//对指定的窗口进行换肤
	//hWnd			: 指定的窗口句柄
	//pszName	    : 需要更换皮肤样式的控制名称
	void __stdcall SetWindowSkinHwnd(HWND hWnd, LPCTSTR pszName = NULL);
	
	//永久去掉指定窗口的皮肤样式.
	//hWnd			: 指定的窗口句柄
	//bChildNoSkin	: 是否对该窗口中的子窗口去掉皮肤
	void __stdcall SetWindowNoSkinHwnd(HWND hWnd, BOOL bChildNoSkin = TRUE);
	
	//对指定的窗口去掉皮肤,若需要再次换肤可以通过SetWindowSkinHwnd进行皮肤样式更换
	void __stdcall RemoveWindowSkinHwnd(HWND hWnd);
	
	//设置是否需要用户自己绘制对话框背景.
	void __stdcall SetDialogEraseBkgnd(HWND hWnd, BOOL bErase = TRUE);
	
	BOOL __stdcall SetWindowSkinResID(HWND hWnd, int nResID);
	
	
#ifdef __cplusplus
}
#endif  //__cplusplus

#endif

