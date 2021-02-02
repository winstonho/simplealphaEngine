#include "Level1.h"
#include "Engine.h"
#include "MeshUtil.h"
#include "FontUtil.h"
#include "RenderUtil.h"

void Level1::Load(void)
{
	pMesh1 = MeshUtil::CreateRect(1.0f, 1.0f, 1.0f, 1.0f);
}

void Level1::InitScene(void)
{
	obj1.scale = AEVec2{ 100.0f, 100.0f };
	obj1.colour.SetRGBA(1.0f, 0.0f, 0.0f, 1.0f);
	obj1.deg = 0.0f;
}

void Level1::Update(float dt)
{
	//reset all the Transform to identity
	CleanUp();

	obj1.deg += 100.0f * dt;

	obj1.transform.Scaling(obj1.scale.x, obj1.scale.y);
	obj1.transform.RotInDeg(obj1.deg);
	obj1.transform.Translate(obj1.pos.x, obj1.pos.y);

	if (AEInputCheckTriggered(AEVK_2))
	{
		Engine::GetInstance().gsm.SetNextState(GS_STATES::GS_LEVEL2); 
	}

	if (AEInputCheckTriggered(AEVK_R))
	{
		Engine::GetInstance().gsm.SetNextState(GS_STATES::GS_RESTART);
	}

}

void Level1::Draw(void)
{

	int x = 0, y = 0;
	AEInputGetCursorPosition(&x, &y);

	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	FontUtil::PrintText(Engine::GetInstance().GetFontID(), 0.5f, 0.5f,1.0f, 1.0f, 1.0f, 1.0f, "This it Level 1");
	FontUtil::PrintText(Engine::GetInstance().GetFontID(), -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, "Rot %.2f",obj1.deg);
	FontUtil::PrintText(Engine::GetInstance().GetFontID(), -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, "FPS %.2f", AEFrameRateControllerGetFrameRate());
	FontUtil::PrintText(Engine::GetInstance().GetFontID(), 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, "Mouse Pos{ %d,%d}", x, y);
	RenderUtil::RenderWithSolidColour(pMesh1, obj1);



	
	
}

void Level1::Free(void)
{
}

void Level1::Unload(void)
{
	AEGfxMeshFree(pMesh1);
}

void Level1::CleanUp()
{
	obj1.transform.Identity();
}
