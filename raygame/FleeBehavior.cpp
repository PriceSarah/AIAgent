#include "FleeBehavior.h"

Vector2 FleeBehavior::Update(Agent * agent, float deltaTime)
{
	if (agent == nullptr)
	{
		return Vector2{ 0, 0 };
	}

	Vector2 pos = agent->getPosition();

	Vector2 targetPos = m_target->getPosition();

	Vector2 direction = pos - targetPos;
	direction = direction.normalize();

	direction = direction * 100;

	Vector2 force = direction - agent->getVelocity();

	return force;
}
