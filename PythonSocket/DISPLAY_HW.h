#pragma once

#include "./../server/AtomicStandardOutput.h"
#include "./../server/Entity.h"
#include "./../server/System.h"
#include "./../server/SafeQueue.h"
#include "client.cpp"
//NOTE: more #includes for added-in libraries go here

class DISPLAY_HW : public System
{
private:
	AtomicStandardOutput* atomicOutput;
	//OPTIONAL:
	string customVARIABLE;
	BTHWL interface;

public:
	DISPLAY_HW();
	void init();
	void update();
	void CUSTOM_FUNCTION(float &PARAM_1, float &PARAM_2);
	void get_data();
};
