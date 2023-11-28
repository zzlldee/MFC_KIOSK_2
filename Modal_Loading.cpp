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
    : CDialogEx(IDD_DIALOG_LOADING, pParent), m_nTimer(0)
{
}

Modal_Loading::~Modal_Loading()
{
}

void Modal_Loading::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}
// Modal_Loading.cpp 파일의 OnInitDialog 함수 내에 해당 코드를 추가합니다.

BOOL Modal_Loading::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    CenterWindow();

    // IDC_STATIC_PAYING 컨트롤에 "결제중입니다"라는 텍스트를 출력합니다.
    CWnd* pWnd = GetDlgItem(IDC_STATIC_PAYING);
    if (pWnd != nullptr) {
        pWnd->SetWindowText(_T("결제중입니다"));
    }

    m_nTimer = SetTimer(1, 3000, nullptr); // 3초 후 onTimer함수 실행

    return TRUE;
}


BEGIN_MESSAGE_MAP(Modal_Loading, CDialogEx)
    ON_WM_TIMER()
END_MESSAGE_MAP()


void Modal_Loading::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    KillTimer(m_nTimer); // 타이머 종료
    DestroyWindow();
    //MessageBoxA("결제 완료되었습니다.", "결제 완료", MB_OK | MB_ICONINFORMATION);
    CDialogEx::OnTimer(nIDEvent);
}