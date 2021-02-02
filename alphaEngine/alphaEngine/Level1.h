#pragma once
#include "Scene.h"
#include "GameObject.h"
class Level1 : public Scene
{
	public:
	/******************************************************************************/
	/*!
	\brief Load
		The intermediate function to call the child's load function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	void Load(void) override final;
	/******************************************************************************/
	/*!
	\brief Init
		The intermediate function to call the child's init function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	void InitScene(void)override final;

	/******************************************************************************/
	/*!
	\brief Update
		The intermediate function to call the child's update function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	void Update(float dt)override final;

	/******************************************************************************/
	/*!
	\brief Draw
		The intermediate function to call the child's draw function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	void Draw(void)override final;
	/******************************************************************************/
	/*!
	\brief Free
		The intermediate function to call the child's free function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	void Free(void)override final;
	/******************************************************************************/
	/*!
	\brief Unload
		The intermediate function to call the child's unload function by the scene
		manager

	\ret void
	*/
	/******************************************************************************/
	virtual void Unload(void)override final;
private:
	GameObject obj1;
	void CleanUp();
	AEGfxVertexList* pMesh1;
};

