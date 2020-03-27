#pragma once
#include "Behavior.h"

class Condition : public Behavior
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(Agent* agent) const = 0;

	virtual bool execute(Agent* agent, float deltaTime)
	{
		if (test(agent))
		{
			return true;
		}
		return false;
	}

};

