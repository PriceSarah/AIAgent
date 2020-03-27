#include "FiniteStateMachine.h"
#include "State.h"
#include "Transition.h"
#include "Condition.h"

bool FiniteStateMachine::execute(Agent * agent, float deltaTime)
{
	if (m_currentState != nullptr)
	{
		Transition* transition = m_currentState->getTriggeredTransition(agent);

		if (transition != nullptr)
		{
			m_currentState->exit(agent);
			m_currentState = transition->getTargetState();
			m_currentState->init(agent);
		}
		m_currentState->update(agent, deltaTime);
		return true;
	}
	return false;
	
}
