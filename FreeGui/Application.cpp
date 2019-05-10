#include "stdafx.h"
#include "Gui/Application.h"
#include "GL/glew.h"

Application::Application()
{
	glEnable(GL_DEPTH_TEST);
}


Application::~Application()
{
}

void Application::AddWindow(AppWindow *window)
{
	//this->_windowses.push_back(*window);
}

void Application::TickAutomaticly()
{
	for (int i = 0; i < this->_windowses.size(); i++)
	{
		if (this->_windowses.at(i).CanAcceptTick())
		{
			this->_windowses.at(i).Tick();
		}

	}
}

