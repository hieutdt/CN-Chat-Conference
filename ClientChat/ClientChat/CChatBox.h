#pragma once
#include "CommonLib.h"
#include "ClientChatDoc.h"
#include "CNoti.h"
enum BoxType { CHAT_GROUP, CHAT_DIRECT };

class CChatBox : public CDialog {
	DECLARE_DYNAMIC(CChatBox)

	public:
		CStatic m_titleCB;
		CEdit m_inputMsg;
		CRichEditCtrl m_outputConversation;
		CListBox m_lstReceivedFiles;

		CommonData sendMsg;
		CString titleCB;
		BoxType type;

		CClientChatDoc* p_Document;

	public:
		CChatBox(CClientChatDoc* doc, CWnd* pParent = nullptr);   // standard constructor
		virtual ~CChatBox();

	public:
		CString GetTitle() { return titleCB; }
		void SetTitle(CString newTitleCB) { titleCB = newTitleCB; m_titleCB.SetWindowText(titleCB);  }
		void SetType(BoxType boxType) { type = boxType; }
		CommonData GetSendMsg() { return sendMsg; }
		void DisplayNewMsg(CommonData&);
		void DisplayNewFile(CommonData&);

	// Dialog Data
	#ifdef AFX_DESIGN_TIME
		enum { IDD = IDD_ChatBox };
	#endif

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		DECLARE_MESSAGE_MAP()

	public:
		afx_msg void OnBtnClickSendMsg();
		afx_msg void OnBtnClickUpload();
		afx_msg void OnDBClickReceiveFile();
		
};


