#include "pch.h"
#include "PcapDataInfo.h"


PcapDataInfo::PcapDataInfo()
{
	m_szPath.Empty();	/* ·�� */
	m_iAllPkt = 0;		/* �ܰ��� */
	m_iCurPkt = 0;		/* ��ǰ����� */
	m_iSendedPktNum = 0;	/* �ѷ��͵İ��� */
	m_iNeedSendNum = 1;		/* ��Ҫ���͵İ����� */
	m_enSendMode = LoopPktSend;	/* ����ģʽ */
	m_enSendStat = SendStop;	/* ����״̬ */
}

PcapDataInfo::~PcapDataInfo()
{
}

CString PcapDataInfo::getPath()
{
	return m_szPath;
}

int PcapDataInfo::setPath(CString path)
{
	m_szPath = path;
	return 0;
}

void PcapDataInfo::ClnPath()
{
	m_szPath.Empty();
}

int PcapDataInfo::getAllPkt()
{
	return m_iAllPkt;
}

int PcapDataInfo::setAllPkt(int num)
{
	m_iAllPkt = num;
	return 0;
}

int PcapDataInfo::getCurPkt()
{
	return m_iCurPkt;
}

int PcapDataInfo::setCurPkt(int num)
{
	m_iCurPkt = num;
	return 0;
}

void PcapDataInfo::AccCurPkt()
{
	m_iCurPkt++;
}

void PcapDataInfo::RstCurPkt()
{
	m_iCurPkt = 0;
}

int PcapDataInfo::getSendedPktNum()
{
	return m_iSendedPktNum;
}

void PcapDataInfo::AccSendPkt()
{
	m_iSendedPktNum++;
}

void PcapDataInfo::ClnSendPkt()
{
	m_iSendedPktNum = 0;
}

int PcapDataInfo::getNeedSendNum()
{
	return m_iNeedSendNum;
}

int PcapDataInfo::setNeedSendNum(int num)
{
	m_iNeedSendNum = num;
	return 0;
}

SendModeEnum PcapDataInfo::getSendMode()
{
	return m_enSendMode;
}

int PcapDataInfo::setSendMode(SendModeEnum mode)
{
	m_enSendMode = mode;
	return 0;
}

SendStatEnum PcapDataInfo::getSendStat()
{
	return m_enSendStat;
}

int PcapDataInfo::setSendStat(SendStatEnum stat)
{
	m_enSendStat = stat;
	return 0;
}
