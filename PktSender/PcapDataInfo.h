#pragma once

typedef enum{
	SinglePktSend,
	MultiPktSend,
	OncePktSend,
	LoopPktSend
}SendModeEnum;

typedef enum {
	SendStart,
	SendStop,
	SendPause,
	SendEnd
}SendStatEnum;

class PcapDataInfo
{
private:
	CString m_szPath;	/* 路径 */
	int m_iAllPkt;		/* 总包数 */
	int m_iCurPkt;		/* 当前包序号 */
	int m_iSendedPktNum;	/* 已发送的包数 */
	int m_iNeedSendNum;		/* 需要发送的包个数 */
	SendModeEnum m_enSendMode;	/* 发送模式 */
	SendStatEnum m_enSendStat;	/* 发送状态 */
public:
	PcapDataInfo();			/* 初始化 */
	~PcapDataInfo();		/* 析构 */

public:
	CString getPath();			/* 获取文件路径 */
	int setPath(CString path);	/* 设置文件路径 */
	void ClnPath();				/* 清除路径 */

	int getAllPkt();			/* 获取所有包个数 */
	int setAllPkt(int num);		/* 设置所有包个数 */

	int getCurPkt();			/* 获取当前的包序号 */
	int setCurPkt(int num);		/* 设置当前的包序号 */
	void AccCurPkt();			/* 当前的包序号加1 */
	void RstCurPkt();			/* 重置当前的包序号 */

	int getSendedPktNum();		/* 获取已发送的包数 */
	void AccSendPkt();			/* 已发送包数加1 */
	void ClnSendPkt();			/* 清除已发送包数 */

	int getNeedSendNum();		/* 获取需要发送的包数 */
	int setNeedSendNum(int num);	/* 设置需要发送的包数 */

	SendModeEnum getSendMode();			/* 获取发送模式 */
	int setSendMode(SendModeEnum mode);	/* 设置发送模式 */

	SendStatEnum getSendStat();			/* 获取发送状态 */
	int setSendStat(SendStatEnum stat);	/* 设置发送状态 */


};