#include "WithinRangeCondition.h"

bool WithinRangeCondition::test(Agent * agent) const
{
	//Get the target position
	Vector2 targetPos = m_target->getPosition();
	//get this agents position
	Vector2 pos = agent->getPosition();
	//find the distance
	float distance = (targetPos - pos).magnitude();
	//return the restult
	return distance <= m_range;
}
