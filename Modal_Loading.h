#pragma once
#include "afxdialogex.h"
#include "PictureEx.h"


// Modal_Loading 대화 상자

class Modal_Loading : public CDialogEx
{
	DECLARE_DYNAMIC(Modal_Loading)

public:
	Modal_Loading(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Modal_Loading();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOADING };
#endif
private:
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	BOOL OnInitDialog();
	CPictureEx  m_GifLoading;
	UINT_PTR m_nTimer; // 타이머 ID
	DECLARE_MESSAGE_MAP();

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	HBRUSH Modal_Loading::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

};
