#pragma once
#include "SFML/Graphics.hpp"

class EventReactable
{
public:
	EventReactable();
	~EventReactable();

	virtual void EventHappened(sf::Event event) = 0;
};

EventReactable::EventReactable()
{
}


EventReactable::~EventReactable()
{
}