#include "stdafx.h"
#include "TurnRight.h"


TurnRight::TurnRight()
{
}


TurnRight::~TurnRight()
{
}

void TurnRight::Handle_Motor(Motor& rightMotor, Motor& leftMotor){
	std::cout << "Turning right" << endl;
	rightMotor.setValue(1);
	leftMotor.setValue(-1);
}