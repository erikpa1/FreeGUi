#include "stdafx.h"
#include "Buton.h"

#define COLOR_DIFFERENCE 10

Buton::Buton(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{
	_backgroundShape = RectangleShape(Vector2f(x, y));
	_drawable = &_backgroundShape;

	Buton::SetPosition(x, y);
	Buton::SetColor(50, 50, 50, 255);
	Buton::SetDimension(100, 50);

	_buttonText.SetParent(this);

	SetAligment(MIDDLE, *this, this->_buttonText);

}

Buton::~Buton()
{

}

void Buton::Start()
{
	Renderable::Start();
}

void Buton::Update()
{
	Renderable::Update();
}

void Buton::SendEvent(Event& event)
{

	GuiElement::SendEvent(event);

	switch (event.type)
	{

	case Event::MouseButtonPressed:

		if (MouseOnElement(event.mouseButton.x, event.mouseButton.y))
		{
			_backgroundShape.setFillColor(Color(rand(), rand(), rand()));
			GuiElement::ForwardEvent(1);
		}

		break;

	case Event::MouseMoved:

		if (MouseOnElement(event.mouseMove.x, event.mouseMove.y))
		{
			_backgroundShape.setFillColor(_onMouseFocusColor);

		}
		else
		{
			_backgroundShape.setFillColor(_color);
		}
		break;
	}
}

void Buton::SetPosition(int x, int y)
{
	GuiElement::SetPosition(x, y);
	_backgroundShape.setPosition(x, y);

	SetAligment(MIDDLE, *this, this->_buttonText);

}

void Buton::SetDimension(int x, int y)
{
	Renderable::SetDimension(x, y);
	_backgroundShape.setSize(Vector2f(x, y));
}


void Buton::Draw()
{
	Renderable::Draw();
	this->_buttonText.Draw();
}

void Buton::SetRenderer(RenderWindow* window)
{
	Renderable::SetRenderer(window);
	this->_buttonText.SetRenderer(window);
}
void Buton::SetFontColor(int r, int g, int b, int a)
{

}

void Buton::SetText(string text)
{
	this->_buttonText.SetText(text);
}

void Buton::SetColor(int r, int g, int b, int a)
{
	_color = Color(r, b, g, a);
	_backgroundShape.setFillColor(_color);
}

Label* Buton::GetLabel()
{
	return &this->_buttonText;
}