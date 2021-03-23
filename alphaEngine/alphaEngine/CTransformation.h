/* Start Header ************************************************************************/
/*!
\file     CTransformation.h
\author   Winston Ho,ho.s
\par	 :ho.s\@digipen.edu
\date	 2018/01/15
\brief	  
this file has content the Transformation class that use mostly for drawing.

Copyright (C) 2018 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents
without the prior written consent of DigiPen Institute of
Technology is prohibited.
*/
/* End Header **************************************************************************/

#pragma once
#include "AEEngine.h"
#include <iostream>
#include <string.h>

class CTransformation
{
private:
	AEMtx33 mat;
public:
	CTransformation();

	void Translate(float x, float y);
	void RotInDeg(float deg);
	void Identity();
	void Scaling(float x, float y);
	void SetTransformationMatrix(AEMtx33 MAT);
	AEMtx33 * GetTransformationMatrix();

	~CTransformation();
	CTransformation operator *(CTransformation& rhs);
};

