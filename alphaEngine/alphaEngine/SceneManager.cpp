/* Start Header ************************************************************************/
/*!
\file     SceneManager.cpp
\author   Tan De Bin, debin.tan, 390004917
\par	  debin.tan\@digipen.edu
\date	  Feb 11, 2018
\course	  GAM150 (The Magic Moment)
\brief	  This file contains a class to call the functions of current game state

Copyright (C) 2018 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents
without the prior written consent of DigiPen Institute of
Technology is prohibited.
*/
/* End Header **************************************************************************/
#include "SceneManager.h"
#include "Level1.h"
#include "Level2.h"


/******************************************************************************/
/*!
\brief SceneManager
	Constructor

*/
/******************************************************************************/
SceneManager::SceneManager()
	:currentScene{}, ifPause{ false }, sceneId{ GS_STATES::GS_NULL }
	,sceneArray{nullptr,nullptr}
{
}

/******************************************************************************/
/*!
\brief ~SceneManager
	Destructor

*/
/******************************************************************************/
SceneManager::~SceneManager()
{
	for ( Scene * & elem : sceneArray)
	{
		if (elem != nullptr)
			delete elem;
	}
}

void SceneManager::SetUp()
{
	sceneArray[(unsigned)GS_STATES::GS_LEVEL1] = new Level1();
	sceneArray[(unsigned)GS_STATES::GS_LEVEL2] = new Level2();
}

void SceneManager::Render()
{
	currentScene->Draw();
}


/******************************************************************************/
/*!
\brief SetSceneID
	Set the id of new scene

\param id
	Id of the new scene

\ret void
*/
/******************************************************************************/
void SceneManager::SetLevel(GS_STATES id)
{
	if (id < GS_STATES::GS_COUT)
	{
		sceneId = id;
		currentScene = sceneArray[(unsigned int)id];
	}
}

/******************************************************************************/
/*!
\brief Load
	Used by the system to load the child data

\ret void
*/
/******************************************************************************/
void SceneManager::Load()
{
	this->currentScene->Load();
}

/******************************************************************************/
/*!
\brief Init
	Used by the system to initialize the child

\ret void
*/
/******************************************************************************/
void SceneManager::InitScene()
{
	this->currentScene->InitScene();
}

/******************************************************************************/
/*!
\brief Update
	Used by the system to update the child datas

\param dt
	The time for each frame

\ret void
*/
/******************************************************************************/
void SceneManager::Update(float dt)
{
	this->currentScene->Update(dt);
}

/******************************************************************************/
/*!
\brief Free
	Used by the system to free the child data

\ret void
*/
/******************************************************************************/
void SceneManager::Free()
{
	this->currentScene->Free();
}

/******************************************************************************/
/*!
\brief Unload
	Used by the system to unload the child scene

\ret void
*/
/******************************************************************************/
void SceneManager::Unload()
{
	this->currentScene->Unload();
}

/******************************************************************************/
/*!
\brief SetIfPause
	Set if the scene pauses
	Mainly used for the game scene

\param IfPause
	Set if pause the scene

\ret void
*/
/******************************************************************************/
void SceneManager::SetIfPause(bool IfPause)
{
	ifPause = IfPause;
}

/******************************************************************************/
/*!
\brief GetIfPause
	Get if current scene is paused
	Mainly used for the game scene

\ret void
*/
/******************************************************************************/
bool SceneManager::GetIfPause()
{
	return ifPause;
}