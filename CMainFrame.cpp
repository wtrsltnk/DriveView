#include "CMainFrame.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CMainFrame::CMainFrame()
{
	this->m_dwCreationFlags  = 0L;
	this->m_dwWindowStyle	 = WS_OVERLAPPEDWINDOW;
	this->m_dwExWindowStyle	 = WS_EX_WINDOWEDGE;
	this->m_dwCreationFlags  = SW_SHOW;
	this->m_PosX			 = CW_USEDEFAULT;	
	this->m_PosY			 = CW_USEDEFAULT;	
	this->m_dwCreationWidth  = CW_USEDEFAULT;
	this->m_dwCreationHeight = CW_USEDEFAULT;
	this->m_hbrWindowColor	 = (HBRUSH)(COLOR_WINDOW);
	this->m_hIcon			 = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_ICON));
	this->m_strWindowTitle	 = "Drive view test";
	this->m_hMenu			 = LoadMenu( m_hInstance, MAKEINTRESOURCE(IDR_MENU)); 	
}


CMainFrame::~CMainFrame()
{
}

/////////////////////////////////////
// Memberfuncties                  //
/////////////////////////////////////

LRESULT CMainFrame::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nWidth, nHeight;
	string result;

	string FileName;
	HTREEITEM hItem;

	switch ( uMsg )
	{
	case WM_CREATE:
		m_pFiles = new CFileView( m_hInstance, m_hWnd, 0, 0, 100, 100, ID_FILES );
		m_pFiles->create( WS_EX_CLIENTEDGE, LVS_ICON | LVS_SHOWSELALWAYS );

		CheckMenuRadioItem( this->m_hMenu, IDM_VIEW_ICON, IDM_VIEW_LIST, IDM_VIEW_ICON, 0);
			
		m_pDrives = new CFolderView( m_hInstance, m_hWnd, 0, 0, 100, 100, ID_DRIVES );
		m_pDrives->create( WS_EX_CLIENTEDGE, TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_FULLROWSELECT | TVS_SHOWSELALWAYS );
		break;

	case WM_SIZE:
		nWidth = LOWORD(lParam);
		nHeight = HIWORD(lParam);
		m_pDrives->resize( 0, 0, nWidth/3, nHeight );
		m_pFiles->resize( nWidth/3, 0, (nWidth/3)*2, nHeight );
		break;

	case WM_NOTIFY:
		switch ( wParam )
		{
		case ID_DRIVES:
			switch ( ((LPNMHDR) lParam)->code )
			{
			case TVN_SELCHANGING:
				result = m_pDrives->initPath( wParam, lParam );
				m_pFiles->initFiles( result );
				break;
			}
			break;
		case ID_FILES:
			switch ( ((LPNMHDR) lParam)->code )
			{
			case LVN_ITEMACTIVATE:
				FileName = m_pFiles->getFilePath();
				if ( FileName != "" )
				{
					ShellExecute( NULL, "open", FileName.c_str(), NULL, NULL, SW_SHOWDEFAULT );
				}
				break;
			}
			break;
		}
		break;
	case WM_COMMAND:
		switch ( LOWORD(wParam) )
		{
		case ID_BESTAND_OPEN:
			break;
		case IDM_VIEW_ICON:
		case IDM_VIEW_SMALLICON:
		case IDM_VIEW_LIST:
		case IDM_VIEW_REPORT:
			m_pFiles->setStyle( LOWORD(wParam)-IDM_VIEW_ICON );
			CheckMenuRadioItem( this->m_hMenu, IDM_VIEW_ICON, IDM_VIEW_LIST, LOWORD(wParam), 0);
			break;
		}
		break;
	}
	return CWin::MsgProc(hWnd, uMsg, wParam, lParam);
}
