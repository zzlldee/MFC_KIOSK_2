
// MFC_KIOSKDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_KIOSK.h"
#include "MFC_KIOSKDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCKIOSKDlg 대화 상자



CMFCKIOSKDlg::CMFCKIOSKDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_KIOSK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCKIOSKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCKIOSKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_COFFEE, &CMFCKIOSKDlg::OnBnClickedButton2)

END_MESSAGE_MAP()


// CMFCKIOSKDlg 메시지 처리기

BOOL CMFCKIOSKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	LONG style = GetWindowLong(this->m_hWnd, GWL_STYLE);
	style &= ~(WS_MAXIMIZEBOX); // 최대화 버튼 제거
	SetWindowLong(this->m_hWnd, GWL_STYLE, style);



	// 다이얼로그 크기 고정
	SetWindowPos(NULL, 0, 0, 1920, 1080, SWP_NOMOVE | SWP_NOZORDER); // 해상도 1920 1080 고정
	//배경 이미지 로드
	SetBackgroundImage(134); // 배경 이미지 불러오기 

	/**************1920 1080 해상도에 맞춰서 동적으로 버튼 위치이동 로직입니다. *****************************************/

					/**		모든 버튼 하나하나 위치를 지정해주지 않으면 
							리소스 뷰에서 버튼을 건들이면 
					바로 버튼 위치가 바뀌어서 일일이 지정해줌ㅠㅠ.		**/
	
	/*1920 1080 해상도 기준입니다.*/	
	//버튼에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(68, 83, IDC_BUTTON_COFFEE); //커피 버튼
	m_setButtonPositiion(321, 83, 1001); //제조음료 버튼
	m_setButtonPositiion(578, 83, 1002); // 티 버튼 
	m_setButtonPositiion(835, 83, 1003); // 제과류 버튼
	m_setButtonPositiion( 1248, 803 , 1005); // 매장이용 버튼 
	m_setButtonPositiion( 1569, 803, 1006); // 포장 버튼

	//매뉴 이미지 박스에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(68, 170, 1007); //매뉴 이미지 박스1
	m_setButtonPositiion(418, 170, 1008); // 2
	m_setButtonPositiion(768, 170, 1009);
	m_setButtonPositiion(68, 450, 1010);
	m_setButtonPositiion(418, 450, 1011);
	m_setButtonPositiion(768, 450, 1012);
	m_setButtonPositiion(68, 750, 1013);
	m_setButtonPositiion(418, 750, 1014);
	m_setButtonPositiion(768, 750, 1015); //9

	//매뉴 이름 텍스트와 가격 텍스트에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(129, 370, 1016); //매뉴 이름 텍스트 1
	m_setButtonPositiion(479, 370, 1017); // 2
	m_setButtonPositiion(829, 370, 1018);
	
	m_setButtonPositiion(129, 650, 1019);
	m_setButtonPositiion(479, 650, 1020);
	m_setButtonPositiion(829, 650, 1021);

	m_setButtonPositiion(129, 950, 1022);
	m_setButtonPositiion(479, 950, 1023);
	m_setButtonPositiion(829, 950, 1024); // 9

	m_setButtonPositiion(129, 410, 1025); //매뉴 가격 텍스트 1
	m_setButtonPositiion(479, 410, 1034); // 2
	m_setButtonPositiion(829, 410, 1035);

	m_setButtonPositiion(129, 690, 1036);
	m_setButtonPositiion(479, 690, 1037);
	m_setButtonPositiion(829, 690, 1038);

	m_setButtonPositiion(129, 990, 1039);
	m_setButtonPositiion(479, 990, 1040);
	m_setButtonPositiion(829, 990, 1041); // 9

	//위, 아래 버튼에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1155, 410, 1026);
	m_setButtonPositiion(1155, 925 , 1027);

	//주문 텍스트에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1262, 130, 1028);
	m_setButtonPositiion(1262, 190, 1043);
	m_setButtonPositiion(1262, 260, 1044);
	m_setButtonPositiion(1262, 330, 1045);
	m_setButtonPositiion(1262, 400, 1046);
	m_setButtonPositiion(1262, 470, 1047);
	m_setButtonPositiion(1262, 540, 1048);
	m_setButtonPositiion(1262, 610, 1049);
	
	//주문 가격 총합 텍스트에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1662, 130, 1029);
	m_setButtonPositiion(1662, 190, 1030);
	m_setButtonPositiion(1662, 260, 1031);
	m_setButtonPositiion(1662, 330, 1032);
	m_setButtonPositiion(1662, 400, 1033);
	m_setButtonPositiion(1662, 470, 1042);
	m_setButtonPositiion(1662, 540, 1050);
	m_setButtonPositiion(1662, 610, 1051);
	//주문 수량 에디트박스에 대한 동적 이동 로직이빈다. 
	m_setButtonPositiion(1582, 130, 1052);
	m_setButtonPositiion(1582, 190, 1053);
	m_setButtonPositiion(1582, 260, 1054);
	m_setButtonPositiion(1582, 330, 1055);
	m_setButtonPositiion(1582, 400, 1056);
	m_setButtonPositiion(1582, 470, 1057);
	m_setButtonPositiion(1582, 540, 1058);
	m_setButtonPositiion(1582, 610, 1059);
	//모든 주문 전체 가격 총합 텍스트 이동 로직입니다.
	m_setButtonPositiion(1540, 730, 1060);
	//////////////////////////////////////////////////////////////////////////////////////////////////


					/**************
	텍스트 오브젝트별로 글꼴 설정 로직입니다. 
		*****************************************/
		/*******************************
	/*	m_setFont + <object> + _<objectname> ( int 폰트사이즈, int 폰트굵기매크로 ) */
	
	/*FW_어쩌고는 MFC상에서 매크로 정의가 되어있음. FW_THIN FW_BOLD 등 타이핑하면 자동완성 뜰거임*/

	/*	menu : 매뉴 텍스트 */
	/*	price : 가격 텍스트 */
	/*	editbox : 에디트박스 텍스트 */
	/*	order : 주문 목록 텍스트 */
	/*	ordersum : 각 주문별 가격 총합 텍스트 - 모든 주문의 가격 총합이 아니라 각 주문별로 총합임 예) 아메리카노(5000) x 4 = oredersum 20000*/
	m_setFont_menu(31, FW_BOLD); 
	m_setFont_price(31, FW_THIN);
	m_setFont_editbox(31, FW_HEAVY);
	m_setFont_order(31, FW_BOLD);
	m_setFont_ordersum(31, FW_BOLD);
	m_setFont_allsum(55, FW_BOLD);

	/////////////////////////////////////////////////////////





	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCKIOSKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCKIOSKDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
		
		
	
	}
	else
	{
		CDialogEx::OnPaint();

	}


}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCKIOSKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCKIOSKDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}







