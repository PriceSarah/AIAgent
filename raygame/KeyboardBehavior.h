#pragma once
#include "Behavior.h"

class KeyboardBehavior : public Behavior
{

public:
	KeyboardBehavior() {}
	virtual ~KeyboardBehavior() {}

	virtual Vector2 Update(Agent* agent, float deltaTime);
};

