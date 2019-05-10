#pragma once

#include <vector>
#include "Renderable.h"
#include "SFML/Graphics.hpp"
#include "../World.h"


using namespace std;
using namespace sf;

class EXPORT AppWindow : public Renderable
{

public:

	AppWindow(int x, int y, int w, int h, string appName);
	~AppWindow();
	
	void IndependentStart();
	void Tick();
	void Pause();
	void Remove();
	void AddElement(Renderable *renderable);
		
	bool CanAcceptTick() const { return _window->isOpen() && _canUpdate;}

	int GetDimensionX() const override;
	int GetDimensionY() const override;
	int GetPositionX() const override;
	int GetPositionY() const override;

	RenderWindow *GetRenderWindow() { return _window; };
		
private:

	inline void ParticalTick();	
	inline void HandleEvents(Event &event);

	bool _canDraw = true;
	bool _canUpdate = true;
	bool _canSendEvents = true;

	vector<Renderable*> _renderableObjects;
	RenderWindow *_window;
	World * _world = nullptr;

};


