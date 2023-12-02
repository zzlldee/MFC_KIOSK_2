
// MFC_KIOSKDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_KIOSK.h"
#include "MFC_KIOSKDlg.h"
#include "afxdialogex.h"
#include "Modal_Pay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// headers about database connection
#include <afxdb.h>
#include <odbcinst.h>
#include <sqlext.h>

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
	DDX_Control(pDX, IDC_TEXT_ORDER1, m_textOrder1);
	DDX_Control(pDX, IDC_TEXT_ORDER1_SUM, m_textOrderSum1);
	DDX_Control(pDX, IDC_TEXT_ORDER2_SUM, m_textOrderSum2);
	DDX_Control(pDX, IDC_TEXT_ORDER3_SUM, m_textOrderSum3);
	DDX_Control(pDX, IDC_TEXT_ORDER4_SUM, m_textOrderSum4);
	DDX_Control(pDX, IDC_TEXT_ORDER5_SUM, m_textOrderSum5);
	DDX_Control(pDX, IDC_TEXT_ORDER6_SUM, m_textOrderSum6);
	DDX_Control(pDX, IDC_TEXT_ORDER7_SUM, m_textOrderSum7);
	DDX_Control(pDX, IDC_TEXT_ORDER8_SUM, m_textOrderSum8);

	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_EDIT5, m_edit5);
	DDX_Control(pDX, IDC_EDIT6, m_edit6);
	DDX_Control(pDX, IDC_EDIT7, m_edit7);
	DDX_Control(pDX, IDC_EDIT8, m_edit8);



	DDX_Control(pDX, 1064, m_orderlist_1); //IDC_TEXT_ORDER 첫번째 ( 주문 리스트 첫번째 )
	DDX_Control(pDX, IDC_TEXT_ORDER12, m_orderlist_2);
	DDX_Control(pDX, IDC_TEXT_ORDER13, m_orderlist_3);
	//DDX_Control(pDX, IDC_TEXT_ORDER14, m_orderlist_4);
	DDX_Control(pDX, 1044, m_orderlist14_2);
	DDX_Control(pDX, IDC_TEXT_ORDER15, m_orderlist_5);
	DDX_Control(pDX, IDC_TEXT_ORDER16, m_orderlist_6);
	DDX_Control(pDX, IDC_TEXT_ORDER17, m_orderlist_7);
	DDX_Control(pDX, IDC_TEXT_ORDER18, m_orderlist_8);

	DDX_Control(pDX, IDC_TEXT_ALLSUM, m_ALLSUM);
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
ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_BUTTON_HERE, &CMFCKIOSKDlg::OnClickedButtonHere)
ON_BN_CLICKED(IDC_BUTTON_TOGO, &CMFCKIOSKDlg::OnClickedButtonTogo)



ON_STN_CLICKED(IDC_TEXT_ORDER13, &CMFCKIOSKDlg::OnStnClickedTextOrder13)
ON_STN_CLICKED(IDC_TEXT_ORDER3_SUM, &CMFCKIOSKDlg::OnStnClickedTextOrder3Sum)
ON_WM_LBUTTONDOWN()
ON_STN_CLICKED(IDC_TEXT_ORDER18, &CMFCKIOSKDlg::OnStnClickedTextOrder18)
ON_STN_CLICKED(IDC_TEXT_ORDER12, &CMFCKIOSKDlg::OnStnClickedTextOrder12)
ON_STN_CLICKED(IDC_TEXT_ORDER19, &CMFCKIOSKDlg::OnStnClickedTextOrder19)
ON_EN_CHANGE(IDC_EDIT1, &CMFCKIOSKDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_CANC1, &CMFCKIOSKDlg::OnBnClickedCanc1)
ON_BN_CLICKED(IDC_CANC2, &CMFCKIOSKDlg::OnBnClickedCanc2)
ON_BN_CLICKED(IDC_CANC3, &CMFCKIOSKDlg::OnBnClickedCanc3)
ON_BN_CLICKED(IDC_CANC4, &CMFCKIOSKDlg::OnBnClickedCanc4)
ON_BN_CLICKED(IDC_CANC5, &CMFCKIOSKDlg::OnBnClickedCanc5)
ON_BN_CLICKED(IDC_CANC6, &CMFCKIOSKDlg::OnBnClickedCanc6)
ON_BN_CLICKED(IDC_CANC7, &CMFCKIOSKDlg::OnBnClickedCanc7)
ON_BN_CLICKED(IDC_CANC8, &CMFCKIOSKDlg::OnBnClickedCanc8)
ON_STN_CLICKED(IDC_TEXT_ORDER2_SUM, &CMFCKIOSKDlg::OnStnClickedTextOrder2Sum)
ON_STN_CLICKED(IDC_TEXT_ORDER8_SUM, &CMFCKIOSKDlg::OnStnClickedTextOrder8Sum)
ON_STN_CLICKED(IDC_letf1, &CMFCKIOSKDlg::OnStnClickedletf1)
ON_STN_CLICKED(IDC_letf2, &CMFCKIOSKDlg::OnStnClickedletf2)
ON_STN_CLICKED(IDC_letf3, &CMFCKIOSKDlg::OnStnClickedletf3)
ON_STN_CLICKED(IDC_letf4, &CMFCKIOSKDlg::OnStnClickedletf4)
ON_STN_CLICKED(IDC_letf5, &CMFCKIOSKDlg::OnStnClickedletf5)
ON_STN_CLICKED(IDC_letf6, &CMFCKIOSKDlg::OnStnClickedletf6)
ON_STN_CLICKED(IDC_letf7, &CMFCKIOSKDlg::OnStnClickedletf7)
ON_STN_CLICKED(IDC_letf8, &CMFCKIOSKDlg::OnStnClickedletf8)
ON_STN_CLICKED(IDC_right1, &CMFCKIOSKDlg::OnStnClickedright1)
ON_STN_CLICKED(IDC_right2, &CMFCKIOSKDlg::OnStnClickedright2)
ON_STN_CLICKED(IDC_right3, &CMFCKIOSKDlg::OnStnClickedright3)
ON_STN_CLICKED(IDC_right4, &CMFCKIOSKDlg::OnStnClickedright4)
ON_STN_CLICKED(IDC_right5, &CMFCKIOSKDlg::OnStnClickedright5)
ON_STN_CLICKED(IDC_right6, &CMFCKIOSKDlg::OnStnClickedright6)
ON_STN_CLICKED(IDC_right7, &CMFCKIOSKDlg::OnStnClickedright7)
ON_STN_CLICKED(IDC_right8, &CMFCKIOSKDlg::OnStnClickedright8)
END_MESSAGE_MAP()


typedef struct {
	CString pname;
	int p;
	int q;
}Product;

Product Array_Stock[32];

