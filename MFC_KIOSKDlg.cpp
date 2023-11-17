
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
	DDX_Control(pDX, IDC_TEXT1, m_Text1);
	DDX_Control(pDX, IDC_TEXT2, m_Text2);
	DDX_Control(pDX, IDC_TEXT3, m_Text3);
	DDX_Control(pDX, IDC_TEXT4, m_Text4);
	DDX_Control(pDX, IDC_TEXT5, m_Text5);
	DDX_Control(pDX, IDC_TEXT6, m_Text6);
	DDX_Control(pDX, IDC_TEXT7, m_Text7);
	DDX_Control(pDX, IDC_TEXT8, m_Text8);
	DDX_Control(pDX, IDC_TEXT9, m_Text9);
	DDX_Control(pDX, IDC_PRICE1, m_Price1);
	DDX_Control(pDX, IDC_PRICE2, m_Price2);
	DDX_Control(pDX, IDC_PRICE3, m_Price3);
	DDX_Control(pDX, IDC_PRICE4, m_Price4);
	DDX_Control(pDX, IDC_PRICE5, m_Price5);
	DDX_Control(pDX, IDC_PRICE6, m_Price6);
	DDX_Control(pDX, IDC_PRICE7, m_Price7);
	DDX_Control(pDX, IDC_PRICE8, m_Price8);
	DDX_Control(pDX, IDC_PRICE9, m_Price9);
	DDX_Control(pDX, IDC_PICTUREBOX1, m_pictureControl1);
	DDX_Control(pDX, IDC_PICTUREBOX2, m_pictureControl2);
	DDX_Control(pDX, IDC_PICTUREBOX3, m_pictureControl3);
	DDX_Control(pDX, IDC_PICTUREBOX4, m_pictureControl4);
	DDX_Control(pDX, IDC_PICTUREBOX5, m_pictureControl5);
	DDX_Control(pDX, IDC_PICTUREBOX6, m_pictureControl6);
	DDX_Control(pDX, IDC_PICTUREBOX7, m_pictureControl7);
	DDX_Control(pDX, IDC_PICTUREBOX8, m_pictureControl8);
	DDX_Control(pDX, IDC_PICTUREBOX9, m_pictureControl9);
	//  DDX_Control(pDX, IDC_BUTTON_UP, m_buttonUp);
	//  DDX_Control(pDX, IDC_BUTTON_DOWN, m_buttonDown);
}

