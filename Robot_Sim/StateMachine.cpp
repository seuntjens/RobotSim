#include "stdafx.h"
#include "StateMachine.h"


StateMachine::StateMachine() :rightIsOpen(false), roadIsBlocked(true), leftIsOpen(false) //member initialization
{
}


StateMachine::~StateMachine()
{
}

void StateMachine::onUpdate(bool rightSensor, bool frontSensor, bool leftSensor){
	/*rightIsOpen=rightSensor;	
	roadIsBlocked=frontSensor;
	leftIsOpen=leftSensor*/
	Set_Next_State();
}

void StateMachine::Set_Next_State(){//Priority is to always go right if possible. States are called in this order
	if (rightIsOpen){
		TurnRight t_right;
		t_right.Handle_Motor(rightMotor, leftMotor);
	}
	else if (!roadIsBlocked){
		Forward forward;
		forward.Handle_Motor(rightMotor, leftMotor);
	}
	else if (leftIsOpen){
		TurnLeft t_left;
		t_left.Handle_Motor(rightMotor, leftMotor);
	}
	else if (!rightIsOpen && roadIsBlocked && !leftIsOpen){//Turn right if there is no possible way to go.
		TurnRight t_right;
		t_right.Handle_Motor(rightMotor, leftMotor);
	}
}