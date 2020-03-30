#pragma once
#include "Behavior.h"
#include "State.h"
#include "Transition.h"
#include "Condition.h"

class FiniteStateMachine : public Behavior
{
public:

	FiniteStateMachine() : m_currentState(nullptr) {}
	virtual ~FiniteStateMachine();

	//Add components, takes ownership
	void addState(State* state) { m_states.push_back(state);  }
	void addTransition(Transition* transition) { m_transitions.push_back(transition);  }
	void addCondition(Condition* condition) { m_conditions.push_back(condition);  }

	void setCurrentState(State* state) { m_currentState = state; }
	virtual Vector2 update(Agent* agent, float deltaTime);

protected:

	std::vector<State*>		 m_states;
	std::vector<Transition*> m_transitions;
	std::vector<Condition*>	 m_conditions;
	State*					 m_currentState;

};

