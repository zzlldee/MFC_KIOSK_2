#pragma once
#include "afxdialogex.h"


// Modal_Pay 대화 상자

class Modal_Pay : public CDialogEx
{
	DECLARE_DYNAMIC(Modal_Pay)

public:
	Modal_Pay(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Modal_Pay();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MOFAL_PAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	BOOL Modal_Pay::OnInitDialog();

public:
	afx_msg void OnBnClickedButtonBack();
	CBitmapButton m_BitmapBtn1;
	CBitmapButton m_BitmapBtn2;
	CBitmapButton m_BitmapBtn3;
	CBitmapButton m_BitmapBtn4;
};