void CMFCKIOSKDlg::m_setButtonPositiion(int buttonX, int buttonY, int nID)
{
	// TODO: 여기에 구현 코드 추가.
		/**************해상도에 맞춰서 동적으로 버튼 위치이동 로직입니다. *****************************************/
	// 현재 화면 해상도 얻기
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// 버튼 위치 계산 (예: 화면의 가운데에 배치)


	
	// 버튼 위치 설정
	CWnd* pButton = GetDlgItem(nID); // IDC_MYBUTTON은 버튼의 ID
	if (pButton != nullptr)
	{
		pButton->SetWindowPos(NULL, buttonX, buttonY, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	}

	/****************************************************************************************************/
}




void CMFCKIOSKDlg::m_setFont_for_m_font_menu(int nID)
{
	// TODO: 여기에 구현 코드 추가.
	// 글꼴 적용
	CEdit* pEdit = (CEdit*)GetDlgItem(nID); 
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_menu);
		
	}

	
}

void CMFCKIOSKDlg::m_setFont_for_m_font_price(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_price);

	}




}
void CMFCKIOSKDlg::m_setFont_for_m_font_edit(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_editbox);

	}




}
void CMFCKIOSKDlg::m_setFont_for_m_font_order(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_order);

	}




}

void CMFCKIOSKDlg::m_setFont_for_m_font_ordersum(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_ordersum);

	}




}