BEGIN_MESSAGE_MAP(CMFCKIOSKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

ON_BN_CLICKED(IDC_BUTTON_COFFEE, &CMFCKIOSKDlg::OnClickedButtonCoffee)
ON_BN_CLICKED(IDC_BUTTON_CRAFT, &CMFCKIOSKDlg::OnClickedButtonCraft)
ON_BN_CLICKED(IDC_BUTTON_TEA, &CMFCKIOSKDlg::OnClickedButtonTea)
ON_BN_CLICKED(IDC_BUTTON_BREAD, &CMFCKIOSKDlg::OnClickedButtonBread)
ON_BN_CLICKED(IDC_BUTTON_UP, &CMFCKIOSKDlg::OnClickedButtonUp)
ON_BN_CLICKED(IDC_BUTTON_DOWN, &CMFCKIOSKDlg::OnClickedButtonDown)
ON_BN_CLICKED(IDC_BUTTON_KOREAN, &CMFCKIOSKDlg::OnClickedButtonKorean)
ON_BN_CLICKED(IDC_BUTTON_ENGLISH, &CMFCKIOSKDlg::OnClickedButtonEnglish)
ON_BN_CLICKED(IDC_BUTTON_CHINESE, &CMFCKIOSKDlg::OnClickedButtonChinese)
//ON_STN_CLICKED(IDC_TEXT1, &CMFCKIOSKDlg::OnStnClickedText1)
ON_WM_CTLCOLOR()
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
	//주문 수량 에디트박스에 대한 동적 이동 로직입니다. 
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
	//언어에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1570, 20, IDC_BUTTON_KOREAN);
	m_setButtonPositiion(1690, 20, IDC_BUTTON_ENGLISH);
	m_setButtonPositiion(1800, 20, IDC_BUTTON_CHINESE);
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
	m_buttonCoffee = m_buttonBread = m_buttonTea = m_buttonCraft = m_buttonCoffeeDown = m_buttonBreadDown = false;
	m_korean = m_english = m_chinese = false;

	OnClickedButtonKorean();   //초기화면 한국어
	OnClickedButtonCoffee();     //초기화면 커피메뉴

	//언어 버튼 투명화
	SetWindowTheme(GetDlgItem(IDC_BUTTON_KOREAN)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_BUTTON_ENGLISH)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_BUTTON_CHINESE)->GetSafeHwnd(), _T(""), _T(""));
	//위, 아래 버튼 투명화
	SetWindowTheme(GetDlgItem(IDC_BUTTON_UP)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_BUTTON_DOWN)->GetSafeHwnd(), _T(""), _T(""));
	//메뉴 버튼 투명화
	SetWindowTheme(GetDlgItem(IDC_BUTTON_COFFEE)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_BUTTON_CRAFT)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_BUTTON_TEA)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_BUTTON_BREAD)->GetSafeHwnd(), _T(""), _T(""));
	//매장, 포장 버튼 투명화
	SetWindowTheme(GetDlgItem(IDC_BUTTON_HERE)->GetSafeHwnd(), _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_BUTTON_TOGO)->GetSafeHwnd(), _T(""), _T(""));
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



void CMFCKIOSKDlg::OnClickedButtonCoffee()
{
	//coffee 메뉴를 클릭했을 때 메뉴판
	m_buttonCoffee = true;
	ClickedCoffeeUp();
	m_buttonBread = m_buttonTea = m_buttonCraft = false;
}


void CMFCKIOSKDlg::OnClickedButtonCraft()
{
	//craft 메뉴를 클릭했을 때 메뉴판
	m_buttonCraft = true;
	ClickedCraft();
	m_buttonCoffee = m_buttonTea = m_buttonBread = false;
}


void CMFCKIOSKDlg::OnClickedButtonTea()
{
	//tea 메뉴를 클릭했을 때 메뉴판
	m_buttonTea = true;
	ClickedTea();
	m_buttonCoffee = m_buttonBread = m_buttonCraft = false;
}


void CMFCKIOSKDlg::OnClickedButtonBread()
{
	//bread 메뉴를 클릭했을 때 메뉴판
	m_buttonBread = true;
	ClickedBreadUp();
	m_buttonCoffee = m_buttonTea = m_buttonCraft = false;
}


void CMFCKIOSKDlg::OnClickedButtonUp()
{
	if (m_buttonCoffee)
	{
		//위 버튼 눌렀을 때(coffee)
		ClickedCoffeeUp();
		m_buttonCoffeeDown = false;
	}

	else if (m_buttonBread)
	{
		//위 버튼 눌렀을 때(bread)
		ClickedBreadUp();
		m_buttonBreadDown = false;
	}
}


void CMFCKIOSKDlg::OnClickedButtonDown()
{
	if (m_buttonCoffee)
	{
		//아래 버튼 눌렀을 때(coffee)
		ClickedCoffeeDown();
		m_buttonCoffeeDown = true;
	}

	else if (m_buttonBread)
	{
		//아래 버튼 눌렀을 때(bread)
		ClickedBreadDown();
		m_buttonBreadDown = true;
	}
}


