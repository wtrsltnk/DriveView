#ifndef CLISTVIEW_H
#define CLISTVIEW_H

#include <windows.h>
#include <commctrl.h>
#include <string>
#include "CControl.h"
using namespace std;

class CListView : public CControl
{
private:
public:
	CListView( HINSTANCE, HWND, int, int, int, int, int );
	CListView( HINSTANCE, HWND );

	void create( void );
	void create( DWORD );
	void create( DWORD, DWORD );
	void reset( void );
	void setExStyle( DWORD );

	void setImageList( UINT, int, int, int );

	void addColumn( string, int, int );
	void setColumnWidth( int, int );
	int getColumnWidth( int );

	void addItem( string, int, int );
	void addSubItem( string, int, int );

	int getSelectedIndex( void );
	string getItemText( int );
	string getSubItemText( int, int );
};
#endif
