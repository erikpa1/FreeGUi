#pragma once


#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "ObjectShell.h"

using namespace sf;
using namespace std;

class EXPORT Renderable : public ObjectShell
{

public:

	//Renderable(Renderable &parent);
	Renderable();
	Renderable(int x, int y, int w, int h);
	virtual ~Renderable();


	//Basic rendering voids
	virtual void Start();
	virtual void Update();	
	virtual void Draw();	
	virtual void SetRenderer(RenderWindow *window);
	virtual void SetPosition(int x, int y);
	virtual void SetDimension(int x, int y);
	virtual void SendEvent(Event &event);
	virtual void SetColor(int r, int g, int b, int a = 255);
	virtual void RecalculateYourSelf();
	virtual void SetRelative();
	virtual void SetAbsolute();

	//Basic parent child architecture
	virtual void AddChild(Renderable *child);
	virtual void SetParent(Renderable *parent);
	virtual void DisconnectFromParent();
	virtual void DisconnectChildren();
	virtual void EraseChildren();
	virtual void ChangeDrawingStatus(bool value);
	virtual void ChangeUpdateStatus(bool value);
	virtual void SetID(signed int ID);

	//Basic Element pose
	virtual int GetPositionX() const { return _position.x; }
	virtual int GetPositionY() const { return _position.y; }
	virtual int GetDimensionX() const { return _dimension.x; }
	virtual int GetDimensionY() const { return _dimension.y; }

	signed int GetID();

	
	bool GetDrawingState() { return _canBeDrawed; }
	bool GetUpdateState() { return _canRecieveUpdate; }

   
	RenderWindow *GetRenderWindow();
	//EventPack *GetEventPack() { return _events; }

protected:
	
	inline void DrawChildren();
	inline void UpdateChildren();
	
	Renderable* _parent = nullptr;	
	RenderWindow *_window = nullptr;
	Drawable *_drawable = nullptr;
	vector<Renderable*> _children;

	Color _color;
	Vector2i _position;
	Vector2i _dimension;	
	

	bool _canBeDrawed = true;
	bool _canRecieveUpdate = true;
	bool _isRelative = false;

	signed int _ID;


private:

	static int numberOfMe;
	void CommonConstructor();

};



