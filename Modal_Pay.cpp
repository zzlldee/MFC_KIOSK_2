	// Modal_Pay.cpp: 구현 파일
	//


	#include "pch.h"
	#include "MFC_KIOSK.h"
	#include "afxdialogex.h"
	#include "Modal_Pay.h"
	#include "Modal_Loading.h"

	IMPLEMENT_DYNAMIC(Modal_Pay, CDialogEx)

	Modal_Pay::Modal_Pay(CWnd* pParent /*=nullptr*/)
		: CDialogEx(IDD_DIALOG_MOFAL_PAY, pParent)
	{

	}

	Modal_Pay::~Modal_Pay()
	{
	}

	void Modal_Pay::DoDataExchange(CDataExchange* pDX)
	{
		CDialogEx::DoDataExchange(pDX);
		DDX_Control(pDX, IDC_BUTTON_KAKAO, m_BitmapBtn1);
		DDX_Control(pDX, IDC_BUTTON_NAVER, m_BitmapBtn2);
		DDX_Control(pDX, IDC_BUTTON_CARD, m_BitmapBtn3);
		DDX_Control(pDX, IDC_BUTTON_PAYCO, m_BitmapBtn4);
	}


	BEGIN_MESSAGE_MAP(Modal_Pay, CDialogEx)
		ON_BN_CLICKED(IDC_BUTTON_BACK, &Modal_Pay::OnBnClickedButtonBack)
		ON_BN_CLICKED(IDC_BUTTON_KAKAO, &Modal_Pay::OnBnClickedButtonKakao)
		ON_BN_CLICKED(IDC_BUTTON_NAVER, &Modal_Pay::OnBnClickedButtonNaver)
		ON_BN_CLICKED(IDC_BUTTON_CARD, &Modal_Pay::OnBnClickedButtonCard)
		ON_BN_CLICKED(IDC_BUTTON_PAYCO, &Modal_Pay::OnBnClickedButtonPayco)
		ON_MESSAGE(WM_USER_PAYMENT_COMPLETED, OnPaymentCompleted)
	END_MESSAGE_MAP()

	BOOL Modal_Pay::OnInitDialog()
	{
		CDialogEx::OnInitDialog();
		CenterWindow();
		m_BitmapBtn1.LoadBitmaps(IDB_BITMAP_KAKAO, IDB_BITMAP_KAKAO, IDB_BITMAP_KAKAO, IDB_BITMAP_KAKAO);
		m_BitmapBtn2.LoadBitmaps(IDB_BITMAP_NAVER, IDB_BITMAP_NAVER, IDB_BITMAP_NAVER, IDB_BITMAP_NAVER);
		m_BitmapBtn3.LoadBitmaps(IDB_BITMAP_CARD, IDB_BITMAP_CARD, IDB_BITMAP_CARD, IDB_BITMAP_CARD);
		m_BitmapBtn4.LoadBitmaps(IDB_BITMAP_PAYCO, IDB_BITMAP_PAYCO, IDB_BITMAP_PAYCO, IDB_BITMAP_PAYCO);
		return TRUE;
	}



	void Modal_Pay::OnBnClickedButtonBack()
	{
		OnCancel();
	}

	void Modal_Pay::OnBnClickedButtonKakao()
	{
		if (m_dlgLoading == nullptr) {
			m_dlgLoading = new Modal_Loading(this);
			if (m_dlgLoading != nullptr) {
				m_dlgLoading->Create(IDD_DIALOG_LOADING, this);
				m_dlgLoading->ShowWindow(SW_SHOW);
			}
		}
		else if (m_dlgLoading != nullptr) {
			m_dlgLoading->ShowWindow(SW_SHOW);
		}

		int result = MessageBoxA("결제 완료되었습니다.", "결제 완료", MB_OK | MB_ICONINFORMATION);
		if (result == IDOK) {
			::PostMessage(GetSafeHwnd(), WM_USER_PAYMENT_COMPLETED, 0, 0);
		}

	}

	void Modal_Pay::OnBnClickedButtonNaver() {
		if (m_dlgLoading == nullptr) {
			m_dlgLoading = new Modal_Loading(this);
			if (m_dlgLoading != nullptr) {
				m_dlgLoading->Create(IDD_DIALOG_LOADING, this);
				m_dlgLoading->ShowWindow(SW_SHOW);
			}
		}
		else if (m_dlgLoading != nullptr) {
			m_dlgLoading->ShowWindow(SW_SHOW);
		}

		int result = MessageBoxA("결제 완료되었습니다.", "결제 완료", MB_OK | MB_ICONINFORMATION);
		if (result == IDOK) {
			::PostMessage(GetSafeHwnd(), WM_USER_PAYMENT_COMPLETED, 0, 0);
		}
	}

	void Modal_Pay::OnBnClickedButtonCard()
	{
		if (m_dlgLoading == nullptr) {
			m_dlgLoading = new Modal_Loading(this);
			if (m_dlgLoading != nullptr) {
				m_dlgLoading->Create(IDD_DIALOG_LOADING, this);
				m_dlgLoading->ShowWindow(SW_SHOW);
			}
		}
		else if (m_dlgLoading != nullptr) {
			m_dlgLoading->ShowWindow(SW_SHOW);
		}

		int result = MessageBoxA("결제 완료되었습니다.", "결제 완료", MB_OK | MB_ICONINFORMATION);
		if (result == IDOK) {
			::PostMessage(GetSafeHwnd(), WM_USER_PAYMENT_COMPLETED, 0, 0);
		}
	}


	void Modal_Pay::OnBnClickedButtonPayco()
	{
		if (m_dlgLoading == nullptr) {
			m_dlgLoading = new Modal_Loading(this);
			if (m_dlgLoading != nullptr) {
				m_dlgLoading->Create(IDD_DIALOG_LOADING, this);
				m_dlgLoading->ShowWindow(SW_SHOW);
			}
		}
		else if (m_dlgLoading != nullptr) {
			m_dlgLoading->ShowWindow(SW_SHOW);
		}

		int result = MessageBoxA("결제 완료되었습니다.", "결제 완료", MB_OK | MB_ICONINFORMATION);
		if (result == IDOK) {
			::PostMessage(GetSafeHwnd(), WM_USER_PAYMENT_COMPLETED, 0, 0);
		}
	}

	LRESULT Modal_Pay::OnPaymentCompleted(WPARAM wParam, LPARAM lParam)
	{
		if (m_dlgLoading != nullptr)
		{
			m_dlgLoading->DestroyWindow();
			delete m_dlgLoading;
			m_dlgLoading = nullptr;
		}

		EndDialog(IDOK);

		return 0;
	}
