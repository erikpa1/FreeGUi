#include "LauncherWindow.h"
#include "AccountGui.h"
#include "LinearLayout.h"
#include "HBox.h"
#include "AppWindow.h"

LauncherWindow::LauncherWindow()
{
	_window = new AppWindow(800, 600, "Ella launcher");
	_buttonLayout = new HBox(0, 0, _window->GetWindowDimensionX(), MENU_BUTTON_SIZE_Y);
	_buttonLayout->setGap(1);
	_buttonLayout->SetChildrenAutoScaleOn();
	_views = new LinearLayout(0, MENU_BUTTON_SIZE_Y + 2, _window->GetWindowDimensionX(), _window->GetWindowDimensionX() - MENU_BUTTON_SIZE_Y - 2);
	_views->setGap(2);	

	//this->InitButtons();
	//this->InitWindow();

	//for (auto temp : _menuButtons)
	//{
	//	_buttonLayout->AddElement(*temp);
	//}
	//_window->AddElement(_buttonLayout);

	_window->AddElement(new World(800, 600, 400, 400));
	
}

LauncherWindow::~LauncherWindow()
{
}

void LauncherWindow::Start()
{
	_window->IndependentStart();
}

void LauncherWindow::InitButtons()
{
	for (auto i = 0; i < 5; i++)
	{
		_menuButtons.push_back(new Buton(0, 0, 0, 0));
	}

	_menuButtons[0]->SetText("Account");
	_menuButtons[1]->SetText("Download");
	_menuButtons[2]->SetText("Modules");
	_menuButtons[3]->SetText("Store");
	_menuButtons[4]->SetText("Console");

}

void LauncherWindow::InitWindow()
{
	_actualGui = new AccountGui();
	_actualGui->BuildYourSelf(*_views);
	_window->AddElement(_views);

}
