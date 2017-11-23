#include "COpenSaveDlg.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////

COpenSaveDlg::COpenSaveDlg( HINSTANCE hInstance, HWND hWnd )
{
	this->m_hOwner		= hWnd;
	this->m_hInstance	= hInstance;
}

COpenSaveDlg::~COpenSaveDlg( void )
{
}

/////////////////////////////////////
// Memberfuncties                  //
/////////////////////////////////////

string COpenSaveDlg::open( const char *title, const char *szFilter, const char *szDefExt )
{
	OPENFILENAME ofn = {0};
	char szFile[MAX_PATH+1] =	{0};
	
	//specificeer de dialog box zo volledig mogelijk
	ofn.Flags             = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	ofn.hwndOwner         = m_hOwner;
	ofn.lpstrCustomFilter = 0;
	ofn.lpstrFile         = szFile;
	ofn.lpstrFileTitle    = 0;
	ofn.lpstrFilter       = szFilter;
	ofn.lpstrDefExt		  = szDefExt;
	ofn.lpstrInitialDir   = 0;
	ofn.lpstrTitle        = title;
	ofn.lStructSize       = sizeof( OPENFILENAME );
	ofn.nMaxFile          = MAX_PATH;


	//open de dialoog
	if( GetOpenFileName( &ofn ) != 0 )
    {
        return string(ofn.lpstrFile);
	}

	//als het openen van de dialoog niet gelukt is, geeft een lege string terug

    return string("");
}

string COpenSaveDlg::save( const char *title, const char *szFilter, const char *szDefExt )
{
	char *result;
	OPENFILENAME ofn = {0};
	char szFile[MAX_PATH+1] =	{0};
	
	//specificeer de dialog box zo volledig mogelijk
	ofn.Flags             = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	ofn.hwndOwner         = m_hOwner;
	ofn.lpstrCustomFilter = 0;
	ofn.lpstrFile         = szFile;
	ofn.lpstrFileTitle    = 0;
	ofn.lpstrFilter       = szFilter;
	ofn.lpstrDefExt		  = szDefExt;
	ofn.lpstrInitialDir   = 0;
	ofn.lpstrTitle        = title;
	ofn.lStructSize       = sizeof( OPENFILENAME );
	ofn.nMaxFile          = MAX_PATH;


	//open de dialoog
	if( GetSaveFileName( &ofn ) != 0 )
    {
        return string(ofn.lpstrFile);
	}

	//als het openen van de dialoog niet gelukt is, geeft een lege string terug

    return string("");
}
