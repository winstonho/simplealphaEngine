#pragma once
/* Start Header ************************************************************************/
/*!
\file     engine.h
\author   winston ho, ho.s, 
\date	  2021/02/1
\brief	  This file contain the game engine please do look up what a singleton desgin.


Copyright (C) 2018 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents
without the prior written consent of DigiPen Institute of
Technology is prohibited.
*/
/* End Header **************************************************************************/
#include "AEEngine.h"
#include "GameStateList.h"
#include "GameStateManager.h"
#include "SceneManager.h"

class Engine
{
public:
	GSM gsm;
	/******************************************************************************/
	/*!
	\brief 
		Get the instance of this class

	\ret Engine &
	*/
	/******************************************************************************/
	static Engine & GetInstance();

	/******************************************************************************/
	/*!
	\brief 
		Init the engine 

		\ret void
	*/
	/******************************************************************************/
	void InitScene(HINSTANCE hAppInstance, s32 show, s32 WinWidth, s32 WinHeight, s32 CreateConsole, const s8* pTitle);
	/******************************************************************************/
	/*!
	\brief 
		Load the engine(yopu might want to load all your font here)

		\ret void
	*/
	/******************************************************************************/
	void Load();
	/******************************************************************************/
	/*!
	\brief Update:
		main game loop should be in here

		\ret void
	*/
	/******************************************************************************/
	void Update();
	/******************************************************************************/
	/*!
	\brief Destory
		unload all your stuff;

		\ret void
	*/
	/******************************************************************************/
	void Destory();

	~Engine();
	
	//HomeWork try change it sure that you have a emun for differnt font type
	//and a class to create / store / destory /get the font.
	int GetFontID();
private:
	//for a singleton we would like to private the constructor so that no one able to 
	//create a engine instance but force to call our GetInstance function to get the engine.
	Engine();
	SceneManager sceneManager;
	int fontID;
};

