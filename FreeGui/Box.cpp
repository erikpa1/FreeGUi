#include "stdafx.h"
#include "Gui/Box.h"

void Box::Draw()
{
	GuiElement::Draw();
	for (auto guiElement : _children)
	{
		guiElement->Draw();
	}
}


inline void Box::SetChildrenAutoScaleOn()
{
	_affectChildrenDimension = true;
}

inline void Box::SetChildrenAutoScaleOff()
{
	_affectChildrenDimension = false;
}


void Box::Start()
{
}

void Box::Update()
{
}

void Box::SetColor(int r, int g, int b, int a)
{
	_color = Color(r, b, g, a);
	_backgroundShape.setFillColor(_color);

}

void Box::SetRenderer(RenderWindow* window)
{
	Renderable::SetRenderer(window);

	for (auto guiElements : _children)
	{
		guiElements->SetRenderer(GetRenderWindow());
	}

}

void Box::SendEvent(Event& event)
{
	for (auto guiElement : _children)
	{
		guiElement->SendEvent(event);
	}
}

int Box::getSize()
{
	return _children.size();
}

