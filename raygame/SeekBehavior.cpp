#include "SeekBehavior.h"


Vector2 SeekBehavior::Update(Agent * agent, float deltaTime)
{
	//If the target is null
		//Return a zero vector
	if (agent == nullptr)
	{
		return Vector2{ 0, 0 };
	}

	Vector2 pos = agent->getPosition();

	Vector2 targetPos = m_target->getPosition();

	Vector2 direction = targetPos - pos;
	direction = direction.normalize();

	direction = direction * 500;

	Vector2 force = direction - agent->getVelocity();

	return force;
	
}
