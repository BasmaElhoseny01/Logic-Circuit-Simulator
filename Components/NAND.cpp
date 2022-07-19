#include "NAND.h"
#include "..\ApplicationManager.h"

NAND::NAND(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND::Operate()
{
	//caclulate the output status as the NANDing of the two input pins

	for(int i=0;i<m_Inputs;i++)
	{
		if(m_InputPins[i].getStatus()==LOW)
		{
			m_OutputPin.setStatus(HIGH);
			break;
		}
	}

	int n=0;
	for(int i=0;i<m_Inputs;i++)
	{
		if(m_InputPins[i].getStatus()==HIGH)
		{
			n++;
		}
	}
	if(n==m_Inputs)
	{
		m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws 2-input NAND gate
void NAND::Draw(Output* pOut,bool select)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo,select);
	pOut->DrawLabel( getstr(),m_GfxInfo.x1,m_GfxInfo.y1);
}
//make copy
Component*NAND::getcopy( )
{
	NAND *pA=new NAND(m_GfxInfo,AND2_FANOUT); 
	return pA;
}
//returns status of outputpin
int NAND::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
void NAND::Save(ofstream &x, int y, int z, int k)
{
	x << "NAND" << "\t" << ID << "\t";
	if (getstr() == "")
		x << "NOLABEL";
	else x << getstr();
	x<< "\t" << getm_GfxInfo().x1 << "\t" << getm_GfxInfo().y1 << endl;
}
void NAND::Load(ifstream&p,ApplicationManager*pa)
{
	int  x, y,z;
	string lab;
	p >> z>>lab >> x >> y;
	setid(z);
	m_GfxInfo.x1 = x;
	m_GfxInfo.y1 = y;
	m_GfxInfo.x2 = x + UI.AND2_Width;
	m_GfxInfo.y2 = y + UI.AND2_Height;
	if (lab == "NOLABEL")
		setstr("");
	else
		setstr(lab);
	pa->AddComponent(this);
}
