#pragma once
#include "State.h"

class EnemyAttackState : public State
{
public:
	EnemyAttackState(Agent* target, float speed) : m_target(target), m_speed(speed){}
	virtual ~EnemyAttackState() {}
	virtual void update(Agent* agent, float deltaTime);

private:
	float m_speed;
	Agent* m_target;
};

