#pragma once
#include "GuiElement.h"

class EXPORT Fragment
{
	virtual GuiElement * getButtonRepresentation() = 0;
	virtual GuiElement * getGetWindowRepresentation() = 0;

};
