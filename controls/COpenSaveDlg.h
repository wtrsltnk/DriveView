#ifndef COPENSAVEDLG_H
#define COPENSAVEDLG_H

#include <windows.h>
#include <string>
using namespace std;

class COpenSaveDlg
{
private:
	HWND				m_hOwner;
	HWND				m_hWnd;
	HINSTANCE			m_hInstance;

public:
	COpenSaveDlg( HINSTANCE, HWND );
	~COpenSaveDlg( void );

    string open( const char *title, const char *szFilter, const char *szDefExt );
    string save( const char *title, const char *szFilter, const char *szDefExt );
};

#endif
