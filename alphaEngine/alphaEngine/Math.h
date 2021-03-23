#pragma once
#include <AEMath.h>
namespace Math
{
	template <typename T>
	T Lerp(const T& a, const T& b, float t)
	{
		return a + t * (b - a);
	}
	template <typename T>
	inline T Clamp(const T& value,const  T & min,const T & max)
	{
		return (value < min) ? min : (max < value) ? max : value; 
	}

	int RandomInt(int min, int max);

	float RandomFloat(float a, float b);
}

 AEVec2 operator+ (const AEVec2& , const AEVec2&);
 AEVec2 operator- (const AEVec2&, const AEVec2&);
 AEVec2 operator+= (AEVec2&,const  AEVec2&);
 float operator* (const AEVec2&, const AEVec2&);
 AEVec2 operator* (const AEVec2&, float);

