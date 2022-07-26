#ifndef _ADD_NAND_GATE_H
#define _ADD_NAND_GATE_H

#include "action.h"
#include "..\Components\NAND.h"
class ADDNANDgate2:public Action
{
	private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
public:
	ADDNANDgate2(ApplicationManager *pApp);
	~ADDNANDgate2(void);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif

