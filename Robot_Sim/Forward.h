#pragma once
#include "aState.h"
#include "Motor.h"
#include <iostream>

using namespace std;
class Forward :
	public aState
{
public:
	Forward();
	~Forward();

	void Handle_Motor(const Motor& rightMotor, const Motor& leftMotor);
};

