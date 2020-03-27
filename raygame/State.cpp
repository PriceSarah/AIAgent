#include "State.h"
#include "Transition.h"
#include"Agent.h"

Transition* State::getTriggeredTransition(Agent * agent)
{
	for (auto transition : m_transitions) 
	{
		if (transition->hasTriggered(agent))
			return transition; 
	}
	return nullptr;
}
