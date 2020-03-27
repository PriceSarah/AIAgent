#pragma once
#include "Behavior.h"
class State;
class Transition;
class Condition;

class FiniteStateMachine : public Behavior
{
public:

	FiniteStateMachine() : m_currentState(nullptr) {}

	virtual ~FiniteStateMachine() {
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

	//Add components, takes ownership
	State* addState(State* state) { m_states.push_back(state); return state; }
	Transition* addTransition(Transition* transition) { m_transitions.push_back(transition); return transition; }
	Condition* addCondition(Condition* condition) { m_conditions.push_back(condition); return condition; }

	bool execute(Agent* aagent, float deltaTime);

protected:

	std::vector<State*>		 m_states;
	std::vector<Transition*> m_transitions;
	std::vector<Condition*>	 m_conditions;
	State*					 m_currentState;

};

