
// PktSenderDlg.h: 头文件
//

#pragma once
#include "PcapDataInfo.h"

// CPktSenderDlg 对话框
class CPktSenderDlg : public CDialogEx
{
// 构造
public:
	CPktSenderDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PKTSENDER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	PcapDataInfo m_CDataInfo;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editPath;
	afx_msg void OnBnClickedBtOpen();

	afx_msg void OnBnClickedCheckOntop();
	afx_msg void OnSelchangeComboSendmode();
	// 用于设置发送次数或发送包数
	CEdit m_editPktNum;
};
