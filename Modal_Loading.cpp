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

BOOL Modal_Loading::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    CenterWindow();
    //if (m_GifLoading.Load("IDR_GIF1")) //파일에서 로드
    //    m_GifLoading.Draw();
    TRACE("Timer event triggered\n");

    m_nTimer = SetTimer(1, 3000, nullptr); // 올바른 타이머 ID를 저장
    TRACE("Timer event triggered\n");

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
