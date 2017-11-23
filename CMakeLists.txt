cmake_minimum_required(VERSION 3.1)

project(DriveView)

add_executable(DriveView
    controls/CButton.cpp
    controls/CCheck.cpp
    controls/CCombo.cpp
    controls/CControl.cpp
    controls/CEdit.cpp
    controls/CFileView.cpp
    controls/CFolderView.cpp
    controls/CFrame.cpp
    controls/CLabel.cpp
    controls/CList.cpp
    controls/CListView.cpp
    controls/COpenSaveDlg.cpp
    controls/CReportView.cpp
    controls/CSlider.cpp
    controls/CStatusBar.cpp
    controls/CToolBar.cpp
    controls/CTreeView.cpp
    resource/resource.rc
    CMainFrame.cpp
    CWin.cpp
    WinMain.cpp
    )

target_compile_features(DriveView
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_link_libraries(DriveView
    comctl32
    )
