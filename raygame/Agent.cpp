#include "Agent.h"
#include "Behavior.h"

void Agent::update(float deltaTime)
{
	//Set total force to zero
	Vector2 totalForce = { 0, 0 };

	//For each behavior in the behavior list
	for (auto i = m_BehaviorList.begin(); i != m_BehaviorList.end(); i++)
	{
		//Call the behavior's update function
		Vector2 force = (*i)->Update(this, deltaTime);
		//Add the returned value to the total force
		totalForce += force;
	}

	//Add total force times delta time to velocity
	addForce(totalForce * deltaTime);
	//Add velocity times delta time to position
	m_Position += m_Velocity * deltaTime;
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 100.0f, 100.0f, GREEN);
}

void Agent::addBehavior(Behavior* behavior)
{
	//Add the behavior to the Behavior list
	m_BehaviorList.insert(m_BehaviorList.end(), behavior);
}

void Agent::addForce(Vector2 force)
{
	m_Velocity += force;
}

