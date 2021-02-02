/* Start Header ************************************************************************/
/*!
\file     CColour.cpp
\author   Winston Ho,ho.s
\par	 :ho.s\@digipen.edu
\date	  2018/01/12
\brief	  This file is contain the implementation CColour class

Copyright (C) 2018 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents
without the prior written consent of DigiPen Institute of
Technology is prohibited.
*/
/* End Header **************************************************************************/


#include "CColour.h"

CColour::CColour()
{
	this->r_ = 1.0f;
	this->g_ = 1.0f;
	this->b_ = 1.0f;
	this->a_ = 1.0f;
}
CColour::CColour(float r, float g, float b, float a)
{
	this->r_ = r;
	this->g_ = g;
	this->b_ = b;
	this->a_ = a;
}

CColour::CColour(float const(&colour)[4])
	: r_{ colour[0] }
	, g_{ colour[1] }
	, b_{ colour[2] }
	, a_{ colour[3] }
{
}

float CColour::GetR()
{
	return this->r_;
}

float CColour::GetG()
{
	return this->g_;
}

float CColour::GetB()
{
	return this->b_;
}

float CColour::GetA()
{
	return this->a_;
}

void CColour::SetR(float R)
{
	this->r_ = R;
}

void CColour::SetG(float G)
{
	this->g_ = G;
}

void CColour::SetB(float B)
{
	this->b_ = B;
}

void CColour::SetA(float A)
{
	this->a_ = A;
}


void CColour::SetRGBA(float r, float g, float b, float a)
{
	this->r_ = r;
	this->b_ = b;
	this->g_ = g;
	this->a_ = a;
}

CColour::~CColour()
{
}
