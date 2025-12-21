//ARAT
void CActorInstance::CurrentMotionProcess()
//İçinde Bul
    if (!isLooping)
    {

//Altına ekle

        if (m_kCurMotNode.fStartTime <= 0.0f)
            m_kCurMotNode.fStartTime = fCurrentTime;