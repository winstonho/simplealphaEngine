#include "Engine.h"

static Engine* instance;

Engine & Engine::GetInstance()
{
	if (!instance)
		instance = new Engine();

	return *instance;
}
void Engine::InitScene(HINSTANCE hAppInstance, s32 show, s32 WinWidth, s32 WinHeight, s32 CreateConsole, const s8 * pTitle)
{
	// Using custom window procedure
	AESysInit(hAppInstance, show, WinWidth, WinHeight, CreateConsole, 60, true, NULL);


	// Changing the window title
	AESysSetWindowTitle(pTitle);

	// reset the system modules
	AESysReset();
}

void Engine::Load()
{
	sceneManager.SetUp();
	fontID = AEGfxCreateFont("Resource/Font/Roboto-Regular.ttf", 12);
	
	gsm.GSM_Initialize(GS_STATES::GS_LEVEL2);
	sceneManager.SetLevel(gsm.GetCurrentState());
}
void Engine::Update()
{
	// initialize current state
	while (gsm.GetCurrentState() !=  GS_STATES::GS_QUIT)
	{
		if (gsm.GetCurrentState() == GS_STATES::GS_RESTART)
		{
			// set the current and next state to its previous state
			gsm.SetCurrentState(gsm.GetPreviousState());
			gsm.SetNextState(gsm.GetPreviousState());
		}
		else
		{
			// load the current state's resources
			sceneManager.Load();
		}

		// initialize current state
		sceneManager.InitScene();

		while (gsm.GetCurrentState() == gsm.GetNextState())
		{
			// Informing the system about the loop's start
			float dt = (float)AEFrameRateControllerGetFrameTime();
			AESysFrameStart();
			// allow inputs
			AEInputUpdate();


			// update the scenes
			sceneManager.Update(dt);

			// draw the scenes
			sceneManager.Render();


			AESysFrameEnd();

			// Set the state to quit if the window does not exist
			if (AESysDoesWindowExist() == false)
				gsm.SetCurrentState(GS_STATES::GS_QUIT);
		}

		// clears the data of the current state
		//SceneManager::GetInstance()->Free();
		if (gsm.GetNextState() != GS_STATES::GS_RESTART)
			// unloads the resources of the current state
			sceneManager.Unload();


		// set the previous state to the current state
		gsm.SetPreviousState(gsm.GetCurrentState());

		// set the current state to the next state
		gsm.SetCurrentState(gsm.GetNextState());
		sceneManager.SetLevel(gsm.GetCurrentState());

		//SceneManager::GetInstance()->ChangeState(GSM::GetInstance()->GetCurrentState());
		if (AESysDoesWindowExist() == false)
			gsm.SetCurrentState(GS_STATES::GS_QUIT);
	}

}
void Engine::Destory()
{
	AEGfxDestroyFont(fontID);
	delete instance;
	instance = nullptr;	
	AESysExit();
}

Engine::Engine()
	:fontID(0)
{

}
Engine::~Engine()
{
}

int Engine::GetFontID()
{
	return fontID;
}
