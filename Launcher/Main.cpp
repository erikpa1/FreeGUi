#pragma once



#include "Application.h";
#include "LoginGui.h"

int main(int argc, char *argv[])
{
	try
	{
		LoginGui loginGui;
		loginGui.ShowBlocking();	

		
	} catch(exception e)
	{
		cerr << e.what() << endl;
	}
	

}