#pragma once
#include "GuiElement.h"

class Layout;

class GuiItem
{
public:

	virtual void BuildYourSelf(Layout & layout) = 0;
};
