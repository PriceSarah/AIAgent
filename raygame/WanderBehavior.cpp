#include "WanderBehavior.h"

Vector2 WanderBehavior::Update(Agent * agent, float deltaTime)
{
	//Start with a random target on the edge of the sphere with a set radius around the agent
	float randRange = ((float)RAND_MAX) / 2;
	Vector2 targetPos = Vector2{ rand() - randRange, rand() - randRange }.normalize() * m_radius;
	//Add a randomized vector to the target with a magnituse specified by a jitter ammount
	targetPos += Vector2{ rand() - randRange, rand() - randRange }.normalize * m_jitter;
	//Bring the target back to the radius of the sphere by normalizing it and scaling by the radius
	targetPos = targetPos.normalize() * m_radius;
	//Add the agents heading, multiplied by the distance, to the target
	Vector2 heading = agent->getVelocity().normalize();
	targetPos += heading;

	
	Vector2 pos = agent->getPosition();


	Vector2 direction = targetPos - pos;
	direction = direction.normalize();

	direction = direction * 500;

	Vector2 force = direction - agent->getVelocity();

	return force;


	return Vector2();
}
