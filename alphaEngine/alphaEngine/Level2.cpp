#include "Level2.h"
#include "Level1.h"
#include "Engine.h"
#include "MeshUtil.h"
#include "FontUtil.h"
#include "RenderUtil.h"
#include <vector>
#include "Math.h"
#include "Particale.h"
#include "Math.h"

AEGfxBlendMode blendTest = AE_GFX_BM_BLEND;
CircleEmitter blackHole;
CircleEmitter firework;
AEVec2 fireworkPos;
void Level2::Load(void)
{
	pMesh1 = MeshUtil::CreateRect(1.0f, 1.0f, 1.0f, 1.0f);
	circleMesh1 = MeshUtil::CreateCircle(1.0f);
}

void Level2::InitScene(void)
{
	obj1.scale = AEVec2{ 100.0f, 100.0f };
	obj1.colour.SetRGBA(1.0f, 1.0f, 1.0f, 1.0f);
	obj1.deg = 0.0f;


	//blackHole.setting.mindirInDegree = -90;
	//blackHole.setting.maxdirInDegree = -90;
	blackHole.setting.m_colourStart = CColour(1.0f, 0.0f, 0.0f, 1.0f);
	blackHole.setting.m_colourEnd = CColour(0.0f, 0.0f, 1.0f, 0.0f);
	//blackHole.setting.m_minSize = 3.0f;
	//blackHole.setting.m_maxSize = 5.0f;
	//blackHole.setting.m_minlifeTime = 3.0f;
	//blackHole.setting.m_maxlifeTime = 5.0f;
	//blackHole.setting.m_maxSpeed = 50.0f;
	//blackHole.setting.m_minSpeed = 30.0f;
	//blackHole.SetMaxParticale(256);
	//blackHole.m_minAngleInDeg = 0.0;
	//blackHole.m_maxAngleInDeg = 360.0;
	//blackHole.m_minRadius = 100.0f;
	//blackHole.m_maxRadius = 100.0f;
	blackHole.sizeEffect = EFFECT::FADEOUT;
	blackHole.LoadSetting2("test.txt");
	blackHole.Init();
	

	firework.setting.mindirInDegree = 0;
	firework.setting.maxdirInDegree = 0;
	firework.setting.m_colourStart = CColour(0.9f, 0.6f, 0.1f, 1.0f);
	firework.setting.m_colourEnd = CColour(0.9f, 0.6f, 0.1f, 0.0f);
	firework.setting.m_minSize = 3.0f;
	firework.setting.m_maxSize = 3.0f;
	firework.setting.m_minlifeTime = 3.0f;
	firework.setting.m_maxlifeTime = 5.0f;
	firework.setting.m_maxSpeed = 0;
	firework.setting.m_minSpeed = 0;
	firework.SetMaxParticale(256);
	firework.m_minAngleInDeg = 0.0;
	firework.m_maxAngleInDeg = 360.0;
	firework.m_minRadius = 0;
	firework.m_maxRadius = 10;
	firework.sizeEffect = EFFECT::FADEOUT;
	firework.Init();
	firework.emiteTime = 4.0f;

	fireworkPos.y = AEGfxGetWinMinY();

}