void CMFCKIOSKDlg::m_setFont_for_m_font_allsum(int nID)
{
	//매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_allsum);

	}




}







void CMFCKIOSKDlg::m_setFont_menu(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.

	m_font_menu.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름
	m_setFont_for_m_font_menu(IDC_TEXT1);
	m_setFont_for_m_font_menu(IDC_TEXT2);
	m_setFont_for_m_font_menu(IDC_TEXT3);
	m_setFont_for_m_font_menu(IDC_TEXT4);
	m_setFont_for_m_font_menu(IDC_TEXT5);
	m_setFont_for_m_font_menu(IDC_TEXT6);
	m_setFont_for_m_font_menu(IDC_TEXT7);
	m_setFont_for_m_font_menu(IDC_TEXT8);
	m_setFont_for_m_font_menu(IDC_TEXT9);
}


void CMFCKIOSKDlg::m_setFont_price(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_price.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름
	m_setFont_for_m_font_price(IDC_PRICE1);
	m_setFont_for_m_font_price(IDC_PRICE2);
	m_setFont_for_m_font_price(IDC_PRICE3);
	m_setFont_for_m_font_price(IDC_PRICE4);
	m_setFont_for_m_font_price(IDC_PRICE5);
	m_setFont_for_m_font_price(IDC_PRICE6);
	m_setFont_for_m_font_price(IDC_PRICE7);
	m_setFont_for_m_font_price(IDC_PRICE8);
	m_setFont_for_m_font_price(IDC_PRICE9);




}


void CMFCKIOSKDlg::m_setFont_order(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_order.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름
	m_setFont_for_m_font_order(IDC_TEXT_ORDER1);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER2);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER3);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER4);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER5);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER6);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER7);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER8);

}

void CMFCKIOSKDlg::m_setFont_editbox(int fontsize, int FW)
{
	m_font_editbox.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름
	m_setFont_for_m_font_edit(IDC_EDIT1);
	m_setFont_for_m_font_edit(IDC_EDIT2);
	m_setFont_for_m_font_edit(IDC_EDIT3);
	m_setFont_for_m_font_edit(IDC_EDIT4);
	m_setFont_for_m_font_edit(IDC_EDIT5);
	m_setFont_for_m_font_edit(IDC_EDIT6);
	m_setFont_for_m_font_edit(IDC_EDIT7);
	m_setFont_for_m_font_edit(IDC_EDIT8);
}


void CMFCKIOSKDlg::m_setFont_ordersum(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_ordersum.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름

	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER1_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER2_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER3_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER4_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER5_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER6_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER7_SUM);
	m_setFont_for_m_font_ordersum(IDC_TEXT_ORDER8_SUM);

}

void CMFCKIOSKDlg::m_setFont_allsum(int fontsize, int FW)
{
	// TODO: 여기에 구현 코드 추가.
	m_font_allsum.CreateFont(
		fontsize,                        // 높이
		0,                         // 폭
		0,                         // 기울기 각도
		0,                         // 기울기 각도
		FW,                 // 글꼴 두께
		FALSE,                     // 이탤릭
		FALSE,                     // 밑줄
		0,                         // 취소선
		ANSI_CHARSET,              // 문자셋
		OUT_DEFAULT_PRECIS,        // 출력 정밀도
		CLIP_DEFAULT_PRECIS,       // 클리핑 정밀도
		DEFAULT_QUALITY,           // 출력 품질
		DEFAULT_PITCH | FF_SWISS,  // 피치 및 패밀리
		_T("Arial"));              // 글꼴 이름

	m_setFont_for_m_font_allsum(1060);


}

