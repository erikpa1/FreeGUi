#pragma once
#include "GuiElement.h"
#include "Layout.h"

class EXPORT Box : public Layout
{
public :

	Box(int x, int y, int w, int h) : Layout(x, y, w, h)
	{
		_backgroundShape = RectangleShape(Vector2f(x, y));
		Layout::SetColor(100, 100, 100);
	}

	void Draw() override;
	void Start() override;
	void Update() override;

	void SetColor(int r, int g, int b, int a = 255) override;
	void SetRenderer(RenderWindow* window) override;
	void SendEvent(Event& event) override;

	void SetChildrenAutoScaleOn();
	void SetChildrenAutoScaleOff();

	int getSize();


	virtual void AddElement(GuiElement & element) override = 0;
	virtual void removeElement(int position) = 0;

protected:

	bool _affectChildrenDimension = false;

protected:

	RectangleShape _backgroundShape;
	

};

