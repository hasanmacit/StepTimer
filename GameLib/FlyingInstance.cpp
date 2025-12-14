//ekle
#include "../EterBase/StepTimer.h"

//arat
m_fStartTime=0.0f;

//altına ekle
m_fLastTime = 0.0f;

//arat
void CFlyingInstance::UpdateAttachInstance()

//değiştir
void CFlyingInstance::UpdateAttachInstance(float fElapsedTime)

//arat
		D3DXToRadian(m_pData->m_v3AngVel.y)*CTimer::Instance().GetElapsedSecond(),
		D3DXToRadian(m_pData->m_v3AngVel.x)*CTimer::Instance().GetElapsedSecond(),
		D3DXToRadian(m_pData->m_v3AngVel.z)*CTimer::Instance().GetElapsedSecond());

//değiştir
		D3DXToRadian(m_pData->m_v3AngVel.y)*fElapsedTime,
		D3DXToRadian(m_pData->m_v3AngVel.x)*fElapsedTime,
		D3DXToRadian(m_pData->m_v3AngVel.z)*fElapsedTime);

//arat
bool CFlyingInstance::Update()
{

//altına ekle
	float fElapsedTime = float(DX::StepTimer::Instance().GetTotalSeconds() - m_fLastTime);
	m_fLastTime = DX::StepTimer::Instance().GetTotalSeconds();


//arat
float angle = (CTimer::Instance().GetCurrentSecond() - m_fStartTime)*2*3.1415926535897931f/rfad.fPeriod;

//değiştir
float angle = (DX::StepTimer::Instance().GetTotalSeconds() - m_fStartTime)*2*3.1415926535897931f/rfad.fPeriod;

//arat
float dt = CTimer::Instance().GetCurrentSecond() - m_fStartTime;

//değiştir
float dt = DX::StepTimer::Instance().GetTotalSeconds() - m_fStartTime;

//arat
m_pData->m_fHomingStartTime + m_fStartTime < CTimer::Instance().GetCurrentSecond())

//değiştir
m_pData->m_fHomingStartTime + m_fStartTime < DX::StepTimer::Instance().GetTotalSeconds())

//arat
	m_v3Velocity += m_v3Accel*CTimer::Instance().GetElapsedSecond();
	m_v3Velocity.z+=m_pData->m_fGravity * CTimer::Instance().GetElapsedSecond();
	D3DXVECTOR3 v3Movement = m_v3Velocity * CTimer::Instance().GetElapsedSecond();

//değiştir
	m_v3Velocity += m_v3Accel*fElapsedTime;
	m_v3Velocity.z+=m_pData->m_fGravity * fElapsedTime;
	D3DXVECTOR3 v3Movement = m_v3Velocity * fElapsedTime;

//arat
UpdateAttachInstance();

//değiştir
UpdateAttachInstance(fElapsedTime);

//arat
m_fStartTime = CTimer::Instance().GetCurrentSecond();

//değiştir
	m_fStartTime = DX::StepTimer::Instance().GetTotalSeconds();
	m_fLastTime = DX::StepTimer::Instance().GetTotalSeconds();

//arat
UpdateAttachInstance();

//değiştir
UpdateAttachInstance(0.0f);
