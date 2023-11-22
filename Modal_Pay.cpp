// Modal_Pay.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_KIOSK.h"
#include "afxdialogex.h"
#include "Modal_Pay.h"


// Modal_Pay 대화 상자

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