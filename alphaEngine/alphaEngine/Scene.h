#pragma once
#include "AEEngine.h"
#include <iostream>

class Scene
{
public:
	/******************************************************************************/
	/*!
	\brief Scene
		Constructor
	
	*/
	/******************************************************************************/
	Scene() {};
	/******************************************************************************/
	/*!
	\brief ~Scene
		virtual destructor
	
	*/
	/******************************************************************************/
	virtual ~Scene() {};

	/******************************************************************************/
	/*!
	\brief Load
		The intermediate function to call the child's load function by the scene
		manager
	
	\ret void
	*/
	/******************************************************************************/
	virtual void Load(void) = 0;
	/******************************************************************************/
	/*!
	\brief Init
		The intermediate function to call the child's init function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	virtual void InitScene(void) = 0;
	/******************************************************************************/
	/*!
	\brief Update
		The intermediate function to call the child's update function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	virtual void Update(float dt) = 0;
	/******************************************************************************/
	/*!
	\brief Draw
		The intermediate function to call the child's draw function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	virtual void Draw(void) = 0;
	/******************************************************************************/
	/*!
	\brief Free
		The intermediate function to call the child's free function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	virtual void Free(void) = 0;
	/******************************************************************************/
	/*!
	\brief Unload
		The intermediate function to call the child's unload function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	virtual void Unload(void) = 0;
	
	
private:
	
};


