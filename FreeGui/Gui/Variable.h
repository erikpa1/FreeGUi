#pragma once
#include "ObjectShell.h"

class EXPORT Variable : public ObjectShell
{
public:	
};

class Int4 : public Variable
{
public:

	Int4(int x, int y, int z, int w);

	int _x = 0;
	int _y = 0;
	int _z = 0;
	int _w = 0;

};
