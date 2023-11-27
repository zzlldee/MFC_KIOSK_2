// Modal_Loading.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_KIOSK.h"
#include "afxdialogex.h"
#include "Modal_Loading.h"
#include "PictureEx.h"


// Modal_Loading 대화 상자

IMPLEMENT_DYNAMIC(Modal_Loading, CDialogEx)

Modal_Loading::Modal_Loading(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_LOADING, pParent), m_nTimer(0) // 초기화 리스트에서 m_nTimer 초기화
{
}

Modal_Loading::~Modal_Loading()
{
}

void Modal_Loading::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BOOL Modal_Loading::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    CenterWindow();
    if (m_GifLoading.Load("IDR_GIF1")) //파일에서 로드
        m_GifLoading.Draw();



    m_nTimer = SetTimer(1, 3000, nullptr); // 3000ms = 3초 후에 타이머 이벤트 발생
    return TRUE;
}

void Modal_Loading::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == 1) {
        KillTimer(m_nTimer); // 타이머 종료
        EndDialog(IDOK); // 다이얼로그 종료
    }
    CDialogEx::OnTimer(nIDEvent);
}

BEGIN_MESSAGE_MAP(Modal_Loading, CDialogEx)
END_MESSAGE_MAP()