void CMFCKIOSKDlg::ClickedCoffeeUp()
{
	// 커피 메뉴를 클릭했을 때
	//한글, 영어, 중국어 일때 
	//UP일때
	ClearTextFields();
	m_buttonCoffee = true;
	if (m_korean) {
		m_Text1.SetWindowTextW(_T("아메리카노(ice)"));
		m_Text2.SetWindowTextW(_T("아메리카노(hot)"));
		m_Text3.SetWindowTextW(_T("카페라떼(ice)"));
		m_Text4.SetWindowTextW(_T("카페라떼(hot)"));
		m_Text5.SetWindowTextW(_T("카라멜마끼아또(ice)"));
		m_Text6.SetWindowTextW(_T("카라멜마끼아또(hot)"));
		m_Text7.SetWindowTextW(_T("콜드브루"));
		m_Text8.SetWindowTextW(_T("바닐라라떼(ice)"));
		m_Text9.SetWindowTextW(_T("바닐라라떼(hot)"));

		m_Price1.SetWindowTextW(_T("1,500원"));
		m_Price2.SetWindowTextW(_T("2,000원"));
		m_Price3.SetWindowTextW(_T("2,900원"));
		m_Price4.SetWindowTextW(_T("2,900원"));
		m_Price5.SetWindowTextW(_T("3,700원"));
		m_Price6.SetWindowTextW(_T("3,700원"));
		m_Price7.SetWindowTextW(_T("3,500원"));
		m_Price8.SetWindowTextW(_T("3,400원"));
		m_Price9.SetWindowTextW(_T("3,400원"));

	}
	else if (m_english) {
		m_Text1.SetWindowTextW(_T("Americano(ice)"));
		m_Text2.SetWindowTextW(_T("Americano(hot)"));
		m_Text3.SetWindowTextW(_T("Latte(ice)"));
		m_Text4.SetWindowTextW(_T("Latte(hot)"));
		m_Text5.SetWindowTextW(_T("Caramel macchiato(ice)"));
		m_Text6.SetWindowTextW(_T("Caramel macchiato(hot)"));
		m_Text7.SetWindowTextW(_T("Cold brew"));
		m_Text8.SetWindowTextW(_T("Vanilla latte(ice)"));
		m_Text9.SetWindowTextW(_T("Vanilla latte(hot)"));

		m_Price1.SetWindowTextW(_T("1,500₩"));
		m_Price2.SetWindowTextW(_T("2,000₩"));
		m_Price3.SetWindowTextW(_T("2,900₩"));
		m_Price4.SetWindowTextW(_T("2,900₩"));
		m_Price5.SetWindowTextW(_T("3,700₩"));
		m_Price6.SetWindowTextW(_T("3,700₩"));
		m_Price7.SetWindowTextW(_T("3,500₩"));
		m_Price8.SetWindowTextW(_T("3,400₩"));
		m_Price9.SetWindowTextW(_T("3,400₩"));
	}
	else if (m_chinese) {
		m_Text1.SetWindowTextW(_T("美式咖啡(冰)"));
		m_Text2.SetWindowTextW(_T("美式咖啡(热)"));
		m_Text3.SetWindowTextW(_T("拿铁咖啡(冰)"));
		m_Text4.SetWindowTextW(_T("拿铁咖啡(热)"));
		m_Text5.SetWindowTextW(_T("焦糖玛奇朵（冰）"));
		m_Text6.SetWindowTextW(_T("焦糖玛奇朵（热）"));
		m_Text7.SetWindowTextW(_T("冷萃咖啡"));
		m_Text8.SetWindowTextW(_T("香草拿铁(冰)"));
		m_Text9.SetWindowTextW(_T("香草拿铁(热)"));

		m_Price1.SetWindowTextW(_T("1,500₩"));
		m_Price2.SetWindowTextW(_T("2,000₩"));
		m_Price3.SetWindowTextW(_T("2,900₩"));
		m_Price4.SetWindowTextW(_T("2,900₩"));
		m_Price5.SetWindowTextW(_T("3,700₩"));
		m_Price6.SetWindowTextW(_T("3,700₩"));
		m_Price7.SetWindowTextW(_T("3,500₩"));
		m_Price8.SetWindowTextW(_T("3,400₩"));
		m_Price9.SetWindowTextW(_T("3,400₩"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C1));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C2));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C3));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C4));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C5));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C6));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C7));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C8));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C9));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonBread = m_buttonTea = m_buttonCraft = false;
}


