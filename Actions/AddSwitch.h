#pragma once
#ifndef _ADD_SWITCH_H
#define _ADD_SWITCH_H

#include "action.h"
#include "..\Components\Switch.h"

class AddSwitch :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the LED
	int Cx, Cy;	//Center point of the SWITCH
public:
	 AddSwitch (ApplicationManager *pApp);
	virtual ~ AddSwitch (void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};

#endif