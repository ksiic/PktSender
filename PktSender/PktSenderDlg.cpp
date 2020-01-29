
// PktSenderDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "PktSender.h"
#include "PktSenderDlg.h"
#include "afxdialogex.h"
#include "PcapDataInfo.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPktSenderDlg 对话框



CPktSenderDlg::CPktSenderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PKTSENDER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPktSenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PATH, m_editPath);
	DDX_Control(pDX, IDC_EDIT_PKTNUM, m_editPktNum);
}

BEGIN_MESSAGE_MAP(CPktSenderDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_OPEN, &CPktSenderDlg::OnBnClickedBtOpen)
	ON_BN_CLICKED(IDC_CHECK_ONTOP, &CPktSenderDlg::OnBnClickedCheckOntop)
	ON_CBN_SELCHANGE(IDC_COMBO_SENDMODE, &CPktSenderDlg::OnSelchangeComboSendmode)
END_MESSAGE_MAP()


// CPktSenderDlg 消息处理程序

BOOL CPktSenderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 初始化控件状态
	((CButton*)GetDlgItem(IDC_CHECK_ONTOP))->SetCheck(0);		/* 置顶选框为FALSE */
	((CButton*)GetDlgItem(IDC_BT_RESEND))->EnableWindow(FALSE);	/* 重发按钮不可点击 */
	((CButton*)GetDlgItem(IDC_BT_STOP))->EnableWindow(FALSE);	/* 停止按钮不可点击 */

	((CComboBox*)GetDlgItem(IDC_COMBO_SENDMODE))->SetCurSel(0);	/* 设置下拉列表为"循环发送" */
	((CEdit*)GetDlgItem(IDC_EDIT_PKTNUM))->SetWindowText(L"1");	/* 设置循环发送次数为"1" */

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPktSenderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPktSenderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPktSenderDlg::OnBnClickedBtOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(
		TRUE, NULL, NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(L"离线报文(*.pcap;*.cap)|*.PCAP;*.CAP|所有文件(*.*)|*.*||"));

	if (dlg.DoModal() == IDOK)
	{
		m_CDataInfo.setPath(dlg.GetPathName());
		m_editPath.SetWindowText(m_CDataInfo.getPath());
	}
	else
	{
		/* 清除字符串 */
		m_CDataInfo.ClnPath();
		m_editPath.SetWindowText(m_CDataInfo.getPath());
	}
	
	
}


void CPktSenderDlg::OnBnClickedCheckOntop()
{
	// TODO: 在此添加控件通知处理程序代码
	int state = ((CButton*)GetDlgItem(IDC_CHECK_ONTOP))->GetCheck();
	if (1 == state)
	{
		SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	}
	else
	{
		SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	}
}


void CPktSenderDlg::OnSelchangeComboSendmode()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = ((CComboBox*)GetDlgItem(IDC_COMBO_SENDMODE))->GetCurSel();
	if (0 == index)
	{
		/* 设置 IDC_STATIC_TIMES 标签为"次数" */
		((CStatic*)GetDlgItem(IDC_STATIC_TIMES))->SetWindowText(L"次数");

		/* 设置 IDC_EDIT_PKTNUM 循环发送次数为"1" */
		if (!m_editPktNum.IsWindowEnabled())
		{
			m_editPktNum.EnableWindow(TRUE);
		}
		m_editPktNum.SetWindowText(L"1");
	}
	else if (1 == index)
	{
		/* 设置 IDC_EDIT_PKTNUM 循环发送次数为空，且控件不可用 */
		if (m_editPktNum.IsWindowEnabled())
		{
			m_editPktNum.EnableWindow(FALSE);
		}
		m_editPktNum.SetWindowText(L"");
	}
	else if (2 == index)
	{
		/* 设置 IDC_STATIC_TIMES 标签为"次数" */
		((CStatic*)GetDlgItem(IDC_STATIC_TIMES))->SetWindowText(L"包数");

		/* 设置 IDC_EDIT_PKTNUM 循环发送次数为"1" */
		if (!m_editPktNum.IsWindowEnabled())
		{
			m_editPktNum.EnableWindow(TRUE);
		}
		m_editPktNum.SetWindowText(L"1");
	}
	else
	{
		/* 设置 IDC_STATIC_TIMES 标签内容为空 */
		((CStatic*)GetDlgItem(IDC_STATIC_TIMES))->SetWindowText(L"");

		/* 设置 IDC_EDIT_PKTNUM 循环发送次数为空，且控件不可用 */
		if (m_editPktNum.IsWindowEnabled())
		{
			m_editPktNum.EnableWindow(FALSE);
		}
		m_editPktNum.SetWindowText(L"");
		AfxMessageBox(L"slect err.");
	}
}