void CMFCKIOSKDlg::ClickedCoffeeDown()
{
	// 커피메뉴를 클릭 했을 때
	//한글, 영어, 중국어 일때 
	//down일때
	ClearTextFields();
	m_buttonCoffee = true;
	if (m_korean) {
		m_Text1.SetWindowTextW(_T("에스프레소"));
		m_Text2.SetWindowTextW(_T("카페모카"));

		m_Price1.SetWindowTextW(_T("1,500원"));
		m_Price2.SetWindowTextW(_T("3,700원"));
	}
	else if (m_english) {
		m_Text1.SetWindowTextW(_T("Espresso"));
		m_Text2.SetWindowTextW(_T("Cafe Mocha"));

		m_Price1.SetWindowTextW(_T("1,500₩"));
		m_Price2.SetWindowTextW(_T("3,700₩"));
	}
	else if (m_chinese) {
		m_Text1.SetWindowTextW(_T("浓缩咖啡"));
		m_Text2.SetWindowTextW(_T("摩卡咖啡厅"));

		m_Price1.SetWindowTextW(_T("1,500₩"));
		m_Price2.SetWindowTextW(_T("3,700₩"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C10));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_C11));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonBread = m_buttonTea = m_buttonCraft = false;
}


void CMFCKIOSKDlg::ClickedCraft()
{
	// 크레프트 메뉴를 클릭했을 때
	//한글, 영어, 중국어 일때
	ClearTextFields();
	m_buttonCraft = true;
	if (m_korean) {
		m_Text1.SetWindowTextW(_T("녹차프라페"));
		m_Text2.SetWindowTextW(_T("쿠키프라페"));
		m_Text3.SetWindowTextW(_T("민트프라페"));
		m_Text4.SetWindowTextW(_T("요거트스무디"));
		m_Text5.SetWindowTextW(_T("유니콘프라페"));

		m_Price1.SetWindowTextW(_T("3,900원"));
		m_Price2.SetWindowTextW(_T("3,900원"));
		m_Price3.SetWindowTextW(_T("3,900원"));
		m_Price4.SetWindowTextW(_T("3,900원"));
		m_Price5.SetWindowTextW(_T("4,800원"));

	}
	else if (m_english) {
		m_Text1.SetWindowTextW(_T("Green tea Frappe"));
		m_Text2.SetWindowTextW(_T("Cookie Frappe"));
		m_Text3.SetWindowTextW(_T("Mint Frappe"));
		m_Text4.SetWindowTextW(_T("Yoghurt Smoothie"));
		m_Text5.SetWindowTextW(_T("Unicorn Frappe"));

		m_Price1.SetWindowTextW(_T("3,900₩"));
		m_Price2.SetWindowTextW(_T("3,900₩"));
		m_Price3.SetWindowTextW(_T("3,900₩"));
		m_Price4.SetWindowTextW(_T("3,900₩"));
		m_Price5.SetWindowTextW(_T("4,800₩"));
	}
	else if (m_chinese) {
		m_Text1.SetWindowTextW(_T("绿茶冰沙"));
		m_Text2.SetWindowTextW(_T("饼干冰沙"));
		m_Text3.SetWindowTextW(_T("薄荷冰沙"));
		m_Text4.SetWindowTextW(_T("酸奶冰沙"));
		m_Text5.SetWindowTextW(_T("独角兽冰沙"));

		m_Price1.SetWindowTextW(_T("3,900₩"));
		m_Price2.SetWindowTextW(_T("3,900₩"));
		m_Price3.SetWindowTextW(_T("3,900₩"));
		m_Price4.SetWindowTextW(_T("3,900₩"));
		m_Price5.SetWindowTextW(_T("4,800₩"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR1));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR2));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR3));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR4));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_CR5));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCoffee = m_buttonTea = m_buttonBread = false;
}


