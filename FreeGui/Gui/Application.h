#pragma once
#include "AppWindow.h"
#include <vector>

class EXPORT Application
{
public:

	Application();
	~Application();

	void AddWindow(AppWindow *window);
	void RemoveWindow(AppWindow *window);

	void TickAutomaticly();
	void TickPause();

	void ExternalUpdate();
	void ExternalDraw();
	void ExternalStart();

private:

	vector<AppWindow> _windowses;
	
};

