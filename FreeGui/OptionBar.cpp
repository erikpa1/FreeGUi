#include "stdafx.h"
#include "OptionBar.h"

OptionBar::OptionBar(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{
	_elements = new VBox(x, y, w, h);
	GuiElement::Disable();
}

OptionBar::~OptionBar()
{
	delete _elements;
}

void OptionBar::Draw()
{
	if (_updateActive)
	{
		_elements->Draw();
	}

}

void OptionBar::Start()
{
	_elements->Start();
}

void OptionBar::Update()
{
	if (_updateActive)
	{
		_elements->Update();
	}
}

void OptionBar::SendEvent(Event& event)
{
	if (_updateActive)
	{
		_elements->SendEvent(event);
	}

}

void OptionBar::SetRenderer(RenderWindow* window)
{
	GuiElement::SetRenderer(window);
	_elements->SetRenderer(window);

}

void OptionBar::pushElements(GuiElement& element)
{
	_elements->AddElement(element);
}