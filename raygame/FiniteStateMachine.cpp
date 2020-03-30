#include "FiniteStateMachine.h"
#include "State.h"
#include "Transition.h"
#include "Condition.h"

FiniteStateMachine::~FiniteStateMachine()
{
	
		for (auto state : m_states)
		{
			delete state;
		}
		for (auto t : m_transitions)
		{
			delete t;
		}
		for (auto c : m_conditions)
		{
			delete c;
		}
	
}

Vector2 FiniteStateMachine::update(Agent * agent, float deltaTime)
{
	if (m_currentState == nullptr)
	{
		return Vector2{ 0.0f, 0.0f };
	}
	Transition* transition = m_currentState->getTriggeredTransition(agent);
	if (transition != nullptr)
	{
		m_currentState->exit(agent);
		m_currentState = transition->getTargetState();
		m_currentState->init(agent);
	}
	m_currentState->update(agent, deltaTime);
	return Vector2{ 0.0f, 0.0f };
}
