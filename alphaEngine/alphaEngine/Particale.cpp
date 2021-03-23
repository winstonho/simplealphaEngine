#include "Particale.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>


#define GETVarName(name) GetName(#name)


std::string GetName(std::string name)
{
	auto id = name.find(".");
	if (id != std::string::npos)
	{
		name.erase(name.begin(), name.begin() + id + 1);
	}
	return std::move(name) + ":";
}

void CircleEmitter::Init()
{
	m_particleBuffer.resize(m_maxParticle);
	for (unsigned int i = 0; i < m_maxParticle; i++) {
		m_particleBuffer[i].m_fLifeTime = -1.0f;
	}
}



void CircleEmitter::Update(float dt)
{

	int count = 0;

	for (unsigned int i = 0; i < lastUsedParticle; ++i)
	{
		auto& particle = m_particleBuffer[i];

		if (m_particleBuffer[i].GetActive())
		{

			particle.m_fAge += dt;
			float lifeRatio = Math::Clamp(particle.m_fAge / particle.m_fLifeTime, 0.0f, 1.0f);


			particle.m_Position += particle.m_Velocity * dt;
			particle.m_fSize = GetValue(this->sizeEffect, setting.m_minSize, particle.m_finalSize, lifeRatio);

			switch (this->colourEffect)
			{
			case EFFECT::FADEIN:
				particle.m_Color = setting.m_colourStart + (setting.m_colourEnd - setting.m_colourStart) * lifeRatio;
				break;
			case EFFECT::FADEOUT:
				particle.m_Color = setting.m_colourEnd + (setting.m_colourStart - setting.m_colourEnd) * lifeRatio;
				break;
			}


			if (particle.m_fAge > particle.m_fLifeTime)
			{
				particle.SetActive(false);
				--lastUsedParticle;
			}
		}

	}
	std::sort(m_particleBuffer.begin(), m_particleBuffer.end());
}





void CircleEmitter::EmitParticle(const AEVec2& pos, bool random)
{
	if (lastUsedParticle < m_maxParticle)
	{

		if (!m_particleBuffer[lastUsedParticle].GetActive())
		{
			AEVec2 spawnDir;

			float angle = Math::RandomFloat(m_minAngleInDeg, this->m_maxAngleInDeg);
			//std::cout << angle << std::endl;
			spawnDir.x = cosf(AEDegToRad(angle));
			spawnDir.y = sinf(AEDegToRad(angle));

			m_particleBuffer[lastUsedParticle].SetActive(true);
			m_particleBuffer[lastUsedParticle].m_fAge = 0.0f;
			m_particleBuffer[lastUsedParticle].m_fLifeTime = Math::RandomFloat(setting.m_minlifeTime, setting.m_maxlifeTime);


			m_particleBuffer[lastUsedParticle].m_finalSize = m_particleBuffer[lastUsedParticle].m_fSize = Math::RandomFloat(setting.m_minSize, setting.m_maxSize);
			m_particleBuffer[lastUsedParticle].m_Position = pos + spawnDir * Math::RandomFloat(m_minRadius, m_maxRadius);
			if (random)
			{
				m_particleBuffer[lastUsedParticle].m_Velocity = RandomVelocity() * Math::RandomFloat(setting.m_minSpeed, setting.m_maxSpeed);
			}
			else
			{
				AEVec2 dir = pos - m_particleBuffer[lastUsedParticle].m_Position;
				AEVec2Normalize(&dir, &dir);
				m_particleBuffer[lastUsedParticle].m_Velocity = dir * Math::RandomFloat(setting.m_minSpeed, setting.m_maxSpeed);
			}



			m_particleBuffer[lastUsedParticle].m_Color = setting.m_colourStart;
			++lastUsedParticle;
		}
		else
		{
			std::cout << "error in creating go and look at your sort algo" << std::endl;
		}
	}
}



