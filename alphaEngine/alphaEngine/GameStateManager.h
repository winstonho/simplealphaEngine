#pragma once
#include "GameStateList.h"

class GSM
{
public:


	GSM();

	/******************************************************************************/
	/*!
	\brief GSM_Initialize
		This function initializes the game state manager
		It should be called once after the system is initialized

	\param startingState
		The state to start with
	
	\ret void
	*/
	/******************************************************************************/
	void GSM_Initialize(GS_STATES startingState);



	/******************************************************************************/
	/*!
	\brief SetCurrentState
		Set the current state of the game
	
	\param state
		The state to set to
	
	\ret void
	*/
	/******************************************************************************/
	void SetCurrentState(GS_STATES state);
	/******************************************************************************/
	/*!
	\brief SetPreviousState
		Set the previous state of the game

	\param state
		The state to set to

	\ret void
	*/
	/******************************************************************************/
	void SetPreviousState(GS_STATES state);
	/******************************************************************************/
	/*!
	\brief SetNextState
		Set the next state of the game

	\param state
		The state to set to

	\ret void
	*/
	/******************************************************************************/
	void SetNextState(GS_STATES state);

	/******************************************************************************/
	/*!
	\brief GetCurrentState
		Get the state currently in
	
	\ret int
	*/
	/******************************************************************************/
	GS_STATES GetCurrentState(void);
	/******************************************************************************/
	/*!
	\brief GetPreviousState
		Get the state previously in

	\ret int
	*/
	/******************************************************************************/
	GS_STATES GetPreviousState(void);
	/******************************************************************************/
	/*!
	\brief GetNextState
		Get the state the game changing to

	\ret int
	*/
	/******************************************************************************/
	GS_STATES GetNextState(void);
	
private:
	GS_STATES current, previous, next; // keep track of the states
};
