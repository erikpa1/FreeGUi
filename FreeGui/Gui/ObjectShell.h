#pragma once

#include "Definitions.h"

#include <random>
#include <chrono>
#include <string>
#include <fstream>
#include "algorithm"
#include <iostream>


#define ODDELOVAC "******"


class EXPORT ObjectShell
{
	
public:

	ObjectShell();		
	virtual ~ObjectShell();

	int getID() { return _ID;}	
	int getReferencesCount() { return _references; }		

	void setUniqueID(int ID);
	void setCategory(int category);
	void increment();
	void decrement();

	virtual std::string ToString();

	virtual void saveMySelf(std::ofstream & stream);
	virtual void loadMySelf(std::ifstream & stream);
	virtual void posthumousVoice(std::string voice = "");

	static int generateUniqueID(std::string ID);
	static int getNumberOfMe();

	bool operator==(const ObjectShell & shell);
	
	
private:	

	int _ID = 0;
	int _references = 0;
	


};






