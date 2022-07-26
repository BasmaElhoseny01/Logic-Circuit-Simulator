#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* clipboard;
	int lastid; 

public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	void simulate();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	Component* findcom(GraphicsInfo GInfo);
	void deletecomp(Component *req);
	Component* getclipboard();
	void setclipboard(	Component* c);
	void Save(ofstream&);
	void Loadconnection(GraphicsInfo &, OutputPin*&, InputPin*&, int, int, int);
	void deleteall();
	void increaselastid();
	int getlastid();

	//destructor
	~ApplicationManager();
};

#endif