void SetWindowTransparent(HWND hWnd, BYTE bAlpha = 128);  // �������� 
//͸���ȷ�Χ0~255Ĭ��Ϊ128
HRGN BitmapToRegion(HBITMAP hBmp, COLORREF cTransparentColor = 0, COLORREF cTolerance = 0);  // �������� 
//ͼƬ�ı���ɫĬ��Ϊ��ɫ����ɫƫ��Ϊ0