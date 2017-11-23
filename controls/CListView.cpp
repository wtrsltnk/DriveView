#include "CListView.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CListView::CListView( HINSTANCE hInstance, 
					 HWND hParent,
					 int nX, int nY , 
					 int nWidth ,int nHeight, int id ) : CControl( hInstance, 
					 hParent,
					 nX, nY , 
					 nWidth ,nHeight, id )
{
}

CListView::CListView( HINSTANCE hInstance, HWND hParent ) : CControl( hInstance, hParent )
{
}

/////////////////////////////////////
// Memberfuncties                  //
/////////////////////////////////////

void CListView::create( void )
{
	m_hWnd = CreateWindowEx( WS_EX_WINDOWEDGE,
		 WC_LISTVIEW,
		 "Caption", 
		 WS_CHILD | WS_VISIBLE, 
		 m_nX, 
		 m_nY, 
		 m_nWidth, 
		 m_nHeight, 
		 m_hParent, 
		 (HMENU)control_id, 
		 NULL, 
		 NULL );
}

void CListView::create( DWORD ex_style )
{
	m_hWnd = CreateWindowEx( ex_style,
		 WC_LISTVIEW, 
		 "Caption", 
		 WS_CHILD | WS_VISIBLE,
		 m_nX, 
		 m_nY, 
		 m_nWidth, 
		 m_nHeight, 
		 m_hParent, 
		 (HMENU)control_id, 
		 NULL, 
		 NULL );
}

void CListView::create( DWORD ex_style, DWORD styles )
{
	m_hWnd = CreateWindowEx( ex_style,
		 WC_LISTVIEW, 
		 "Caption", 
		 WS_CHILD | WS_VISIBLE |
		 styles,
		 m_nX, 
		 m_nY, 
		 m_nWidth, 
		 m_nHeight, 
		 m_hParent, 
		 (HMENU)control_id, 
		 NULL, 
		 NULL );
}


void CListView::setImageList( UINT wBMID, int cx, int cy, int iNoImg )
{
	HIMAGELIST himl = ImageList_Create( cx, cy, ILC_COLORDDB, iNoImg, 0 );
	ImageList_Add( himl, LoadBitmap( m_hInstance, MAKEINTRESOURCE( wBMID ) ), NULL );
	SendMessage( m_hWnd, TVM_SETIMAGELIST, TVSIL_NORMAL , ( LPARAM ) ( HIMAGELIST ) himl );
}

void CListView::setExStyle( DWORD style )
{
	ListView_SetExtendedListViewStyleEx( m_hWnd, NULL, style );
}


void CListView::reset( void )
{
	int i = 0;
	int result;

	result = 1;
	ListView_DeleteAllItems( m_hWnd );

	while ( result )
	{
		result = ListView_DeleteColumn( m_hWnd, 0 );
		i++;
	}
}


void CListView::addColumn( string str, int iColNo, int width )
{

	LV_COLUMN lvc;

	lvc.mask = LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
	lvc.fmt = LVCFMT_LEFT ;
	lvc.cchTextMax = 300;
	lvc.cx = width;
	lvc.pszText = const_cast <char *> ( str.c_str() );
	lvc.iSubItem = iColNo;

	ListView_InsertColumn( m_hWnd, iColNo, &lvc );
}


void CListView::setColumnWidth( int iColNo, int nWidth )
{
	SendMessage( m_hWnd, 
		LVM_SETCOLUMNWIDTH, 
		( WPARAM ) iColNo, 
		( LPARAM ) MAKELPARAM ( nWidth, 0 ) );
}


int CListView::getColumnWidth( int iColNo )
{
	return SendMessage( m_hWnd, 
		LVM_GETCOLUMNWIDTH, 
		( WPARAM ) iColNo, 
		0 );
}


void CListView::addItem( string str, int iRowNo, int iImage )
{
	LV_ITEM lvi;

	lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	lvi.state = 0;
	lvi.stateMask = -1;
	lvi.iItem = ( iRowNo );
	lvi.iSubItem = 0;
	lvi.pszText = const_cast <char *> ( str.c_str() );
	lvi.iImage = iImage;

	ListView_InsertItem( m_hWnd, &lvi );
}


void CListView::addSubItem( string s, int iRowNo, int iSubItem )
{
	ListView_SetItemText( m_hWnd, iRowNo, iSubItem, const_cast <char *> ( s.c_str() ) );
}



int CListView::getSelectedIndex( void )
{
	return ListView_GetSelectionMark( m_hWnd );
}

string CListView::getItemText( int row )
{
	char text[255];
	ListView_GetItemText( m_hWnd, row, 0, text, 255 );
	return text;
}

string CListView::getSubItemText( int row, int sub )
{
	char text[255];
	ListView_GetItemText( m_hWnd, row, sub, text, 255 );
	return text;
	return "";
}