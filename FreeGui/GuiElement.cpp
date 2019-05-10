#include "stdafx.h"
#include "GuiElement.h"

GuiElement::GuiElement(int x, int y, int w, int h) : Renderable(x, y, w, h)
{
}


GuiElement::~GuiElement()
{
}

void GuiElement::operator=(const GuiElement& other)
{
	_position.x = other.GetPositionX();
	_position.y = other.GetPositionY();
	_dimension.x = other.GetDimensionX();
	_dimension.y = other.GetDimensionY();
}

void GuiElement::SetRenderer(RenderWindow* window)
{
	Renderable::SetRenderer(window);
	for (auto temp : _children)
	{
		temp->SetRenderer(window);
	}
}

bool GuiElement::MouseOnElement(int x, int y)
{
	bool isXOk = (x >= this->GetPositionX()) && (x <= (this->GetDimensionX() + this->GetPositionX()));
	bool isYOk = (y >= this->GetPositionY()) && (y <= (this->GetDimensionY() + this->GetPositionY()));

	cout << "My position is " << GetPositionX() << " " << GetPositionY() << endl;;
	cout << "My dimension is " << GetDimensionX() << " " << GetDimensionY() << endl;;
	cout << "Mouse was: " << x << " " << y << endl;
	
	return isXOk && isYOk;
}

void GuiElement::EnableResizing()
{

}

void GuiElement::DisableResizing()
{

}

void GuiElement::SetPaddings(int top, int down, int left, int right)
{
	_downPadding = down;
	_topPadding = top;
	_leftPadding = left;
	_rightPadding = left;
}

Int4 GuiElement::GetPadding()
{
	return {0, 0, 0, 0};
}

void GuiElement::Disable()
{
	_updateActive = false;
}

void GuiElement::Enable()
{
	_updateActive = true;
}


void GuiElement::SetAligment(POSE pose, const Renderable& parent, Renderable& child)
{

	int x = parent.GetPositionX();
	int y = parent.GetPositionY();

	switch (pose)
	{
	case MIDDLE:

		x += (parent.GetDimensionX() / 2) - child.GetDimensionX() / 2;
		y += (parent.GetDimensionY() / 2) - child.GetDimensionY();
		child.SetPosition(x, y);
		break;
	case LEFT:
		y += (parent.GetDimensionY() / 2) - child.GetDimensionY();
		child.SetPosition(x, y);
		break;
	}


}

void GuiElement::SetOnClick(IEventAcceptable & onClick)
{
	_events.insert_or_assign(1, &onClick);
}

void GuiElement::ForwardEvent(int event)
{
	IEventAcceptable * reciever = _events[event];

	if (reciever != nullptr)
	{
		reciever->SendEvent(event);
	}
}

