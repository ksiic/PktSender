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
	CString m_szPath;	/* ·�� */
	int m_iAllPkt;		/* �ܰ��� */
	int m_iCurPkt;		/* ��ǰ����� */
	int m_iSendedPktNum;	/* �ѷ��͵İ��� */
	int m_iNeedSendNum;		/* ��Ҫ���͵İ����� */
	SendModeEnum m_enSendMode;	/* ����ģʽ */
	SendStatEnum m_enSendStat;	/* ����״̬ */
public:
	PcapDataInfo();			/* ��ʼ�� */
	~PcapDataInfo();		/* ���� */

public:
	CString getPath();			/* ��ȡ�ļ�·�� */
	int setPath(CString path);	/* �����ļ�·�� */
	void ClnPath();				/* ���·�� */

	int getAllPkt();			/* ��ȡ���а����� */
	int setAllPkt(int num);		/* �������а����� */

	int getCurPkt();			/* ��ȡ��ǰ�İ���� */
	int setCurPkt(int num);		/* ���õ�ǰ�İ���� */
	void AccCurPkt();			/* ��ǰ�İ���ż�1 */
	void RstCurPkt();			/* ���õ�ǰ�İ���� */

	int getSendedPktNum();		/* ��ȡ�ѷ��͵İ��� */
	void AccSendPkt();			/* �ѷ��Ͱ�����1 */
	void ClnSendPkt();			/* ����ѷ��Ͱ��� */

	int getNeedSendNum();		/* ��ȡ��Ҫ���͵İ��� */
	int setNeedSendNum(int num);	/* ������Ҫ���͵İ��� */

	SendModeEnum getSendMode();			/* ��ȡ����ģʽ */
	int setSendMode(SendModeEnum mode);	/* ���÷���ģʽ */

	SendStatEnum getSendStat();			/* ��ȡ����״̬ */
	int setSendStat(SendStatEnum stat);	/* ���÷���״̬ */


};