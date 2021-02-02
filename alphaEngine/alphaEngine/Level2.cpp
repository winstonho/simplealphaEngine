#include "Level2.h"
#include "Level1.h"
#include "Engine.h"
#include "MeshUtil.h"
#include "FontUtil.h"
#include "RenderUtil.h"

void Level2::Load(void)
{
	pMesh1 = MeshUtil::CreateRect(1.0f, 1.0f, 1.0f, 1.0f);
}

void Level2::InitScene(void)
{
	obj1.scale = AEVec2{ 100.0f, 100.0f };
	obj1.colour.SetRGBA(1.0f, 0.0f, 1.0f, 1.0f);
	obj1.deg = 0.0f;


}

void Level2::Update(float dt)
{
	//reset all the Transform to identity
	CleanUp();

	obj1.deg += 10.0f * dt;
	
	//order it important
	obj1.transform.Translate(-0.5f, -0.5f);
	obj1.transform.Scaling(obj1.scale.x, obj1.scale.y);
	obj1.transform.RotInDeg(obj1.deg);
	obj1.transform.Translate(obj1.pos.x, obj1.pos.y);


	if (AEInputCheckTriggered(AEVK_1))
	{
		Engine::GetInstance().gsm.SetNextState(GS_STATES::GS_LEVEL1);
	}

	if (AEInputCheckTriggered(AEVK_R))
	{
		Engine::GetInstance().gsm.SetNextState(GS_STATES::GS_RESTART);
	}


}

void Level2::Draw(void)
{
	AEGfxSetBackgroundColor(0.0f, 0.5f, 0.5f);
	FontUtil::PrintText(Engine::GetInstance().GetFontID(), 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, "This it Level 2");
	FontUtil::PrintText(Engine::GetInstance().GetFontID(), -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, "Rot %.2f", obj1.deg);
	FontUtil::PrintText(Engine::GetInstance().GetFontID(), -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, "FPS %.2f", AEFrameRateControllerGetFrameRate());

	RenderUtil::RenderWithSolidColour(pMesh1, obj1);





}

void Level2::Free(void)
{
}

void Level2::Unload(void)
{
	AEGfxMeshFree(pMesh1);
}

void Level2::CleanUp()
{
	obj1.transform.Identity();
}
