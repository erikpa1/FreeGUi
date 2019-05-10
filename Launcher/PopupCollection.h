#pragma once
#include "ObjectShell.h"
#include "GuiElement.h"
#include "Sp.h"
#include "AppWindow.h"

class PopupCollection : public ObjectShell
{

public:

	PopupCollection();
	~PopupCollection();

	virtual void ShowBlocking();
	virtual void ShowNonBlocking();

private:
		

};

