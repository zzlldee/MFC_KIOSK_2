
// MFC_KIOSKDlg.h: 헤더 파일
//

#pragma once


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

	afx_msg void OnBnClickedButton2();
	
	void m_setButtonPositiion(int buttonX, int buttonY, int nID);
	afx_msg void OnStnClickedPicturebox3();
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

};