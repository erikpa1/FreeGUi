#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

void Object::DecreasePointerNumber()
{
	_pointerCounter--;

	if (_pointerCounter == 0)
	{
		delete this;
	}
}

void Object::IncreasePointerNumber()
{
	_pointerCounter++;
}
