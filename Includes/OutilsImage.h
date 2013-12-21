//#include "afx.h"
#include "afxwin.h"


BOOL WriteDIB( LPCTSTR szFile, HANDLE hDIB);

HANDLE DDBToDIB( CBitmap& bitmap, DWORD dwCompression, CPalette* pPal );

BOOL WriteWindowToDIB( LPCTSTR szFile, CWnd *pWnd );

bool SauverImage(CString nomfichier, CWnd *wnd);