void CMFCKIOSKDlg::ClickedTea()
{
	// 티 메뉴를 클릭했을 때
	//한글, 영어, 중국어 일때
	ClearTextFields();
	m_buttonTea = true;
	if (m_korean) {
		m_Text1.SetWindowTextW(_T("유자차"));
		m_Text2.SetWindowTextW(_T("페퍼민트"));
		m_Text3.SetWindowTextW(_T("캐모마일"));
		m_Text4.SetWindowTextW(_T("얼그레이"));
		m_Text5.SetWindowTextW(_T("녹차"));
		m_Text6.SetWindowTextW(_T("사과유자차"));

		m_Price1.SetWindowTextW(_T("3,000원"));
		m_Price2.SetWindowTextW(_T("2,500원"));
		m_Price3.SetWindowTextW(_T("2,500원"));
		m_Price4.SetWindowTextW(_T("2,500원"));
		m_Price5.SetWindowTextW(_T("2,500원"));
		m_Price6.SetWindowTextW(_T("3,500원"));
	}
	else if (m_english) {
		m_Text1.SetWindowTextW(_T("Citron Tea"));
		m_Text2.SetWindowTextW(_T("Peppermint"));
		m_Text3.SetWindowTextW(_T("Chamomile"));
		m_Text4.SetWindowTextW(_T("Earl Grey"));
		m_Text5.SetWindowTextW(_T("Green Tea"));
		m_Text6.SetWindowTextW(_T("Apple citron Tea"));

		m_Price1.SetWindowTextW(_T("3,000₩"));
		m_Price2.SetWindowTextW(_T("2,500₩"));
		m_Price3.SetWindowTextW(_T("2,500₩"));
		m_Price4.SetWindowTextW(_T("2,500₩"));
		m_Price5.SetWindowTextW(_T("2,500₩"));
		m_Price6.SetWindowTextW(_T("3,500₩"));
	}
	else if (m_chinese) {
		m_Text1.SetWindowTextW(_T("柚子茶"));
		m_Text2.SetWindowTextW(_T("薄荷洋甘菊茶"));
		m_Text3.SetWindowTextW(_T("洋甘菊茶"));
		m_Text4.SetWindowTextW(_T("伯爵茶"));
		m_Text5.SetWindowTextW(_T("绿茶"));
		m_Text6.SetWindowTextW(_T("苹果柚子茶"));

		m_Price1.SetWindowTextW(_T("3,000₩"));
		m_Price2.SetWindowTextW(_T("2,500₩"));
		m_Price3.SetWindowTextW(_T("2,500₩"));
		m_Price4.SetWindowTextW(_T("2,500₩"));
		m_Price5.SetWindowTextW(_T("2,500₩"));
		m_Price6.SetWindowTextW(_T("3,500₩"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T1));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T2));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T3));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T4));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T5));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_T6));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCoffee = m_buttonBread = m_buttonCraft = false;
}


