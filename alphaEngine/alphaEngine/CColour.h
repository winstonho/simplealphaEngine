/* Start Header ************************************************************************/
/*!
\file     CColour.h
\author   Winston Ho,ho.s
\par	 :ho.s\@digipen.edu
\date	  2018/01/12 
\brief	  This file is contain the CColour class

Copyright (C) 2018 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents
without the prior written consent of DigiPen Institute of
Technology is prohibited.
*/
/* End Header **************************************************************************/

#pragma once
class CColour
{
private:
	float r_;//red
	float g_;//blue
	float b_;//green
	float a_;//alpha
public:
	CColour();
	CColour(float r, float g,float b,float a);
	CColour(float const (&colour)[4]);
	float GetR() const;
	float GetG()const;
	float GetB()const;
	float GetA()const;

	void SetR(float r);
	void SetG(float g);
	void SetB(float b);
	void SetA(float a);

	void SetRGBA(float r,float g,float b,float a);
	~CColour();

	CColour operator+ (const CColour& colour);
	CColour operator- (const CColour& colour);
	CColour operator* (const float);
};

