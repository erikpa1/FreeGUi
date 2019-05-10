#include "stdafx.h"
#include "AppWindow.h"
#include <glew.h>

AppWindow::AppWindow(int x, int y, int w, int h, string appName) : Renderable(x, y, w, h)
{
	_window = new RenderWindow(VideoMode(w, h), appName);
	_window->setPosition(Vector2i(x, y));
	_window->setActive(true);

	//_world = new World(0, 400, 400, 600);
	//_world->SetRenderer(_window);

}

AppWindow::~AppWindow()
{
}

void AppWindow::IndependentStart()
{
	_canDraw = true;
	_canUpdate = true;
	_canSendEvents = true;

	while (this->_canDraw && this->_window->isOpen())
	{
		this->ParticalTick();
	}
}

void AppWindow::Tick()
{
	this->ParticalTick();
}

void AppWindow::Pause()
{
	_canUpdate = false;
}

void AppWindow::Remove()
{

}

void AppWindow::AddElement(Renderable* renderable)
{
	_renderableObjects.push_back(renderable);
	renderable->SetParent(this);
	renderable->SetRenderer(this->_window);
}

int AppWindow::GetDimensionX() const
{
	return _window->getSize().x;
}

int AppWindow::GetDimensionY() const
{
	return _window->getSize().y;
}

int AppWindow::GetPositionX() const
{
	return _window->getPosition().x;
}

int AppWindow::GetPositionY() const
{
	return _window->getPosition().y;
}


void AppWindow::ParticalTick()
{

	this->_window->clear();
	Event event;
	while (this->_window->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			_window->close();
		}
		else
		{
			this->HandleEvents(event);
		}
	}

	if (_world != nullptr)
	{
		_window->pushGLStates();
		_world->Update();
		_world->Draw();
		_window->popGLStates();
		_window->pushGLStates();
		_window->popGLStates();
	}


	for (auto i = 0; i < this->_renderableObjects.size(); i++)
	{
		_renderableObjects.at(i)->Update();
		_renderableObjects.at(i)->Draw();
	}

	this->_window->display();
}


void AppWindow::HandleEvents(Event& event)
{
	if (event.type == Event::Resized)
	{
		for (auto tmp : _renderableObjects)
		{
			tmp->RecalculateYourSelf();
		}
	}
	for (auto tmp : _renderableObjects)
	{
		tmp->SendEvent(event);
	}

}



