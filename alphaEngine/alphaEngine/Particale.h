#pragma once
#include <AEEngine.h>
#include "CColour.h"
#include <vector>
#include<string>
#include <variant>
#include <unordered_map>

enum class EFFECT : char
{
	 FADEIN = 0, 
	 FADEOUT, 
	 CONSTANT
};


struct Particle
{
	Particle()
		: m_Position{}
		, m_Velocity{}
		, m_Color{ 1.0f,1.0f,1.0f,1.0f }
		, m_fAge{ 0 }
		, m_fLifeTime{ 0 }
		, m_fSize{ 0 }
		, m_active{ false }
		, m_finalSize(1.0f)
	{}

	AEVec2   m_Position; // Center point of particle
	AEVec2   m_Velocity; // Current particle velocity
	CColour   m_Color;    // Particle color
	//float       m_fRotate;  // Rotate the particle the center
	float       m_fSize;    // Size of the particle
	float       m_fAge;
	float       m_fLifeTime;
	float       m_finalSize;

	void SetActive(bool active);
	bool GetActive();
	bool operator<(Particle& that);
private:
	bool m_active;
};

typedef std::vector<Particle> ParticleBuffer;
typedef std::variant<float*, unsigned int*> ClassMenberType;
typedef std::unordered_map<std::string, ClassMenberType> ReflectionList;

struct BasicEmitterSetting
{
	float m_maxSize;
	float m_minSize;

	float m_maxSpeed;
	float m_minSpeed;

	CColour m_colourStart;
	CColour m_colourEnd;

	float mindirInDegree;
	float maxdirInDegree;

	float m_maxlifeTime;
	float m_minlifeTime;
	friend std::ostream & operator<<(std::ostream& os, const BasicEmitterSetting& dt);
};

class CircleEmitter
{
public:

	void Init();
	void Update(float dt);
	void SaveSetting(const std::string& name);
	void LoadSetting(const std::string& name);

	//whenb random it false the velocity dir for particty will be pos - particale.startingPos 
	void EmitParticle(const AEVec2& pos,bool random = true);
	
	BasicEmitterSetting setting;
	

	float m_minRadius;
	float m_maxRadius;

	float m_minAngleInDeg;
	float m_maxAngleInDeg;

	
	float emiteTime;
	

	const ParticleBuffer& GetParticaleBuffer()const;
	const unsigned int GetNumberOFActiveParticale()const;

	void SetMaxParticale(unsigned int newsize);

	unsigned int GetMaxParticale()const;

	EFFECT sizeEffect;
	EFFECT colourEffect;

	//this one we not need to care about the order
	CircleEmitter();
	void SaveSetting2(const std::string& name);
	void LoadSetting2(const std::string& name);

private:
	unsigned int m_maxParticle;
	
	float GetValue(EFFECT effect, float min, float max, float ratio);
	AEVec2 RandomVelocity();
	
	unsigned int lastUsedParticle;
	ParticleBuffer m_particleBuffer;


	//using c++17 to help soft our save load inorder problem
	ReflectionList meamberVarPtrList;

};