void CMFCKIOSKDlg::ClickedBreadUp()
{
	// 브레드를 클릭했을 때
	//한글, 영어, 중국어 일때 
	//UP일때
	ClearTextFields();
	m_buttonBread = true;
	if (m_korean) {
		m_Text1.SetWindowTextW(_T("아이스크림 크로플"));
		m_Text2.SetWindowTextW(_T("크루아상"));
		m_Text3.SetWindowTextW(_T("마들렌"));
		m_Text4.SetWindowTextW(_T("스콘"));
		m_Text5.SetWindowTextW(_T("마카롱"));
		m_Text6.SetWindowTextW(_T("샌드위치"));
		m_Text7.SetWindowTextW(_T("아이스크림 슈"));
		m_Text8.SetWindowTextW(_T("롤케익"));
		m_Text9.SetWindowTextW(_T("초코칩쿠키"));

		m_Price1.SetWindowTextW(_T("6,500원"));
		m_Price2.SetWindowTextW(_T("2,800원"));
		m_Price3.SetWindowTextW(_T("3,000원"));
		m_Price4.SetWindowTextW(_T("3,000원"));
		m_Price5.SetWindowTextW(_T("2,700원"));
		m_Price6.SetWindowTextW(_T("3,000원"));
		m_Price7.SetWindowTextW(_T("4,800원"));
		m_Price8.SetWindowTextW(_T("8,000원"));
		m_Price9.SetWindowTextW(_T("3,600원"));
	}
	else if (m_english) {
		m_Text1.SetWindowTextW(_T("Ice cream Croffles"));
		m_Text2.SetWindowTextW(_T("Croissants"));
		m_Text3.SetWindowTextW(_T("Madeleine"));
		m_Text4.SetWindowTextW(_T("Scone"));
		m_Text5.SetWindowTextW(_T("Macaron"));
		m_Text6.SetWindowTextW(_T("Sandwich"));
		m_Text7.SetWindowTextW(_T("Ice cream Puff"));
		m_Text8.SetWindowTextW(_T("Roll cake"));
		m_Text9.SetWindowTextW(_T("Chocolate chip Cookies"));

		m_Price1.SetWindowTextW(_T("6,500₩"));
		m_Price2.SetWindowTextW(_T("2,800₩"));
		m_Price3.SetWindowTextW(_T("3,000₩"));
		m_Price4.SetWindowTextW(_T("3,000₩"));
		m_Price5.SetWindowTextW(_T("2,700₩"));
		m_Price6.SetWindowTextW(_T("3,000₩"));
		m_Price7.SetWindowTextW(_T("4,800₩"));
		m_Price8.SetWindowTextW(_T("8,000₩"));
		m_Price9.SetWindowTextW(_T("3,600₩"));
	}
	else if (m_chinese) {
		m_Text1.SetWindowTextW(_T("冰淇淋Croffle"));
		m_Text2.SetWindowTextW(_T("牛角面包"));
		m_Text3.SetWindowTextW(_T("玛德琳"));
		m_Text4.SetWindowTextW(_T("烤饼"));
		m_Text5.SetWindowTextW(_T("马卡龙"));
		m_Text6.SetWindowTextW(_T("三明治"));
		m_Text7.SetWindowTextW(_T("冰淇淋泡芙"));
		m_Text8.SetWindowTextW(_T("蛋糕卷"));
		m_Text9.SetWindowTextW(_T("巧克力饼干"));

		m_Price1.SetWindowTextW(_T("6,500₩"));
		m_Price2.SetWindowTextW(_T("2,800₩"));
		m_Price3.SetWindowTextW(_T("3,000₩"));
		m_Price4.SetWindowTextW(_T("3,000₩"));
		m_Price5.SetWindowTextW(_T("2,700₩"));
		m_Price6.SetWindowTextW(_T("3,000₩"));
		m_Price7.SetWindowTextW(_T("4,800₩"));
		m_Price8.SetWindowTextW(_T("8,000₩"));
		m_Price9.SetWindowTextW(_T("3,600₩"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B1));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B2));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B3));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B4));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B5));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B6));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B7));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B8));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B9));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCoffee = m_buttonTea = m_buttonCraft = false;
}


void CMFCKIOSKDlg::ClickedBreadDown()
{
	// 브레드 메뉴를 클릭했을 때
	//한글, 영어, 중국어 일때 
	//down일때
	ClearTextFields();
	m_buttonBread = true;
	if (m_korean) {
		m_Text1.SetWindowTextW(_T("약과"));
		m_Price1.SetWindowTextW(_T("2,000원"));
	}
	else if (m_english) {
		m_Text1.SetWindowTextW(_T("Yakgwa"));
		m_Price1.SetWindowTextW(_T("2,000₩"));
	}
	else if (m_chinese) {
		m_Text1.SetWindowTextW(_T("藥果"));
		m_Price1.SetWindowTextW(_T("2,000₩"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r, TRUE);
	UpdateWindow();

	//bitmap 이미지 넣기
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_B10));
	m_pictureControl1.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl2.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl3.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl4.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl5.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl6.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl7.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl8.SetBitmap(hbit);
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_EMPTY));
	m_pictureControl9.SetBitmap(hbit);
	m_buttonCoffee = m_buttonTea = m_buttonCraft = false;
}