void initdb(void) {
	CDatabase db;
	CRecordset rs(&db);

	CTime t = CTime::GetCurrentTime();
	CString ymd;
	ymd.Format(_T("%d_%d_%d"), t.GetYear(), t.GetMonth(), t.GetDay());

	BOOL bret = db.OpenEx(_T("DSN=kiosk_db;"));

	if (bret) // 연결 성공시
	{
		CString dbname = _T("db_");
		dbname.Insert(3, ymd);
		CString initdb = _T("CREATE DATABASE IF NOT EXISTS ;");
		initdb.Insert(30, dbname);
		//AfxMessageBox(dbname);
		db.ExecuteSQL(initdb);

		CString usedb = _T("USE ;");
		usedb.Insert(4, dbname);
		//AfxMessageBox(usedb);
		db.ExecuteSQL(usedb);

		CString t0col = _T("pcode INT, p int, q int");
		CString maket0 = _T("CREATE TABLE IF NOT EXISTS t0_stock();");
		maket0.Insert(36, t0col);
		//AfxMessageBox(maket0);

		CString t1col = _T("dt DATETIME, tno int, type bool, pcode int, p int, q int");
		CString maket1 = _T("CREATE TABLE IF NOT EXISTS t1_trans_1();");
		maket1.Insert(38, t1col);
		//AfxMessageBox(maket1);

		CString t2col = _T("dt DATETIME, tno int, type bool, sum int");
		CString maket2 = _T("CREATE TABLE IF NOT EXISTS t2_trans_2();");
		maket2.Insert(38, t2col);
		//AfxMessageBox(maket2);

		db.ExecuteSQL(maket0);
		db.ExecuteSQL(maket1);
		db.ExecuteSQL(maket2);

		AfxMessageBox(_T("db inited"));
	}
	else
	{
		AfxMessageBox(_T("db error"));
	}
}

// CMFCKIOSKDlg 메시지 처리기
BOOL CMFCKIOSKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//initdb();

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
	m_setButtonPositiion(108, 170, 1007); //매뉴 이미지 박스1
	m_setButtonPositiion(468, 170, 1008); // 2
	m_setButtonPositiion(808, 170, 1009);
	m_setButtonPositiion(108, 450, 1010);
	m_setButtonPositiion(458, 450, 1011);
	m_setButtonPositiion(808, 450, 1012);
	m_setButtonPositiion(108, 750, 1013);
	m_setButtonPositiion(468, 750, 1014);
	m_setButtonPositiion(808, 750, 1015); //9

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
	m_setButtonPositiion(1242, 130, 1064);
	m_setButtonPositiion(1242, 190, 1047);
	m_setButtonPositiion(1242, 260, 1043);
	m_setButtonPositiion(1242, 330, 1044);
	m_setButtonPositiion(1242, 400, 1045);
	m_setButtonPositiion(1242, 470, 1046);
	m_setButtonPositiion(1242, 540, 1048);
	m_setButtonPositiion(1242, 610, 1049);
	
	//주문 가격 총합 텍스트에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1600, 130, 1029);
	m_setButtonPositiion(1600, 190, 1030);
	m_setButtonPositiion(1600, 260, 1031);
	m_setButtonPositiion(1600, 330, 1032);
	m_setButtonPositiion(1600, 400, 1033);
	m_setButtonPositiion(1600, 470, 1042);
	m_setButtonPositiion(1600, 540, 1050);
	m_setButtonPositiion(1600, 610, 1051);
	//주문 수량 에디트박스에 대한 동적 이동 로직입니다. 
	m_setButtonPositiion(1582, 130, 1052);
	m_setButtonPositiion(1582, 190, 1053);
	m_setButtonPositiion(1582, 260, 1054);
	m_setButtonPositiion(1582, 330, 1055);
	m_setButtonPositiion(1582, 400, 1056);
	m_setButtonPositiion(1582, 470, 1057);
	m_setButtonPositiion(1582, 540, 1058);
	m_setButtonPositiion(1582, 610, 1059);
	//주문 수량 조절 버튼에 대한 동적 이동 로직입니다.
	m_setButtonPositiion(1552, 140, 1074);
	m_setButtonPositiion(1552, 200, 1081);
	m_setButtonPositiion(1552, 270, 1082);
	m_setButtonPositiion(1552, 340, 1083);
	m_setButtonPositiion(1552, 410, 1085);
	m_setButtonPositiion(1552, 480, 1086);
	m_setButtonPositiion(1552, 550, 1087);
	m_setButtonPositiion(1552, 620, 1088);

	m_setButtonPositiion(1635, 140, 1075);
	m_setButtonPositiion(1635, 200, 1089);
	m_setButtonPositiion(1635, 270, 1090);
	m_setButtonPositiion(1635, 340, 1091);
	m_setButtonPositiion(1635, 410, 1092);
	m_setButtonPositiion(1635, 480, 1093);
	m_setButtonPositiion(1635, 550, 1094);
	m_setButtonPositiion(1635, 620, 1096);

	//주문 취소 버튼에 대한 동적 이동 로직
	m_setButtonPositiion(1245, 130, IDC_CANC1);
	m_setButtonPositiion(1245, 190, IDC_CANC2);
	m_setButtonPositiion(1245, 260, IDC_CANC3);
	m_setButtonPositiion(1245, 330, IDC_CANC4);
	m_setButtonPositiion(1245, 400, IDC_CANC5);
	m_setButtonPositiion(1245, 470, IDC_CANC6);
	m_setButtonPositiion(1245, 540, IDC_CANC7);
	m_setButtonPositiion(1245, 610, IDC_CANC8);


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
	//m_setFont_order_amount(40, FW_HEAVY);

	/////////////////////////////////////////////////////////
	//초기 설정 false
	m_buttonCoffee = m_buttonBread = m_buttonTea = m_buttonCraft = false;
	m_buttonCoffeeDown = m_buttonBreadDown = m_buttonTeaDown = m_buttonCraftDown = false;
	m_korean = m_english = m_chinese = false;

	OnClickedButtonKorean();   //초기화면 한국어
	OnClickedButtonCoffee();     //초기화면 커피메뉴

	//언어 버튼 투명화
	/*SetWindowTheme(GetDlgItem(IDC_BUTTON_KOREAN)->GetSafeHwnd(), _T(""), _T(""));
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
	SetWindowTheme(GetDlgItem(IDC_BUTTON_TOGO)->GetSafeHwnd(), _T(""), _T(""));*/

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
void CMFCKIOSKDlg::m_setFont_order_amount(int nID)
{
	// TODO: 여기에 구현 코드 추가.
	// 글꼴 적용
	CEdit* pEdit = (CEdit*)GetDlgItem(nID);
	if (pEdit != nullptr)
	{
		//pEdit->SetFont(&m_font);

		pEdit->SetFont(&m_font_order_amount);

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
	m_setFont_for_m_font_order(IDC_TEXT_ORDER19);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER2);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER3);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER4);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER5);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER6);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER7);
	m_setFont_for_m_font_order(IDC_TEXT_ORDER8);

}
void CMFCKIOSKDlg::m_setFont_order_amount(int fontsize, int FW)
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
	m_setFont_order_amount(1072);
	m_setFont_order_amount(1073);
	m_setFont_order_amount(1074);
	m_setFont_order_amount(1075);
	m_setFont_order_amount(1077);
	m_setFont_order_amount(1078);
	m_setFont_order_amount(1079);
	m_setFont_order_amount(1080);

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
	m_buttonCraft = m_buttonTea = m_buttonBread = false;
}


void CMFCKIOSKDlg::OnClickedButtonCraft()
{
	//craft 메뉴를 클릭했을 때 메뉴판
	m_buttonCraft = true;
	ClickedCraftUp();
	m_buttonCoffee = m_buttonTea = m_buttonBread = false;
}


void CMFCKIOSKDlg::OnClickedButtonTea()
{
	//tea 메뉴를 클릭했을 때 메뉴판
	m_buttonTea = true;
	ClickedTeaUp();
	m_buttonCoffee = m_buttonCraft = m_buttonBread  = false;
}


void CMFCKIOSKDlg::OnClickedButtonBread()
{
	//bread 메뉴를 클릭했을 때 메뉴판
	m_buttonBread = true;
	ClickedBreadUp();
	m_buttonCoffee = m_buttonCraft = m_buttonTea = false;
}


