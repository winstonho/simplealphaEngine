/* Start Header ************************************************************************/
/*!
\file     GameStateList.h
\author   Tan De Bin, debin.tan, 390004917
\par	  debin.tan\@digipen.edu
\date	  Jan 23, 2018
\course	  GAM150 (The Magic Moment)
\brief	  This file contains the enums for the Game States

Copyright (C) 2018 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents
without the prior written consent of DigiPen Institute of
Technology is prohibited.
*/
/* End Header **************************************************************************/
#pragma once


enum class GS_STATES : unsigned long long
{
	
	GS_LEVEL1 = 0,
	GS_LEVEL2,
	GS_COUT,
	GS_QUIT,
	GS_RESTART,
	GS_NULL = 999999
};