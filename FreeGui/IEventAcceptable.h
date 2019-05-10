#pragma once

#define LEFTCLICK 1;


namespace sf {
	class Event;
}


class IEventAcceptable
{

public:

	virtual void SendEvent(int i) = 0;
	virtual void SendAdvancedEvent(sf::Event & event);
};

inline void IEventAcceptable::SendAdvancedEvent(sf::Event& event)
{

}
