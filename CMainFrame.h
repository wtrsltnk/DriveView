#ifndef CMAINFRAME_H
#define CMAINFRAME_H

#include "CWin.h"
#include "controls\GUI.h"

class CMainFrame : public CWin
{
private:
	CFolderView			*m_pDrives;
	CFileView			*m_pFiles;
public:
	CMainFrame();
	~CMainFrame();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

#endif