AEVec2 CircleEmitter::RandomVelocity()
{
	AEVec2 temp;

	float angle = Math::RandomFloat(setting.mindirInDegree, setting.maxdirInDegree);
	//std::cout << angle << std::endl;
	temp.x = cosf(AEDegToRad(angle));
	temp.y = sinf(AEDegToRad(angle));

	return temp;
}

const ParticleBuffer& CircleEmitter::GetParticaleBuffer() const
{
	return m_particleBuffer;
}

const unsigned int CircleEmitter::GetNumberOFActiveParticale() const
{
	return lastUsedParticle;
}

void CircleEmitter::SetMaxParticale(unsigned int newsize)
{
	this->m_maxParticle = newsize;
}

unsigned int CircleEmitter::GetMaxParticale() const
{
	return  this->m_maxParticle;
}



float CircleEmitter::GetValue(EFFECT effect, float startValue, float maxValue, float ratio)
{
	switch (effect)
	{
	case EFFECT::FADEIN:
		return Math::Lerp(startValue, maxValue, ratio);
		break;
	case EFFECT::FADEOUT:
		return Math::Lerp(maxValue, startValue, ratio);
		break;
	}

	return maxValue;
}


void Particle::SetActive(bool active)
{
	m_active = active;
	m_Color.SetA(active ? m_Color.GetA() : 0.0f);
	m_fSize = active ? m_fSize : 0.0f;
	m_finalSize = active ? m_finalSize : 0.0f;
}

bool Particle::GetActive()
{
	return m_active;
}

bool Particle::operator<(Particle& rhs)
{
	if (this->m_active == rhs.m_active && this->m_active == true)
	{
		return m_fAge > rhs.m_fAge;
	}
	else
	{
		return this->m_active;
	}
}

void CircleEmitter::SaveSetting(const std::string& name)
{
	std::ofstream NewData;
	NewData.open(name, std::ios::trunc);

	NewData << GETVarName(setting.mindirInDegree) << setting.mindirInDegree << std::endl;
	NewData << GETVarName(setting.maxdirInDegree) << setting.maxdirInDegree << std::endl;

	NewData << GETVarName(setting.m_minSize) << setting.m_minSize << std::endl;
	NewData << GETVarName(setting.m_maxSize) << setting.m_maxSize << std::endl;

	NewData << GETVarName(setting.m_minlifeTime) << setting.m_minlifeTime << std::endl;
	NewData << GETVarName(setting.m_maxlifeTime) << setting.m_maxlifeTime << std::endl;

	NewData << GETVarName(setting.m_minSpeed) << setting.m_minSpeed << std::endl;
	NewData << GETVarName(setting.m_maxSpeed) << setting.m_maxSpeed << std::endl;

	NewData << GETVarName(m_minRadius) << m_minRadius << std::endl;
	NewData << GETVarName(m_maxRadius) << m_maxRadius << std::endl;

	NewData << GETVarName(m_minAngleInDeg) << m_minAngleInDeg << std::endl;
	NewData << GETVarName(m_maxAngleInDeg) << m_maxAngleInDeg << std::endl;
	NewData << GETVarName(m_maxParticle) << m_maxParticle << std::endl;

	//std::cout << m_maxParticle << std::endl;
	//v = &m_maxParticle;

	//*std::get<unsigned int *>(v) = 10;
	//std::cout << m_maxParticle << std::endl;

	NewData.close();

}

void CircleEmitter::LoadSetting(const std::string& name)
{
	std::ifstream file(name.c_str());
	if (file.is_open())
	{
		std::string aLineOfText = "";
		std::istringstream iss(aLineOfText);

		
		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss  >> setting.mindirInDegree;
		
		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> setting.maxdirInDegree;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >>  setting.m_minSize;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> setting.m_maxSize;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >>  setting.m_minlifeTime;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> setting.m_maxlifeTime;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> setting.m_minSpeed;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> setting.m_maxSpeed;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> m_minRadius;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> m_maxRadius;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> m_minAngleInDeg;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> m_maxAngleInDeg;

		std::getline(file, aLineOfText);
		iss = std::move(std::istringstream{ aLineOfText.substr(aLineOfText.find(":") + 1) });
		iss >> m_maxParticle;
	
	}
	//perFrameTime_ = maxTime_ / (float)spriteList.size();
	//std::cout << maxTime_;
	file.close();
}


