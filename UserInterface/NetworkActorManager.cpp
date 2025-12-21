//Arat
void SNetworkActorData::SetDstPosition

//Komple Değiştir
void SNetworkActorData::SetDstPosition(DWORD dwServerTime, LONG lDstX, LONG lDstY, DWORD dwDuration)
{
    m_lSrcX = m_lCurX;
    m_lSrcY = m_lCurY;
    m_lDstX = lDstX;
    m_lDstY = lDstY;

    const DWORD dwMaxInterpMs = 200;


    LONG dx = lDstX - m_lSrcX;
    LONG dy = lDstY - m_lSrcY;
    double dist = sqrt(double(dx) * double(dx) + double(dy) * double(dy));
    DWORD computedDuration = (DWORD)(dist / 2.0); // heuristic: 2 pixels per ms
    if (computedDuration < 50) computedDuration = 50;
    if (computedDuration > dwMaxInterpMs) computedDuration = dwMaxInterpMs;

    if (dwDuration > dwMaxInterpMs)
        dwDuration = dwMaxInterpMs;
    if (dwDuration == 0)
        dwDuration = 1;

    if (dwDuration < computedDuration)
        m_dwDuration = dwDuration;
    else
        m_dwDuration = computedDuration;

    DWORD nowClient = ELTimer_GetMSec();
    if (dwServerTime == 0 || dwServerTime > nowClient + 500)
        dwServerTime = nowClient;

    m_dwServerSrcTime = dwServerTime;
    m_dwClientSrcTime = nowClient;
}