/* Start Header ************************************************************************/
/*!
\file     CTransformation.cpp
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

#include "CTransformation.h"

CTransformation::CTransformation()
{
	AEMtx33Identity(&this->mat);
}

void CTransformation::SetTransformationMatrix(AEMtx33 Mat)
{
	this->mat = Mat;
}


void CTransformation::Translate(float x, float y)
{
	AEMtx33 mat1;
	AEMtx33Identity(&mat1);
	AEMtx33Trans(&mat1, x, y);
	
	AEMtx33Concat(&this->mat,  &mat1, &this->mat);
	
}

void CTransformation::RotInDeg(float deg)
{
	AEMtx33 mat1;
	AEMtx33Identity(&mat1);
	AEMtx33RotDeg(&mat1, deg);
	AEMtx33Concat(&this->mat, &mat1, &this->mat);

}

void CTransformation::Scaling(float x ,float y)
{
	AEMtx33 mat1;
	AEMtx33Identity(&mat1);
    AEMtx33Scale(&mat1, x,y);
	AEMtx33Concat(&this->mat, &mat1, &this->mat);

}

void CTransformation::Identity()
{
	AEMtx33Identity(&this->mat);
}

AEMtx33 *  CTransformation::GetTransformationMatrix()
{
	return &this->mat;
}


CTransformation::~CTransformation()
{
}
