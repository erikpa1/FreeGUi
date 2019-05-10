#pragma once
#include "Gui/GuiElement.h"

class EXPORT Fragment
{
	virtual GuiElement * getButtonRepresentation() = 0;
	virtual GuiElement * getGetWindowRepresentation() = 0;

};