void Level2::Update(float dt)
{
	//reset all the Transform to identity
	CleanUp();
	AEVec2 vel;

	
	//std::cout << angle << std::endl;

	obj1.deg += 100.0f * dt;
	vel.x = cosf(AEDegToRad(obj1.deg));
	vel.y = sinf(AEDegToRad(obj1.deg));
	
	//order it important
	obj1.transform.Scaling(obj1.scale.x, obj1.scale.y);
	obj1.transform.RotInDeg(obj1.deg);
	obj1.transform.Translate(obj1.pos.x, obj1.pos.y);
	//obj1.pos = vel * 100;

	if (AEInputCheckTriggered(AEVK_1))
	{
		std::cout << "hello1" << std::endl;
		blendTest = AE_GFX_BM_ADD;
	}

	if (AEInputCheckTriggered(AEVK_R))
	{
		Engine::GetInstance().gsm.SetNextState(GS_STATES::GS_RESTART);
	}

	if (AEInputCheckTriggered(AEVK_Q))
	{
		blackHole.SetMaxParticale(blackHole.GetMaxParticale() * 2);
		blackHole.Init();
	}
	if (AEInputCheckTriggered(AEVK_2))
	{
		std::cout << "hello" << std::endl;
		blendTest = AE_GFX_BM_BLEND;
	}

	if (AEInputCheckTriggered(AEVK_L))
	{
		std::cout << "hello" << std::endl;
		blackHole.LoadSetting("test.txt");
	}
	
	blackHole.EmitParticle(obj1.pos,false);
	blackHole.Update(dt);
	if (firework.emiteTime > 0.0f)
	{
		fireworkPos.y = fireworkPos.y + 50 * dt;
		firework.emiteTime -= dt;
	}
	firework.EmitParticle(fireworkPos);
	firework.Update(dt);
}

void Level2::Draw(void)
{
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	size_t size = tESTparticale.size();

	FontUtil::PrintText(Engine::GetInstance().GetFontID(), -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, "FPS %.2f", AEFrameRateControllerGetFrameRate());
	FontUtil::PrintText(Engine::GetInstance().GetFontID(), 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, "size %.2d", blackHole.GetMaxParticale());
	
	//RenderUtil::RenderWithSolidColour(pMesh1, obj1);
		
	
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetBlendMode(blendTest);

	RenderBlackHole();
	RenderFireWorkHole();



}

void Level2::Free(void)
{
}

void Level2::Unload(void)
{
	AEGfxMeshFree(pMesh1);
	AEGfxMeshFree(circleMesh1);
}

void Level2::CleanUp()
{
	obj1.transform.Identity();
}

void Level2::RenderBlackHole()
{
	auto particaleSize = blackHole.GetNumberOFActiveParticale();
	const auto& particaleBuffer = blackHole.GetParticaleBuffer();

	CTransformation parent;

	parent.RotInDeg(obj1.deg);
	parent.Translate(obj1.pos.x, obj1.pos.y);

	for (unsigned int i = 0; i < particaleSize; ++i)
	{
		CTransformation transform;

		transform.Scaling(particaleBuffer[i].m_fSize, particaleBuffer[i].m_fSize);
		transform.Translate(particaleBuffer[i].m_Position.x, particaleBuffer[i].m_Position.y);
		transform = parent * transform;

		AEGfxSetTransform(transform.GetTransformationMatrix()->m);
		AEGfxSetTintColor(particaleBuffer[i].m_Color.GetR(), particaleBuffer[i].m_Color.GetG(), particaleBuffer[i].m_Color.GetB(), particaleBuffer[i].m_Color.GetA());
		AEGfxSetTransparency(particaleBuffer[i].m_Color.GetA());
		// Set texture
		//AEGfxTextureSet(nullptr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(circleMesh1, AE_GFX_MDM_TRIANGLES);
	}
}

void Level2::RenderFireWorkHole()
{
	auto particaleSize = firework.GetNumberOFActiveParticale();
	const auto& particaleBuffer = firework.GetParticaleBuffer();

	

	for (unsigned int i = 0; i < particaleSize; ++i)
	{
		CTransformation transform;

		transform.Scaling(particaleBuffer[i].m_fSize, particaleBuffer[i].m_fSize);
		transform.Translate(particaleBuffer[i].m_Position.x, particaleBuffer[i].m_Position.y);

		AEGfxSetTransform(transform.GetTransformationMatrix()->m);
		AEGfxSetTintColor(particaleBuffer[i].m_Color.GetR(), particaleBuffer[i].m_Color.GetG(), particaleBuffer[i].m_Color.GetB(), particaleBuffer[i].m_Color.GetA());
		AEGfxSetTransparency(particaleBuffer[i].m_Color.GetA());
		// Set texture
		//AEGfxTextureSet(nullptr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(circleMesh1, AE_GFX_MDM_TRIANGLES);
	}
}
