#include "stdafx.h"
#include "ObjectShell.h"


using namespace std;
using namespace chrono;

static int numberOfMe = 0;



inline ObjectShell::ObjectShell()
{
	numberOfMe++;	
}


ObjectShell::~ObjectShell()
{
	numberOfMe--;
	//cout << ODDELOVAC << "Destruction of object: " << _ID << endl;
}

void ObjectShell::decrement()
{
	_references--;
	if (_references == 0)
	{		
		delete this;		
	}
}

std::string ObjectShell::ToString()
{
	return "";
}

void ObjectShell::saveMySelf(ofstream& stream)
{
	   
}

void ObjectShell::loadMySelf(ifstream& stream)
{

}


int ObjectShell::generateUniqueID(string ID)
{
	string help = ID;
	transform(help.begin(), help.end(), help.begin(), ::toupper);
	int helpID = 0;

	for (auto i = 0; i < ID.size(); i++)
	{
		int a =
			helpID += help.at(i)*(i + 1);
	}

	return helpID;
}

int ObjectShell::getNumberOfMe()
{
	return numberOfMe;
}

bool ObjectShell::operator==(const ObjectShell& shell)
{

	//cout << ODDELOVAC << "Called dvojite rovnasa" << endl;
	return _ID == shell._ID;

}

void ObjectShell::posthumousVoice(string voice)
{
	//cout << ODDELOVAC << _ID << " deletes also " << voice << endl;
}


void ObjectShell::increment()
{
	_references++;
}


