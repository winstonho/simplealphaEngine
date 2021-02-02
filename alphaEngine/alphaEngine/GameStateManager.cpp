/* Start Header ************************************************************************/
/*!
\file     GameStateManager.cpp
\author   Tan De Bin, debin.tan, 390004917
\par	  debin.tan\@digipen.edu
\date	  Jan 23, 2018
\course	  GAM150 (The Magic Moment)
\brief	  This file contains the functions for the Game States

Copyright (C) 2018 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents
without the prior written consent of DigiPen Institute of
Technology is prohibited.
*/
/* End Header **************************************************************************/
#include "GameStateManager.h"



/******************************************************************************/
/*!
\brief GSM
	Constructor

*/
/******************************************************************************/
GSM::GSM()
{
	// set default game state
	current = previous = next = GS_STATES::GS_NULL;
	
}



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
void GSM::GSM_Initialize(GS_STATES startingState)
{
	// initialize the variables
	current = previous = next = startingState; 

}

/******************************************************************************/
/*!
\brief SetCurrentState
	Set the current state of the game

\param state
	The state to set to

\ret void
*/
/******************************************************************************/
void GSM::SetCurrentState(GS_STATES state)
{
	current = state;
}

/******************************************************************************/
/*!
\brief SetPreviousState
	Set the previous state of the game

\param state
	The state to set to

\ret void
*/
/******************************************************************************/
void GSM::SetPreviousState(GS_STATES state)
{
	previous = state;
}

/******************************************************************************/
/*!
\brief SetNextState
	Set the next state of the game

\param state
	The state to set to

\ret void
*/
/******************************************************************************/
void GSM::SetNextState(GS_STATES state)
{
	next = state;
}

/******************************************************************************/
/*!
\brief GetCurrentState
	Get the state currently in

\ret int
*/
/******************************************************************************/
GS_STATES GSM::GetCurrentState(void)
{
	return current;
}

/******************************************************************************/
/*!
\brief GetPreviousState
	Get the state previously in

\ret int
*/
/******************************************************************************/
GS_STATES GSM::GetPreviousState(void)
{
	return previous;
}

/******************************************************************************/
/*!
\brief GetNextState
	Get the state the game changing to

\ret int
*/
/******************************************************************************/
GS_STATES GSM::GetNextState(void)
{
	return next;
}
