/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "Behavior.h"
#include "KeyboardBehavior.h"
#include "ScreenEdgeBehavior.h"
#include "FiniteStateMachine.h"
#include "IdleState.h"
#include "WithinRangeCondition.h"
#include "EnemyAttackState.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	//Create the player
	Agent* player = new Agent();
	player->setPosition({ 800.0f, 450.0f });
	player->setSpeed(500.0f);
	player->setColor(SKYBLUE);

	//Create and add keyboard behavior
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addBehavior(keyboardBehavior);

	//Create and add the screen behavior
	ScreenEdgeBehavior* screenEdgeBehavior = new ScreenEdgeBehavior();
	player->addBehavior(screenEdgeBehavior);

	//Create the enemy
	Agent* enemy = new Agent();
	enemy->setPosition(Vector2{ 400.0f, 225.0f });
	enemy->setSpeed(250.0f);
	enemy->setColor(MAROON);

	//Create the SFM
	FiniteStateMachine* enemyFSM = new FiniteStateMachine();
	enemy->addBehavior(enemyFSM);

	//Create and add the states
	IdleState* idleState = new IdleState();
	enemyFSM->addState(idleState);
	EnemyAttackState* attackState = new EnemyAttackState(player, 250.0f);
	enemyFSM->addState(attackState);
	//Create and add the condition
	Condition* withinRangeCondition = new WithinRangeCondition(player, 200.0f);
	enemyFSM->addCondition(withinRangeCondition);
	//Create and add the transition
	Transition* toAttackTransition = new Transition(attackState, withinRangeCondition);
	enemyFSM->addTransition(toAttackTransition);
	idleState->addTransition(toAttackTransition);
	//Set current state to idle
	enemyFSM->setCurrentState(idleState);




	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();
		player->update(deltaTime);
		enemy->update(deltaTime);
		
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		player->draw();
		enemy->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}