void CMFCKIOSKDlg::OnClickedButtonKorean()
{
	// 한국어 버튼 클릭했을 때
	m_korean = true;
	m_english = m_chinese = false;
	if (m_buttonCoffee) {
		if (m_buttonCoffeeDown) {
			ClickedCoffeeDown();
		}
		else
		{
			ClickedCoffeeUp();
		}
	}
	else if (m_buttonCraft) {
		ClickedCraft();
	}
	else if (m_buttonTea) {
		ClickedTea();
	}
	else if (m_buttonBread) {
		if (m_buttonBreadDown) {
			ClickedBreadDown();
		}
		else {
			ClickedBreadUp();
		}
	}
}


void CMFCKIOSKDlg::OnClickedButtonEnglish()
{
	// 영어 버튼 클릭했을 때
	m_english = true;
	m_korean = m_chinese = false;
	if (m_buttonCoffee) {
		if (m_buttonCoffeeDown) {
			ClickedCoffeeDown();
		}
		else
		{
			ClickedCoffeeUp();
		}
	}
	else if (m_buttonCraft) {
		ClickedCraft();
	}
	else if (m_buttonTea) {
		ClickedTea();
	}
	else if (m_buttonBread) {
		if (m_buttonBreadDown) {
			ClickedBreadDown();
		}
		else {
			ClickedBreadUp();
		}
	}
}


void CMFCKIOSKDlg::OnClickedButtonChinese()
{
	// 중국어 버튼 클릭했을 때
	m_chinese = true;
	m_korean = m_english = false;
	if (m_buttonCoffee) {
		if (m_buttonCoffeeDown) {
			ClickedCoffeeDown();
		}
		else
		{
			ClickedCoffeeUp();
		}
	}
	else if (m_buttonCraft) {
		ClickedCraft();
	}
	else if (m_buttonTea) {
		ClickedTea();
	}
	else if (m_buttonBread) {
		if (m_buttonBreadDown) {
			ClickedBreadDown();
		}
		else {
			ClickedBreadUp();
		}
	}
}


void CMFCKIOSKDlg::ClearTextFields()
{
		//텍스트 초기화
		SetDlgItemText(IDC_TEXT1, _T(""));
		SetDlgItemText(IDC_TEXT2, _T(""));
		SetDlgItemText(IDC_TEXT3, _T(""));
		SetDlgItemText(IDC_TEXT4, _T(""));
		SetDlgItemText(IDC_TEXT5, _T(""));
		SetDlgItemText(IDC_TEXT6, _T(""));
		SetDlgItemText(IDC_TEXT7, _T(""));
		SetDlgItemText(IDC_TEXT8, _T(""));
		SetDlgItemText(IDC_TEXT9, _T(""));

		SetDlgItemText(IDC_PRICE1, _T(""));
		SetDlgItemText(IDC_PRICE2, _T(""));
		SetDlgItemText(IDC_PRICE3, _T(""));
		SetDlgItemText(IDC_PRICE4, _T(""));
		SetDlgItemText(IDC_PRICE5, _T(""));
		SetDlgItemText(IDC_PRICE6, _T(""));
		SetDlgItemText(IDC_PRICE7, _T(""));
		SetDlgItemText(IDC_PRICE8, _T(""));
		SetDlgItemText(IDC_PRICE9, _T(""));
}



HBRUSH CMFCKIOSKDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//언어 버튼 투명화
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	int nRet = pWnd->GetDlgCtrlID();
	if (nRet == IDC_BUTTON_KOREAN)  
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_ENGLISH)  
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_CHINESE)  
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_UP)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_DOWN)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_COFFEE)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_CRAFT)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_TEA)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_BREAD)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_TOGO)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	if (nRet == IDC_BUTTON_HERE)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	return hbr;
}
