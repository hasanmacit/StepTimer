//Arat
 void CInstanceBase::PushTCPState
//İçinde bul
	int nNetworkGap=ELTimer_GetServerFrameMSec()-dwCmdTime;

	m_nAverageNetworkGap=(m_nAverageNetworkGap*70+nNetworkGap*30)/100;

//Değiştir
    const DWORD dwNow = ELTimer_GetServerFrameMSec();
    const int nNetworkGap = static_cast<int>(dwNow - dwCmdTime);
    if (m_nAverageNetworkGap == 0)
    {
        m_nAverageNetworkGap = nNetworkGap;
    }
    else
    {
        int diff = nNetworkGap - m_nAverageNetworkGap;
        if (diff < 0) diff = -diff;
        if (diff > 1000)
            m_nAverageNetworkGap = (m_nAverageNetworkGap * 30 + nNetworkGap * 70) / 100;
        else
            m_nAverageNetworkGap = (m_nAverageNetworkGap * 70 + nNetworkGap * 30) / 100;
    }

////////////////////////////////////////////////////////////////////////////////////////////

//void CInstanceBase::PushTCPState'in içinde bul
kCmdNew.m_uArg      = uArg;

//Altına ekle
    const DWORD dwMaxFutureMs = 300;
    const DWORD kImmediateThresholdMs = 200;

    if (kCmdNew.m_dwChkTime > dwNow + dwMaxFutureMs)
        kCmdNew.m_dwChkTime = dwNow + dwMaxFutureMs;
    else if (kCmdNew.m_dwChkTime > dwNow)
    {
        DWORD dwDelta = kCmdNew.m_dwChkTime - dwNow;
        if (dwDelta <= kImmediateThresholdMs)
            kCmdNew.m_dwChkTime = dwNow;
    }
    const DWORD dwMaxPastMs = 5000;
    if (kCmdNew.m_dwChkTime + dwMaxPastMs < dwNow)
        kCmdNew.m_dwChkTime = dwNow;