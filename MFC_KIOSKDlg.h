
// MFC_KIOSKDlg.h: 헤더 파일
//

#pragma once
#include "Modal_Pay.h"

// CMFCKIOSKDlg 대화 상자
class CMFCKIOSKDlg : public CDialogEx
{
	// 생성입니다.
public:
	CMFCKIOSKDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_KIOSK_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
public:
	CBitmap m_myBackground;
	// 배경 이미지 멤버변수

//	afx_msg void OnBnClickedButton2();
	
	void m_setButtonPositiion(int buttonX, int buttonY, int nID);
	//afx_msg void OnStnClickedPicturebox3();
	CFont m_font_menu; // 매뉴 텍스트 폰트를 저장하기 위한 멤버변수
	CFont m_font_price; // 매뉴 텍스트 폰트를 저장하기 위한 멤버변수
	CFont m_font_order; // 주문 텍스트 폰트를 저장하기 위한 멤버변수
	CFont m_font_editbox; //에디트박스 텍스트 폰트를 저장 
	CFont m_font_ordersum; // 가격 총합 텍스트 폰트를 저장
	CFont m_font_allsum;

	void m_setFont_for_m_font_menu(int nID); // 매뉴 텍스트 폰트를 변경하기 위한 멤버함수
	void m_setFont_for_m_font_price(int nID); //매뉴 가격 텍스트 폰트를 변경하기 위한 멤버함수
	void m_setFont_for_m_font_order(int nID); //
	void m_setFont_for_m_font_ordersum(int nID); //
	void m_setFont_for_m_font_edit(int nID); //
	void m_setFont_for_m_font_allsum(int nID); //

	void m_setFont2(CFont font, int nID); //사용하지 않는 함수!!!!!!!!




	void m_setFont_menu(int fontsize, int FW);
	void m_setFont_price(int fontsize, int FW);
	void m_setFont_editbox(int fontsize, int FW);
	void m_setFont_order(int fontsize, int FW);
	void m_setFont_ordersum(int fontsize, int FW);
	void m_setFont_allsum(int fontsize, int FW);

	afx_msg void OnClickedButtonCoffee();
	afx_msg void OnClickedButtonCraft();
	afx_msg void OnClickedButtonTea();
	afx_msg void OnClickedButtonBread();
	afx_msg void OnClickedButtonUp();
	afx_msg void OnClickedButtonDown();
	void ClickedCoffeeUp();
	void ClickedCoffeeDown();
	void ClickedCraftUp();
	void ClickedTeaUp();
	void ClickedBreadUp();
	void ClickedBreadDown();
	CStatic m_Text1;
	CStatic m_Text2;
	CStatic m_Text3;
	CStatic m_Text4;
	CStatic m_Text5;
	CStatic m_Text6;
	CStatic m_Text7;
	CStatic m_Text8;
	CStatic m_Text9;
	CStatic m_Price1;
	CStatic m_Price2;
	CStatic m_Price3;
	CStatic m_Price4;
	CStatic m_Price5;
	CStatic m_Price6;
	CStatic m_Price7;
	CStatic m_Price8;
	CStatic m_Price9;
	bool m_buttonCoffee;
	bool m_buttonBread;
	bool m_buttonTea;
	bool m_buttonCraft;
	bool m_buttonBreadDown;
	bool m_buttonCoffeeDown;
	bool m_buttonCraftDown;
	bool m_buttonTeaDown;
	bool m_korean;
	bool m_english;
	bool m_chinese;
	afx_msg void OnClickedButtonKorean();
	afx_msg void OnClickedButtonEnglish();
	afx_msg void OnClickedButtonChinese();
	void ClearTextFields();
	CStatic m_pictureControl1;
	CStatic m_pictureControl2;
	CStatic m_pictureControl3;
	CStatic m_pictureControl4;
	CStatic m_pictureControl5;
	CStatic m_pictureControl6;
	CStatic m_pictureControl7;
	CStatic m_pictureControl8;
	CStatic m_pictureControl9;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//RECT r1 = (x시작, y시작, x끝, y끝 좌표}
	RECT r1 = { 129, 370, 1150, 1100 };    //메뉴판 이미지 범위
	RECT r2 = { 1262, 130, 1900, 660 };    //order 큐 범위(변경 필요할수 있음)
	CStatic m_textOrder1;
	CStatic m_textOrderSum1;
	CStatic m_textOrderSum2;
	CStatic m_textOrderSum3;
	CStatic m_textOrderSum4;
	CStatic m_textOrderSum5;
	CStatic m_textOrderSum6;
	CStatic m_textOrderSum7;
	CStatic m_textOrderSum8;
	CStatic m_textOrder2;
	CStatic m_textOrder3;
	CStatic m_textOrder4;
	CStatic m_textOrder5;
	CStatic m_textOrder6;
	CStatic m_textOrder7;
	CStatic m_textOrder8;
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	CEdit m_edit4;
	CEdit m_edit5;
	CEdit m_edit6;
	CEdit m_edit7;
	CEdit m_edit8;
	afx_msg void OnClickedButtonHere();
	afx_msg void OnClickedButtonTogo();
	Modal_Pay m_dlgPay;
	void ClickedCraftDown();
	void ClickedTeaDown();
};