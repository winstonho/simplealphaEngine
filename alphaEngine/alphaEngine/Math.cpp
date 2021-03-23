#include "Math.h"
#include <random>

static std::default_random_engine e;
 AEVec2 operator+(const AEVec2& left, const AEVec2& right)
{
	AEVec2 temp;
	temp.x = left.x + right.x;
	temp.y = left.y + right.y;
	return temp;
}

 AEVec2 operator-(const AEVec2& left, const AEVec2& right)
{
	AEVec2 temp;
	temp.x = left.x - right.x;
	temp.y = left.y - right.y;
	return temp;
}

 AEVec2 operator+=(AEVec2& left, const AEVec2& right)
{
	left.x = left.x + right.x;
	left.y = left.y + right.y;
	return left;
}



 float operator*(const AEVec2& left, const AEVec2& right)
{
	return right.x * left.x + right.y * left.y;
}

 AEVec2 operator*(const AEVec2& left, float right)
{
	AEVec2 temp;
	temp.x = left.x * right;
	temp.y = left.y * right;
	return temp;
}

int Math::RandomInt(int min, int max)
{
	std::uniform_int_distribution<> dis(min, max);
	return dis(e);
}

float Math::RandomFloat(float min, float max)
{

	
	std::uniform_real_distribution<float> dis(min, max);
	return dis(e);

}
