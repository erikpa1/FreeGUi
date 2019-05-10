#pragma once

#include "AppWindow.h"
#include "LinearLayout.h"
#include "Buton.h"
#include "HBox.h"
#include "GuiItem.h"
#include "../FreeGui/World.h"


#define MENU_BUTTON_SIZE_Y 50

class LauncherWindow
{

public:

	LauncherWindow();
	~LauncherWindow();

	void Start();


private:

	AppWindow * _window;
	HBox * _buttonLayout;
	LinearLayout * _views;
	GuiItem * _actualGui;	
	vector<Buton*> _menuButtons;

		
	void InitButtons();
	void InitWindow();
};