void CMFCKIOSKDlg::OnClickedButtonUp()
{
	if (m_buttonCoffee)
	{
		//위 버튼 눌렀을 때(coffee)
		ClickedCoffeeUp();
		m_buttonCoffeeDown = false;
	}
	else if (m_buttonCraft)
	{
		//위 버튼 눌렀을 때(craft)
		ClickedCraftUp();
		m_buttonCraftDown = false;
	}
	else if (m_buttonTea)
	{
		//위 버튼 눌렀을 때(tea)
		ClickedTeaUp();
		m_buttonTeaDown = false;
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
	else if (m_buttonCraft)
	{
		//아래 버튼 눌렀을 때(craft)
		ClickedCraftDown();
		m_buttonCraftDown = true;
	}
	else if (m_buttonTea)
	{
		//아래 버튼 눌렀을 때(tea)
		ClickedTeaDown();
		m_buttonTeaDown = true;
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
	//UP화면
	ClearTextFields();
	m_buttonCoffee = true;
	if (m_korean) {                                        //한국어
		m_Text1.SetWindowTextA(_T("아메리카노(ice)"));
		m_Text2.SetWindowTextA(_T("아메리카노(hot)"));
		m_Text3.SetWindowTextA(_T("카페라떼(ice)"));
		m_Text4.SetWindowTextA(_T("카페라떼(hot)"));
		m_Text5.SetWindowTextA(_T("카라멜마끼아또(ice)"));
		m_Text6.SetWindowTextA(_T("카라멜마끼아또(hot)"));
		m_Text7.SetWindowTextA(_T("콜드브루"));
		m_Text8.SetWindowTextA(_T("바닐라라떼(ice)"));
		m_Text9.SetWindowTextA(_T("바닐라라떼(hot)"));

		m_Price1.SetWindowTextA(_T("1,500원"));
		m_Price2.SetWindowTextA(_T("2,000원"));
		m_Price3.SetWindowTextA(_T("2,900원"));
		m_Price4.SetWindowTextA(_T("2,900원"));
		m_Price5.SetWindowTextA(_T("3,700원"));
		m_Price6.SetWindowTextA(_T("3,700원"));
		m_Price7.SetWindowTextA(_T("3,500원"));
		m_Price8.SetWindowTextA(_T("3,400원"));
		m_Price9.SetWindowTextA(_T("3,400원"));

	}
	else if (m_english) {                                   //영어
		m_Text1.SetWindowTextA(_T("Americano(ice)"));
		m_Text2.SetWindowTextA(_T("Americano(hot)"));
		m_Text3.SetWindowTextA(_T("Latte(ice)"));
		m_Text4.SetWindowTextA(_T("Latte(hot)"));
		m_Text5.SetWindowTextA(_T("Caramel Macchiato(ice)"));
		m_Text6.SetWindowTextA(_T("Caramel Macchiato(hot)"));
		m_Text7.SetWindowTextA(_T("Cold Brew"));
		m_Text8.SetWindowTextA(_T("Vanilla Latte(ice)"));
		m_Text9.SetWindowTextA(_T("Vanilla Latte(hot)"));

		m_Price1.SetWindowTextA(_T("1,500WON"));
		m_Price2.SetWindowTextA(_T("2,000WON"));
		m_Price3.SetWindowTextA(_T("2,900WON"));
		m_Price4.SetWindowTextA(_T("2,900WON"));
		m_Price5.SetWindowTextA(_T("3,700WON"));
		m_Price6.SetWindowTextA(_T("3,700WON"));
		m_Price7.SetWindowTextA(_T("3,500WON"));
		m_Price8.SetWindowTextA(_T("3,400WON"));
		m_Price9.SetWindowTextA(_T("3,400WON"));
	}
	else if (m_chinese) {                                   //중국어
		m_Text1.SetWindowTextA(_T("美式水兒(ice)"));
		m_Text2.SetWindowTextA(_T("美式水兒(hot)"));
		m_Text3.SetWindowTextA(_T("拿鐵水兒(ice)"));
		m_Text4.SetWindowTextA(_T("拿鐵水兒(hot)"));
		m_Text5.SetWindowTextA(_T("焦糖瑪奇(ice)"));
		m_Text6.SetWindowTextA(_T("焦糖瑪奇(hot)"));
		m_Text7.SetWindowTextA(_T("冷萃水兒"));
		m_Text8.SetWindowTextA(_T("香草拿鐵(ice)"));
		m_Text9.SetWindowTextA(_T("香草拿鐵(hot)"));

		m_Price1.SetWindowTextA(_T("1,500WON"));
		m_Price2.SetWindowTextA(_T("2,000WON"));
		m_Price3.SetWindowTextA(_T("2,900WON"));
		m_Price4.SetWindowTextA(_T("2,900WON"));
		m_Price5.SetWindowTextA(_T("3,700WON"));
		m_Price6.SetWindowTextA(_T("3,700WON"));
		m_Price7.SetWindowTextA(_T("3,500WON"));
		m_Price8.SetWindowTextA(_T("3,400WON"));
		m_Price9.SetWindowTextA(_T("3,400WON"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
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
	m_buttonCraft = m_buttonTea = m_buttonBread = false;
}


void CMFCKIOSKDlg::ClickedCoffeeDown()
{
	// 커피 메뉴를 클릭 했을 때
	//DOWN화면
	ClearTextFields();
	m_buttonCoffee = true;
	if (m_korean) {                                         //한국어
		m_Text1.SetWindowTextA(_T("에스프레소"));
		m_Text2.SetWindowTextA(_T("카페모카"));

		m_Price1.SetWindowTextA(_T("1,500원"));
		m_Price2.SetWindowTextA(_T("3,700원"));
	}
	else if (m_english) {                                   //영어
		m_Text1.SetWindowTextA(_T("Espresso"));
		m_Text2.SetWindowTextA(_T("Cafe Mocha"));

		m_Price1.SetWindowTextA(_T("1,500WON"));
		m_Price2.SetWindowTextA(_T("3,700WON"));
	}
	else if (m_chinese) {                                   //중국어
		m_Text1.SetWindowTextA(_T("意式濃縮"));
		m_Text2.SetWindowTextA(_T("巧克力摩"));

		m_Price1.SetWindowTextA(_T("1,500WON"));
		m_Price2.SetWindowTextA(_T("3,700WON"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
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
	m_buttonCraft = m_buttonTea = m_buttonBread = false;
}


void CMFCKIOSKDlg::ClickedCraftUp()
{
	// 제조음료 메뉴를 클릭했을 때
	//UP화면
	ClearTextFields();
	m_buttonCraft = true;
	if (m_korean) {                                        //한국어
		m_Text1.SetWindowTextA(_T("녹차프라페"));
		m_Text2.SetWindowTextA(_T("쿠키프라페"));
		m_Text3.SetWindowTextA(_T("민트프라페"));
		m_Text4.SetWindowTextA(_T("요거트스무디"));
		m_Text5.SetWindowTextA(_T("유니콘프라페"));
		
		m_Price1.SetWindowTextA(_T("3,900원"));
		m_Price2.SetWindowTextA(_T("3,900원"));
		m_Price3.SetWindowTextA(_T("3,900원"));
		m_Price4.SetWindowTextA(_T("3,900원"));
		m_Price5.SetWindowTextA(_T("4,800원"));

	}
	else if (m_english) {                                   //영어
		m_Text1.SetWindowTextA(_T("Green tea Frappe"));
		m_Text2.SetWindowTextA(_T("Cookie Frappe"));
		m_Text3.SetWindowTextA(_T("Mint Frappe"));
		m_Text4.SetWindowTextA(_T("Yoghurt Smoothie"));
		m_Text5.SetWindowTextA(_T("Unicorn Frappe"));

		m_Price1.SetWindowTextA(_T("3,900WON"));
		m_Price2.SetWindowTextA(_T("3,900WON"));
		m_Price3.SetWindowTextA(_T("3,900WON"));
		m_Price4.SetWindowTextA(_T("3,900WON"));
		m_Price5.SetWindowTextA(_T("4,800WON"));
	}
	else if (m_chinese) {                                   //중국어
		m_Text1.SetWindowTextA(_T("綠茶普拉佩"));
		m_Text2.SetWindowTextA(_T("曲奇普拉佩"));
		m_Text3.SetWindowTextA(_T("薄荷色普拉佩"));
		m_Text4.SetWindowTextA(_T("乳酸菌果昔"));
		m_Text5.SetWindowTextA(_T("獨角獸普拉佩"));

		m_Price1.SetWindowTextA(_T("3,900WON"));
		m_Price2.SetWindowTextA(_T("3,900WON"));
		m_Price3.SetWindowTextA(_T("3,900WON"));
		m_Price4.SetWindowTextA(_T("3,900WON"));
		m_Price5.SetWindowTextA(_T("4,800WON"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
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


void CMFCKIOSKDlg::ClickedCraftDown()
{
	// 제조음료 메뉴를 클릭했을 때
	//DOWN화면
	m_buttonCraft = true;
	m_buttonCoffee = m_buttonTea = m_buttonBread = false;
}


void CMFCKIOSKDlg::ClickedTeaUp()
{
	// 차 메뉴를 클릭했을 때
	//UP화면
	ClearTextFields();
	m_buttonTea = true;
	if (m_korean) {                                        //한국어
		m_Text1.SetWindowTextA(_T("유자차"));
		m_Text2.SetWindowTextA(_T("페퍼민트"));
		m_Text3.SetWindowTextA(_T("캐모마일"));
		m_Text4.SetWindowTextA(_T("얼그레이"));
		m_Text5.SetWindowTextA(_T("녹차"));
		m_Text6.SetWindowTextA(_T("사과유자차"));

		m_Price1.SetWindowTextA(_T("3,000원"));
		m_Price2.SetWindowTextA(_T("2,500원"));
		m_Price3.SetWindowTextA(_T("2,500원"));
		m_Price4.SetWindowTextA(_T("2,500원"));
		m_Price5.SetWindowTextA(_T("2,500원"));
		m_Price6.SetWindowTextA(_T("3,500원"));
	}
	else if (m_english) {                                   //영어
		m_Text1.SetWindowTextA(_T("Citron Tea"));
		m_Text2.SetWindowTextA(_T("Peppermint"));
		m_Text3.SetWindowTextA(_T("Chamomile"));
		m_Text4.SetWindowTextA(_T("Earl Grey"));
		m_Text5.SetWindowTextA(_T("Green Tea"));
		m_Text6.SetWindowTextA(_T("Apple citron Tea"));

		m_Price1.SetWindowTextA(_T("3,000WON"));
		m_Price2.SetWindowTextA(_T("2,500WON"));
		m_Price3.SetWindowTextA(_T("2,500WON"));
		m_Price4.SetWindowTextA(_T("2,500WON"));
		m_Price5.SetWindowTextA(_T("2,500WON"));
		m_Price6.SetWindowTextA(_T("3,500WON"));
	}
	else if (m_chinese) {      //중국어

		m_Text1.SetWindowTextA(_T("柚子茶"));
		m_Text2.SetWindowTextA(_T("薄荷洋甘菊茶"));
		m_Text3.SetWindowTextA(_T("洋甘菊茶"));
		m_Text4.SetWindowTextA(_T("伯爵茶"));
		m_Text5.SetWindowTextA(_T("綠茶"));
		m_Text6.SetWindowTextA(_T("沙果柚子茶"));

		m_Price1.SetWindowTextA(_T("3,000WON"));
		m_Price2.SetWindowTextA(_T("2,500WON"));
		m_Price3.SetWindowTextA(_T("2,500WON"));
		m_Price4.SetWindowTextA(_T("2,500WON"));
		m_Price5.SetWindowTextA(_T("2,500WON"));
		m_Price6.SetWindowTextA(_T("3,500WON"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
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
	m_buttonCoffee = m_buttonCraft = m_buttonBread = false;
}


void CMFCKIOSKDlg::ClickedTeaDown()
{
	// 차 메뉴를 클릭했을 때
	//DOWN화면
	m_buttonTea = true;
	m_buttonCoffee = m_buttonCraft = m_buttonBread = false;
}


void CMFCKIOSKDlg::ClickedBreadUp()
{
	// 제과류 메뉴를 클릭했을 때
    //UP화면
	ClearTextFields();
	m_buttonBread = true;
	if (m_korean) {                                        //한국어
		m_Text1.SetWindowTextA(_T("아이스크림 크로플"));
		m_Text2.SetWindowTextA(_T("크루아상"));
		m_Text3.SetWindowTextA(_T("마들렌"));
		m_Text4.SetWindowTextA(_T("스콘"));
		m_Text5.SetWindowTextA(_T("마카롱"));
		m_Text6.SetWindowTextA(_T("샌드위치"));
		m_Text7.SetWindowTextA(_T("아이스크림 슈"));
		m_Text8.SetWindowTextA(_T("롤케익"));
		m_Text9.SetWindowTextA(_T("초코칩쿠키"));

		m_Price1.SetWindowTextA(_T("6,500원"));
		m_Price2.SetWindowTextA(_T("2,800원"));
		m_Price3.SetWindowTextA(_T("3,000원"));
		m_Price4.SetWindowTextA(_T("3,000원"));
		m_Price5.SetWindowTextA(_T("2,700원"));
		m_Price6.SetWindowTextA(_T("3,000원"));
		m_Price7.SetWindowTextA(_T("4,800원"));
		m_Price8.SetWindowTextA(_T("8,000원"));
		m_Price9.SetWindowTextA(_T("3,600원"));
	}
	else if (m_english) {                                   //영어
		m_Text1.SetWindowTextA(_T("Ice cream Croffles"));
		m_Text2.SetWindowTextA(_T("Croissants"));
		m_Text3.SetWindowTextA(_T("Madeleine"));
		m_Text4.SetWindowTextA(_T("Scone"));
		m_Text5.SetWindowTextA(_T("Macaron"));
		m_Text6.SetWindowTextA(_T("Sandwich"));
		m_Text7.SetWindowTextA(_T("Ice cream Puff"));
		m_Text8.SetWindowTextA(_T("Roll Cake"));
		m_Text9.SetWindowTextA(_T("Chocolate chip Cookies"));

		m_Price1.SetWindowTextA(_T("6,500WON"));
		m_Price2.SetWindowTextA(_T("2,800WON"));
		m_Price3.SetWindowTextA(_T("3,000WON"));
		m_Price4.SetWindowTextA(_T("3,000WON"));
		m_Price5.SetWindowTextA(_T("2,700WON"));
		m_Price6.SetWindowTextA(_T("3,000WON"));
		m_Price7.SetWindowTextA(_T("4,800WON"));
		m_Price8.SetWindowTextA(_T("8,000WON"));
		m_Price9.SetWindowTextA(_T("3,600WON"));
	}
	else if (m_chinese) {                                   //중국어
		m_Text1.SetWindowTextA(_T("氷菓淋麥子"));
		m_Text2.SetWindowTextA(_T("牛角面包"));
		m_Text3.SetWindowTextA(_T("瑪德蓮蛋"));
		m_Text4.SetWindowTextA(_T("司康"));
		m_Text5.SetWindowTextA(_T("蛋白杏仁"));
		m_Text6.SetWindowTextA(_T("三明治"));
		m_Text7.SetWindowTextA(_T("氷淇淋泡芙"));
		m_Text8.SetWindowTextA(_T("瑞士卷"));
		m_Text9.SetWindowTextA(_T("巧克力餠干"));

		m_Price1.SetWindowTextA(_T("6,500WON"));
		m_Price2.SetWindowTextA(_T("2,800WON"));
		m_Price3.SetWindowTextA(_T("3,000WON"));
		m_Price4.SetWindowTextA(_T("3,000WON"));
		m_Price5.SetWindowTextA(_T("2,700WON"));
		m_Price6.SetWindowTextA(_T("3,000WON"));
		m_Price7.SetWindowTextA(_T("4,800WON"));
		m_Price8.SetWindowTextA(_T("8,000WON"));
		m_Price9.SetWindowTextA(_T("3,600WON"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
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
	m_buttonCoffee = m_buttonCraft = m_buttonTea = false;
}


void CMFCKIOSKDlg::ClickedBreadDown()
{
	// 제과류 메뉴를 클릭했을 때
	//DOWN화면
	ClearTextFields();
	m_buttonBread = true;

	
	if (m_korean) {                                        //한국어
		m_Text1.SetWindowTextA(_T("약과"));
		m_Price1.SetWindowTextA(_T("2,000원"));
	}
	else if (m_english) {                                   //영어
		m_Text1.SetWindowTextA(_T("Yakgwa"));
		m_Price1.SetWindowTextA(_T("2,000WON"));
	}
	else if (m_chinese) {                                   //중국어
		m_Text1.SetWindowTextA(_T("藥果"));
		m_Price1.SetWindowTextA(_T("2,000WON"));
	}

	// 강제로 윈도우를 다시 그리도록 요청
	InvalidateRect(&r1, TRUE);
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
	m_buttonCoffee = m_buttonCraft = m_buttonTea = false;
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
		if (m_buttonCraftDown) {
			ClickedCraftDown();
		}
		else
		{
			ClickedCraftUp();
		}
	}
	else if (m_buttonTea) {
		if (m_buttonTeaDown) {
			ClickedTeaDown();
		}
		else
		{
			ClickedTeaUp();
		}
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
		if (m_buttonCraftDown) {
			ClickedCraftDown();
		}
		else
		{
			ClickedCraftUp();
		}
	}
	else if (m_buttonTea) {
		if (m_buttonTeaDown) {
			ClickedTeaDown();
		}
		else
		{
			ClickedTeaUp();
		}
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
		if (m_buttonCraftDown) {
			ClickedCraftDown();
		}
		else
		{
			ClickedCraftUp();
		}
	}
	else if (m_buttonTea) {
		if (m_buttonTeaDown) {
			ClickedTeaDown();
		}
		else
		{
			ClickedTeaUp();
		}
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
	//버튼 투명화 함수
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


void CMFCKIOSKDlg::OnClickedButtonHere()
{
	// 매장에서 버튼을 눌렀을 때
	if (m_dlgPay.GetSafeHwnd()) {
		m_dlgPay.DestroyWindow();
	}
	m_dlgPay.DoModal();

}


void CMFCKIOSKDlg::OnClickedButtonTogo()
{
	// 포장 버튼을 눌렀을 때
	if (m_dlgPay.GetSafeHwnd()) {
		m_dlgPay.DestroyWindow();
	}
	m_dlgPay.DoModal();



}
=========
=======
}








void CMFCKIOSKDlg::OnStnClickedTextOrder13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedTextOrder3Sum()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
//	//매뉴 이미지 박스에 대한 동적 이동 로직입니다.
//	m_setButtonPositiion(108, 170, 1007); //매뉴 이미지 박스1
//	m_setButtonPositiion(468, 170, 1008); // 2
//	m_setButtonPositiion(808, 170, 1009);
//	m_setButtonPositiion(108, 450, 1010);
//	m_setButtonPositiion(458, 450, 1011);
//	m_setButtonPositiion(808, 450, 1012);
//	m_setButtonPositiion(108, 750, 1013);
//	m_setButtonPositiion(468, 750, 1014);
//	m_setButtonPositiion(808, 750, 1015); //9
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	{
		// 특정 범위 정의
		
		CRect myRect(108, 170, 300, 370); 
		CRect myRect2(468, 170, 668, 370);
		CRect myRect3(808, 170, 1008, 370);
		CRect myRect4(108, 450, 300, 650);
		CRect myRect5(458, 450, 658, 650);
		CRect myRect6(808, 450, 1008, 650);
		CRect myRect7(108, 750, 300, 950);
		CRect myRect8(468, 750, 668, 950);
		CRect myRect9(808, 750, 1008, 950);

		// 클릭된 좌표가 myRect 내에 있는지 확인
		if (TRUE) { 

			//DDX_Control(pDX, 1064, m_orderlist_1); //IDC_TEXT_ORDER 첫번째 ( 주문 리스트 첫번째 )
			//DDX_Control(pDX, IDC_TEXT_ORDER12, m_orderlist_2);
			//DDX_Control(pDX, IDC_TEXT_ORDER13, m_orderlist_3);
			////DDX_Control(pDX, IDC_TEXT_ORDER14, m_orderlist_4);
			//DDX_Control(pDX, 1044, m_orderlist14_2);
			//DDX_Control(pDX, IDC_TEXT_ORDER15, m_orderlist_5);
			//DDX_Control(pDX, IDC_TEXT_ORDER16, m_orderlist_6);
			//DDX_Control(pDX, IDC_TEXT_ORDER17, m_orderlist_7);
			////DDX_Control(pDX, IDC_TEXT_ORDER18, m_orderlist_8);//
			//bool m_buttonCoffee;//
			//bool m_buttonBread;
			//bool m_buttonTea;
			//bool m_buttonCraft;

			if (myRect.PtInRect(point))
			{
				// 1번 매뉴를 클릭했을 때
				AfxMessageBox(_T("클릭 확인!!!!!!!!!!!."));
				//m_orderlist_1.SetWindowText(_T("아메리카노 (ice)"));  // 테스트
				Add_List(1);
				
			}
			if (myRect2.PtInRect(point))
			{
				// 2번 매뉴를 클릭했을 때 
				AfxMessageBox(_T("클릭 확인2!!!!!!!!!!!."));
				Add_List(2);

			}
			if (myRect3.PtInRect(point))
			{
				// 3번 매뉴를 클릭했을 때 
				AfxMessageBox(_T("클릭 확인!!!!!!!!!!!."));
				Add_List(3);

			}
			if (myRect4.PtInRect(point))
			{
				// 4번 매뉴를 클릭했을 때 
				AfxMessageBox(_T("클릭 확인!!!!!!!!!!!."));
				Add_List(4);

			}if (myRect5.PtInRect(point))
			{
				// 5번 매뉴를 클릭했을 때 
				AfxMessageBox(_T("클릭 확인!!!!!!!!!!!."));
				Add_List(5);

			}if (myRect6.PtInRect(point))
			{
				// 6번 매뉴를 클릭했을 때 
				AfxMessageBox(_T("클릭 확인!!!!!!!!!!!."));
				Add_List(6);

			}if (myRect7.PtInRect(point))
			{
				// 7번 매뉴를 클릭했을 때 
				AfxMessageBox(_T("클릭 확인!!!!!!!!!!!."));
				Add_List(7);

			}if (myRect8.PtInRect(point))
			{
				// 8번 매뉴를 클릭했을 때 
				AfxMessageBox(_T("클릭 확인!!!!!!!!!!!."));
				Add_List(8);

			}
			if (myRect9.PtInRect(point))
			{
				// 9번 매뉴를 클릭했을 때 
				AfxMessageBox(_T("클릭 확인!!!!!!!!!!!."));
				Add_List(9);

			}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCKIOSKDlg::OnStnClickedTextOrder18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedTextOrder12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedTextOrder19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::Add_List(int MENUPOS)
{/*
	"""""""""""""""""""""""""""""""""""""""""""
	"	주문 리스트에 추가
	"
	///*""""""""""""""""""""""""""""""""""""""""*/
	//bool m_buttonCoffee;
	//bool m_buttonBread;
	//bool m_buttonTea;
	//bool m_buttonCraft;
	//*/

	if (m_buttonCoffee && ! m_buttonCoffeeDown) { // 커피의 경우
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(아메리카노_아이스)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(아메리카노_핫)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 3:
			if (InsertOrder(카페라떼_아이스)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 4:
			if (InsertOrder(카페라떼_핫)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 5:
			if (InsertOrder(카라멜마끼아또_아이스)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 6:
			if (InsertOrder(카라멜마끼아또_핫)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 7:
			if (InsertOrder(콜드브루)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 8:
			if (InsertOrder(바닐라라떼_아이스)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 9:
			if (InsertOrder(바닐라라떼_핫)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;

		}
	}
	else if (m_buttonCoffeeDown) {
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(에스프레소)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(카페모카)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		}
	}
	else if (m_buttonTea) { // 차의 경우
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(유자차)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(페퍼민트)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 3:
			if (InsertOrder(캐모마일)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 4:
			if (InsertOrder(얼그레이)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 5:
			if (InsertOrder(녹차)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 6:
			if (InsertOrder(사과유자차)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		}
	}
	else if (m_buttonCraft) { // 제조음료의 경우
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(녹차프라페)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(쿠키프라페)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 3:
			if (InsertOrder(민트프라페)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 4:
			if (InsertOrder(요거트스무디)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 5:
			if (InsertOrder(유니콘프라페 )) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 6:
			if (InsertOrder(유니콘프라페)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		}
		}
	else if (m_buttonBread && ! m_buttonBreadDown) { // 제과류의 경우
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(아이스크림크로플)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 2:
			if (InsertOrder(크루아상)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 3:
			if (InsertOrder(마들렌)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 4:
			if (InsertOrder(스콘)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 5:
			if (InsertOrder(마카롱)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 6:
			if (InsertOrder(샌드위치)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 7:
			if (InsertOrder(아이스크림슈)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 8:
			if (InsertOrder(롤케익)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 9:
			if (InsertOrder(초코칩쿠키)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		case 10:
			if (InsertOrder(약과)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;
		}
	
		}
	else if (m_buttonBreadDown) {
		switch (MENUPOS) {
		case 1:
			if (InsertOrder(약과)) {
				showOrderList();
				MessageBox(_T("주문 성공!"));
			}
			else
				MessageBox(_T("주문 리스트가 꽉 찼습니다!"));
			break;

		}
	}
}

int CMFCKIOSKDlg::InsertOrder(int p_Order) {
	
	//struct OrderList {
	//	CString mName; //매뉴명 
	//	int mQty; // 수량 
	//	int mSum; // 가격 총합
	
	//주문 리스트에 중복이 있는지 확인
	for (int i = 0; i < 8; i++) {
		if (m_OrderList[i].mName == p_Order) {
			m_OrderList[i].mQty++; // 리스트 안에 같은 매뉴가 있으면 수량 + 1
			m_OrderList[i].mSum = getPrice(p_Order) * m_OrderList[i].mQty; // 가격 총합 계산
			return TRUE;
		}
	}

	//빈 자리에 넣음
	for (int i = 0; i < 8; i++) { 
		if (isInitial(m_OrderList[i])){ // 초기화 판단
			m_OrderList[i].mName = p_Order; //매뉴 이름 설정
			m_OrderList[i].mQty++; // 수량 +1
			m_OrderList[i].mSum = getPrice(p_Order) * m_OrderList[i].mQty; // 가격 총합 계산
			return TRUE; //주문 성공
		}
	}

	
	
	return FALSE; //  주문 실패 (주문 리스트에 빈 자리가 없음 !! ) 
}

bool CMFCKIOSKDlg::isInitial(struct OrderList Orderlist)
{
	//구조체가 초기화 상태인지 확인하는 함수
	if (Orderlist.mName == 0)
		return TRUE; //빈 배열 맞음
	else
		return FALSE; //빈 배열 아님
}

int CMFCKIOSKDlg::getPrice(int item_number)
{
	// 매뉴 이름 매크로를 받으면 가격을 리턴하는 함수
	if (item_number == 아메리카노_아이스)
		return 1500;
	else if (item_number == 아메리카노_핫)
		return 2000;
	else if (item_number == 카페라떼_아이스)
		return 2900;
	else if (item_number == 카페라떼_핫)
		return 2900;
	else if (item_number == 카라멜마끼아또_아이스)
		return 3700;
	else if (item_number == 카라멜마끼아또_핫)
		return 3700;
	else if (item_number == 콜드브루)
		return 3500;
	else if (item_number == 바닐라라떼_아이스)
		return 3400;
	else if (item_number == 바닐라라떼_핫)
		return 3400;
	else if (item_number == 에스프레소)
		return 1500;
	else if (item_number == 카페모카)
		return 3700;
	else if (item_number == 녹차프라페)
		return 3900;
	else if (item_number == 쿠키프라페)
		return 3900;
	else if (item_number == 민트프라페)
		return 3900;
	else if (item_number == 요거트스무디)
		return 3900;
	else if (item_number == 유니콘프라페)
		return 4800;
	else if (item_number == 유자차)
		return 3000;
	else if (item_number == 페퍼민트)
		return 2500;
	else if (item_number == 캐모마일)
		return 2500;
	else if (item_number == 얼그레이)
		return 2500;
	else if (item_number == 녹차)
		return 2500;
	else if (item_number == 사과유자차)
		return 3500;
	else if (item_number == 아이스크림크로플)
		return 6500;
	else if (item_number == 크루아상)
		return 2800;
	else if (item_number == 마들렌)
		return 3000;
	else if (item_number == 스콘)
		return 3000;
	else if (item_number == 마카롱)
		return 2700;
	else if (item_number == 샌드위치)
		return 3000;
	else if (item_number == 아이스크림슈)
		return 4800;
	else if (item_number == 롤케익)
		return 8000;
	else if (item_number == 초코칩쿠키)
		return 3600;
	else if (item_number == 약과)
		return 2000;
	else
		return -1; // ERROR : 알 수 없는 매뉴
}


//리스트 삭제 함수
int CMFCKIOSKDlg::deleteOrder(int listPosition) //몇 번째 리스트인지
{/* 
	""""""""""""""""""""""""""""""""""""""""""
		"			1) listPosition 번째 구조체 초기화(삭제)
					2) 구조체 순서 정렬하기
		""""""""""""""""""""""""""""""""""""""""*/
	//"			1) listPosition 번째 구조체 초기화
	initOrder_one(listPosition);

	//"			2) 구조체 순서 정렬하기
	for (int i = 1; i < 8; i++) {
		 
		if (isInitial(m_OrderList[i - 1])) {
			m_OrderList[i - 1] = m_OrderList[i];
			initOrder_one(i + 1);
		}
		
	}

	refreshOrder();

	showOrderList();
	
	return 0;
}


int CMFCKIOSKDlg::initOrder_one(int listPosition) //구조체 하나만 초기화
{
	int n = listPosition - 1;
	// listPosition번째 구조체 초기화
	m_OrderList[n].mName = 0;
	m_OrderList[n].mQty = 0;
	m_OrderList[n].mSum = 0;

	return 0;
}




int CMFCKIOSKDlg::initOrder_all() //구조체 전체 초기화
{
	for (int i = 0; i < 8; i++) {
		m_OrderList[i].mName = 0;
		m_OrderList[i].mQty = 0;
		m_OrderList[i].mSum = 0;

	}
	return 0;
}


int CMFCKIOSKDlg::showOrderList() // 주문 리스트 화면에 표시
{/*
	""""""""""""""""""""""""""""""""""""""""""
		TO DO : 
				주문수량, sum 표시!! 

		"""""""""""""""""""""""""""""""""""""""*/
	//CStatic m_orderlist_1;
	//CStatic m_orderlist_2;
	//CStatic m_orderlist_3;
	//CStatic m_orderlist_4;
	//CStatic m_orderlist_5;
	//CStatic m_orderlist_6;
	//CStatic m_orderlist_7;
	//CStatic m_orderlist_8;
	//CStatic m_orderlist14;
	//CStatic m_orderlist14_2;
	CString mQty[8];
	CString mSum[8];
	CString ALLSUM;
	refreshOrder();
	//주문 리스트 매뉴 이름 추가 
	if (!isInitial(m_OrderList[0])) // 구조체에 내용이 있을 경우
		m_orderlist_1.SetWindowTextA(_T(getName(m_OrderList[0].mName)));
	
	if (!isInitial(m_OrderList[1])) // 구조체에 내용이 있을 경우
		m_orderlist_2.SetWindowTextA(_T(getName(m_OrderList[1].mName)));
	if (!isInitial(m_OrderList[2])) // 구조체에 내용이 있을 경우
		m_orderlist_3.SetWindowTextA(_T(getName(m_OrderList[2].mName)));
	if (!isInitial(m_OrderList[3])) // 구조체에 내용이 있을 경우
		m_orderlist14_2.SetWindowTextA(_T(getName(m_OrderList[3].mName)));
	if (!isInitial(m_OrderList[4])) // 구조체에 내용이 있을 경우
		m_orderlist_5.SetWindowTextA(_T(getName(m_OrderList[4].mName)));
	if (!isInitial(m_OrderList[5])) // 구조체에 내용이 있을 경우
		m_orderlist_6.SetWindowTextA(_T(getName(m_OrderList[5].mName)));
	if (!isInitial(m_OrderList[6])) // 구조체에 내용이 있을 경우
		m_orderlist_7.SetWindowTextA(_T(getName(m_OrderList[6].mName)));
	if (!isInitial(m_OrderList[7])) // 구조체에 내용이 있을 경우
		m_orderlist_8.SetWindowTextA(_T(getName(m_OrderList[7].mName)));

	//주문 리스트 매뉴 수량 추가
	if (!isInitial(m_OrderList[0])) { // 구조체에 내용이 있을 경우
		mQty[0].Format(_T("%d"), m_OrderList[0].mQty);
		m_edit1.SetWindowTextA(mQty[0]);
	}
	if (!isInitial(m_OrderList[1])) { // 구조체에 내용이 있을 경우
		mQty[1].Format(_T("%d"), m_OrderList[1].mQty);
		m_edit2.SetWindowTextA(mQty[1]);
	}if (!isInitial(m_OrderList[2])) { // 구조체에 내용이 있을 경우
		mQty[2].Format(_T("%d"), m_OrderList[2].mQty);
		m_edit3.SetWindowTextA(mQty[2]);
	}if (!isInitial(m_OrderList[3])) { // 구조체에 내용이 있을 경우
		mQty[3].Format(_T("%d"), m_OrderList[3].mQty);
		m_edit4.SetWindowTextA(mQty[3]);
	}if (!isInitial(m_OrderList[4])) { // 구조체에 내용이 있을 경우
		mQty[4].Format(_T("%d"), m_OrderList[4].mQty);
		m_edit5.SetWindowTextA(mQty[4]);
	}if (!isInitial(m_OrderList[5])) { // 구조체에 내용이 있을 경우
		mQty[5].Format(_T("%d"), m_OrderList[5].mQty);
		m_edit6.SetWindowTextA(mQty[5]);
	}if (!isInitial(m_OrderList[6])) { // 구조체에 내용이 있을 경우
		mQty[6].Format(_T("%d"), m_OrderList[6].mQty);
		m_edit7.SetWindowTextA(mQty[6]);
	}if (!isInitial(m_OrderList[7])) { // 구조체에 내용이 있을 경우
		mQty[7].Format(_T("%d"), m_OrderList[7].mQty);
		m_edit8.SetWindowTextA(mQty[7]);
	}

	//주문 리스트 가격합 추가
	if (!isInitial(m_OrderList[0])) { // 구조체에 내용이 있을 경우
		mSum[0].Format(_T("%d"), m_OrderList[0].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum1.SetWindowTextA(mSum[0]);
	}
	if (!isInitial(m_OrderList[1])) { // 구조체에 내용이 있을 경우
		mSum[1].Format(_T("%d"), m_OrderList[1].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum2.SetWindowTextA(mSum[1]);
	}if (!isInitial(m_OrderList[2])) { // 구조체에 내용이 있을 경우
		mSum[2].Format(_T("%d"), m_OrderList[2].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum3.SetWindowTextA(mSum[2]);
	}if (!isInitial(m_OrderList[3])) { // 구조체에 내용이 있을 경우
		mSum[3].Format(_T("%d"), m_OrderList[3].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum4.SetWindowTextA(mSum[3]);
	}if (!isInitial(m_OrderList[4])) { // 구조체에 내용이 있을 경우
		mSum[4].Format(_T("%d"), m_OrderList[4].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum5.SetWindowTextA(mSum[4]);
	}if (!isInitial(m_OrderList[5])) { // 구조체에 내용이 있을 경우
		mSum[5].Format(_T("%d"), m_OrderList[5].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum6.SetWindowTextA(mSum[5]);
	}if (!isInitial(m_OrderList[6])) { // 구조체에 내용이 있을 경우
		mSum[6].Format(_T("%d"), m_OrderList[6].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum7.SetWindowTextA(mSum[6]);
	}if (!isInitial(m_OrderList[7])) { // 구조체에 내용이 있을 경우
		mSum[7].Format(_T("%d"), m_OrderList[7].mQty * getPrice(m_OrderList[0].mName));
		m_textOrderSum8.SetWindowTextA(mSum[7]);
	}

	for (int i = 0,sum = 0; i < 8; i++) {
		sum += m_OrderList[i].mSum;

		if (i == 7) {
			ALLSUM.Format(_T("%d"), sum);
			
			m_ALLSUM.SetWindowTextA(ALLSUM);
		}
	}
	
	return 0;
}


char* CMFCKIOSKDlg::getName(int name) {
		switch (name) {
		case 아메리카노_아이스: return "아메리카노_아이스";
		case 아메리카노_핫: return "아메리카노_핫";
		case 카페라떼_아이스: return "카페라떼_아이스";
		case 카페라떼_핫: return "카페라떼_핫";
		case 카라멜마끼아또_아이스: return "카라멜마끼아또_아이스";
		case 카라멜마끼아또_핫: return "카라멜마끼아또_핫";
		case 콜드브루: return "콜드브루";
		case 바닐라라떼_아이스: return "바닐라라떼_아이스";
		case 바닐라라떼_핫: return "바닐라라떼_핫";
		case 에스프레소: return "에스프레소";
		case 카페모카: return "카페모카";
		case 녹차프라페: return "녹차프라페";
		case 쿠키프라페: return "쿠키프라페";
		case 민트프라페: return "민트프라페";
		case 요거트스무디: return "요거트스무디";
		case 유니콘프라페: return "유니콘프라페";
		case 유자차: return "유자차";
		case 페퍼민트: return "페퍼민트";
		case 캐모마일: return "캐모마일";
		case 얼그레이: return "얼그레이";
		case 녹차: return "녹차";
		case 사과유자차: return "사과유자차";
		case 아이스크림크로플: return "아이스크림크로플";
		case 크루아상: return "크루아상";
		case 마들렌: return "마들렌";
		case 스콘: return "스콘";
		case 마카롱: return "마카롱";
		case 샌드위치: return "샌드위치";
		case 아이스크림슈: return "아이스크림슈";
		case 롤케익: return "롤케익";
		case 초코칩쿠키: return "초코칩쿠키";
		case 약과: return "약과";
		default: return "ERROR";
		}
	}



void CMFCKIOSKDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnBnClickedCanc1() // 주문 취소 버튼 1 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	deleteOrder(1);
}


void CMFCKIOSKDlg::OnBnClickedCanc2() // 주문 취소 버튼 2
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	deleteOrder(2);

}


void CMFCKIOSKDlg::OnBnClickedCanc3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	deleteOrder(3);

}


void CMFCKIOSKDlg::OnBnClickedCanc4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	deleteOrder(4);

}


void CMFCKIOSKDlg::OnBnClickedCanc5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	deleteOrder(5);

}


void CMFCKIOSKDlg::OnBnClickedCanc6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	deleteOrder(6);

}


void CMFCKIOSKDlg::OnBnClickedCanc7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	deleteOrder(7);

}


void CMFCKIOSKDlg::OnBnClickedCanc8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	deleteOrder(8);

}


void CMFCKIOSKDlg::refreshOrder() //주문 리스트 텍스트 전체 초기화
{

	//DDX_Control(pDX, 1064, m_orderlist_1); //IDC_TEXT_ORDER 첫번째 ( 주문 리스트 첫번째 )
	//DDX_Control(pDX, IDC_TEXT_ORDER12, m_orderlist_2);
	//DDX_Control(pDX, IDC_TEXT_ORDER13, m_orderlist_3);
	////DDX_Control(pDX, IDC_TEXT_ORDER14, m_orderlist_4);
	//DDX_Control(pDX, 1044, m_orderlist14_2);
	//DDX_Control(pDX, IDC_TEXT_ORDER15, m_orderlist_5);
	//DDX_Control(pDX, IDC_TEXT_ORDER16, m_orderlist_6);
	//DDX_Control(pDX, IDC_TEXT_ORDER17, m_orderlist_7);
	//DDX_Control(pDX, IDC_TEXT_ORDER18, m_orderlist_8);

	//수량 초기화
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
	SetDlgItemText(IDC_EDIT3, _T(""));
	SetDlgItemText(IDC_EDIT4, _T(""));
	SetDlgItemText(IDC_EDIT5, _T(""));
	SetDlgItemText(IDC_EDIT6, _T(""));
	SetDlgItemText(IDC_EDIT7, _T(""));
	SetDlgItemText(IDC_EDIT8, _T(""));

	//매뉴 초기화
	setTextInit(1064);
	setTextInit(IDC_TEXT_ORDER12);
	setTextInit(IDC_TEXT_ORDER13);
	setTextInit(IDC_TEXT_ORDER14_2);
	setTextInit(IDC_TEXT_ORDER15);
	setTextInit(IDC_TEXT_ORDER16);
	setTextInit(IDC_TEXT_ORDER17);
	setTextInit(IDC_TEXT_ORDER18);

	//가격합 초기화
	setTextInit(IDC_TEXT_ORDER1_SUM);
	setTextInit(IDC_TEXT_ORDER2_SUM);
	setTextInit(IDC_TEXT_ORDER3_SUM);
	setTextInit(IDC_TEXT_ORDER4_SUM);
	setTextInit(IDC_TEXT_ORDER5_SUM);
	setTextInit(IDC_TEXT_ORDER6_SUM);
	setTextInit(IDC_TEXT_ORDER7_SUM);
	setTextInit(IDC_TEXT_ORDER8_SUM);

	//총 가격 초기화
	setTextInit(IDC_TEXT_ALLSUM);
	
}


void CMFCKIOSKDlg::setTextInit(int nID)
{
	CRect Rect;
	GetDlgItem(nID)->GetWindowRect(&Rect);
	ScreenToClient(&Rect);
	InvalidateRect(Rect);
	SetDlgItemText(nID, _T(""));
}


void CMFCKIOSKDlg::OnStnClickedTextOrder2Sum()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedTextOrder8Sum()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedletf1()
{
	minOrder(1);
}


void CMFCKIOSKDlg::OnStnClickedletf2()
{
	minOrder(2);

}


void CMFCKIOSKDlg::OnStnClickedletf3()
{
	minOrder(3);

}


void CMFCKIOSKDlg::OnStnClickedletf4()
{
	minOrder(4);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

=======


void CMFCKIOSKDlg::OnStnClickedletf5()
{
	minOrder(5);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedletf6()
{
	minOrder(6);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedletf7()
{
	minOrder(7);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedletf8()
{
	minOrder(8);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedright1()
{
	addOrder(1);
}


void CMFCKIOSKDlg::OnStnClickedright2()
{
	addOrder(2);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedright3()
{
	addOrder(3);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedright4()
{
	addOrder(4);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedright5()
{
	addOrder(5);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedright6()
{
	addOrder(6);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedright7()
{
	addOrder(7);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCKIOSKDlg::OnStnClickedright8()
{
	addOrder(8);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


int CMFCKIOSKDlg::addOrder(int POS) //매뉴 수량 + 1 버튼 처리
{
	if (isInitial(m_OrderList[POS - 1]))
		return 0;
	else {
		m_OrderList[POS - 1].mQty++;
		m_OrderList[POS - 1].mSum = getPrice(m_OrderList[POS - 1].mName) * m_OrderList[POS - 1].mQty; // 구조체 멤버 sum 업데이트

		showOrderList();
	}
	return 0;
}


int CMFCKIOSKDlg::minOrder(int POS) //매뉴 수량 -1 버튼 처리
{
	if (isInitial(m_OrderList[POS - 1]) || m_OrderList[POS -1].mQty == 1)
		return 0;
	else {
		m_OrderList[POS - 1].mQty--;
		m_OrderList[POS - 1].mSum = getPrice(m_OrderList[POS -1].mName) * m_OrderList[POS - 1].mQty; // 구조체 멤버 sum 업데이트
		showOrderList();
	}
	return 0;
}

