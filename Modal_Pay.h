#pragma once
#ifndef WM_USER_PAYMENT_COMPLETED
#define WM_USER_PAYMENT_COMPLETED (WM_APP + 1)
#endif

#include "afxdialogex.h"
#include "Modal_Loading.h"


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
	afx_msg LRESULT OnPaymentCompleted(WPARAM wParam, LPARAM lParam);
	BOOL Modal_Pay::OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonBack();
	CBitmapButton m_BitmapBtn1;
	CBitmapButton m_BitmapBtn2;
	CBitmapButton m_BitmapBtn3;
	CBitmapButton m_BitmapBtn4;
	afx_msg void OnBnClickedButtonKakao();
	Modal_Loading* m_dlgLoading;
	afx_msg void OnBnClickedButtonNaver();
	afx_msg void OnBnClickedButtonCard();
	afx_msg void OnBnClickedButtonPayco();
};
