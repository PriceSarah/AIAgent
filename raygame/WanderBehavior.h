#pragma once
#include "Behavior.h"
class WanderBehavior : public Behavior
{
public:
	WanderBehavior() {}
	virtual ~WanderBehavior() {}
	virtual Vector2 Update(Agent* agent, float deltaTime);

private:
	float m_radius = 1;
	float m_distance = 0;
	float m_jitter = 0;
	Vector2 m_prevTarget = { 0, 0 };
};

