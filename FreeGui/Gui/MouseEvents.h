#pragma once
#include <functional>
#include <SFML/System/Vector2.hpp>

class MouseEvents

{
public:

	MouseEvents();
	~MouseEvents();

	virtual void EventHappened(int eventID) = 0;


};



MouseEvents::MouseEvents()
{
}


MouseEvents::~MouseEvents()
{
}

