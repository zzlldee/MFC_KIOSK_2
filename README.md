# MFC_KIOSK_2

	//매뉴 이름 enum
		enum Menu {
		아메리카노_아이스 = 1,
		아메리카노_핫 = 2,
		카페라떼_아이스 = 3,
		카페라떼_핫 = 4,
		카라멜마끼아또_아이스 = 5,
		카라멜마끼아또_핫 = 6,
		콜드브루 = 7,
		바닐라라떼_아이스 = 8,
		바닐라라떼_핫 = 9,
		에스프레소 = 10,
		카페모카 = 11,
		녹차프라페 = 12,
		쿠키프라페 = 13,
		민트프라페 = 14,
		요거트스무디 = 15,
		유니콘프라페 = 16,
		유자차 = 17,
		페퍼민트 = 18,
		캐모마일 = 19,
		얼그레이 = 20,
		녹차 = 21,
		사과유자차 = 22,
		아이스크림크로플 = 23,
		크루아상 = 24,
		마들렌 = 25,
		스콘 = 26,
		마카롱 = 27,
		샌드위치 = 28,
		아이스크림슈 = 29,
		롤케익 = 30,
		초코칩쿠키 = 31,
		약과 = 32,
	};

 	//주문 리스트 구조체 구조 ( 앱 내부용 )
	struct OrderList {
		int mName = 0; //매뉴명 
		int mQty = 0; // 수량 
		int mSum = 0; // 가격 총합

	};

//주문 리스트 구조체 배열 선언
 //주문 1번부터 8번까지.
struct OrderList m_OrderList[8]; // 주문 리스트 구조체 배열 선언.
 


 int CMFCKIOSKDlg::initOrder_all() //구조체 전체 초기화

 int CMFCKIOSKDlg::initOrder_one(int listPosition) //구조체 하나만 초기화. 


//파라미터로 매뉴 이름에 해당하는 정수값을 받아 스트링을 리턴하는 함수.
//예시)
//getName(m_OrderList[0]);
//


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
