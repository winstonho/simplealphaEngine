#pragma once
#include <AEEngine.h>
#include "CTransformation.h"
#include "CColour.h"
struct  GameObject
{
		CTransformation transform;
		CColour colour;
		AEVec2 pos;
		AEVec2 scale;
		float deg;
};