void CircleEmitter::SaveSetting2(const std::string& name)
{

	//unlike SaveSeeting we can't order how we save the data if we using unordermap.
	//try change to std::map and see got any differnt in your txt file;
	std::ofstream NewData;
	NewData.open(name, std::ios::trunc);
	std::variant < std::ostream*> temp = &NewData;
	for ( auto& elem : meamberVarPtrList)
	{
		NewData << elem.first;
		std::visit( [](auto  arg,auto temp) {*temp << *arg << std::endl; }, elem.second, temp);
	}
	NewData.close();
}

void CircleEmitter::LoadSetting2(const std::string& name)
{
	//unlike LoadSetting2 first we no need to care the order on how we save the data
	std::ifstream file(name.c_str());
	if (file.is_open())
	{

		std::string aLineOfText = "";
		std::istringstream iss(aLineOfText);

		//yet we shorthen the code 
		while (!file.eof())
		{
			std::getline(file, aLineOfText);
			auto index = aLineOfText.find(":") + 1;
			iss = std::move(std::istringstream{ aLineOfText.substr(index) });


			//sadly std::vist only take in std::variant so we just enclose on iss into a varient
			std::variant <std::istringstream*> temp = &iss;
			
			auto itor = meamberVarPtrList.find(aLineOfText.substr(0, index));
			if (itor != meamberVarPtrList.end())
			{
				std::visit([](auto  arg, auto temp) {*temp >> *arg; }, itor->second, temp);
			}
		}
	}

}



CircleEmitter::CircleEmitter()
	:lastUsedParticle{0},m_maxParticle{0},m_maxRadius{0},m_minRadius{0},
	 m_minAngleInDeg{ 0 }, m_maxAngleInDeg{ 0 }, m_particleBuffer{},
	sizeEffect {EFFECT::FADEIN}, colourEffect{ EFFECT::FADEIN },emiteTime{0.0f}
{
	//here i set up using a unorder map to use to store the a ptr to data.
	//this we do a fake refelction system !!
	//but it will help us to use to solve the problem where 
	//we load the data the order must be same as the save data!!
	meamberVarPtrList[GETVarName(setting.mindirInDegree)] = &setting.mindirInDegree;
	meamberVarPtrList[GETVarName(setting.maxdirInDegree)] = &setting.maxdirInDegree;

	meamberVarPtrList[GETVarName(setting.m_minSize)] = &setting.m_minSize;
	meamberVarPtrList[GETVarName(setting.m_maxSize)] = &setting.m_maxSize;

	meamberVarPtrList[GETVarName(setting.m_minlifeTime)] = &setting.m_minlifeTime;
	meamberVarPtrList[GETVarName(setting.m_maxlifeTime)] = &setting.m_maxlifeTime;

	meamberVarPtrList[GETVarName(setting.m_minSpeed)] = &setting.m_minSpeed;
	meamberVarPtrList[GETVarName(setting.m_maxSpeed)] = &setting.m_maxSpeed;

	meamberVarPtrList[GETVarName(m_minRadius)] = &m_minRadius;
	meamberVarPtrList[GETVarName(m_maxRadius)] = &m_maxRadius;

	meamberVarPtrList[GETVarName(m_minAngleInDeg)] = &m_minAngleInDeg;
	meamberVarPtrList[GETVarName(m_maxAngleInDeg)] = &m_maxAngleInDeg;
	meamberVarPtrList[GETVarName(m_maxParticle)] = &m_maxParticle;



}
