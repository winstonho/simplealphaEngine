
#pragma once
#include "Scene.h"
#include "GameStateList.h"

class SceneManager
{
public:
	/******************************************************************************/
	/*!
	\brief SceneManager
		Constructor
	
	*/
	/******************************************************************************/
	SceneManager();
	/******************************************************************************/
	/*!
	\brief ~SceneManager
		Destructor
	
	*/
	/******************************************************************************/
	~SceneManager();

	/******************************************************************************/
	/*!
	\brief SetUp
		SetUp The SceneManager

	*/
	/******************************************************************************/
	void SetUp();

	/******************************************************************************/
	/*!
	\brief SetUp
		Render The Scene

	*/
	/******************************************************************************/
	void Render();

	
	/******************************************************************************/
	/*!
	\brief SetSceneID
		Set the id of new scene

	\param id
		Id of the new scene

	\ret void
	*/
	/******************************************************************************/
	void SetLevel(GS_STATES id);


	/******************************************************************************/
	/*!
	\brief Load
		Used by the system to load the child data
	
	\ret void
	*/
	/******************************************************************************/
	void Load();
	/******************************************************************************/
	/*!
	\brief Init
		Used by the system to initialize the child
	
	\ret void
	*/
	/******************************************************************************/
	void InitScene();
	/******************************************************************************/
	/*!
	\brief Update
		Used by the system to update the child datas
	
	\param dt
		The time for each frame
	
	\ret void
	*/
	/******************************************************************************/
	void Update(float dt);
	/******************************************************************************/
	/*!
	\brief Free
		Used by the system to free the child data
	
	\ret void
	*/
	/******************************************************************************/
	void Free();
	/******************************************************************************/
	/*!
	\brief Unload
		Used by the system to unload the child scene
	
	\ret void
	*/
	/******************************************************************************/
	void Unload();

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
	void SetIfPause(bool IfPause);
	/******************************************************************************/
	/*!
	\brief GetIfPause
		Get if current scene is paused
		Mainly used for the game scene

	\ret void
	*/
	/******************************************************************************/
	bool GetIfPause();
private:
	Scene * currentScene; // pointer to current scene
	bool ifPause; // stores if the current scene is paused
	GS_STATES sceneId; // current scene's id
	Scene* sceneArray[(unsigned long long)GS_STATES::GS_COUT];
};

