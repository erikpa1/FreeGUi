#include "stdafx.h"
#include "Gui/Layout.h"


Layout::Layout(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{

}

void Layout::AddElement(GuiElement& element)
{
	_children.push_back(&element);
	element.SetRenderer(GetRenderWindow());
}

void Layout::setGap(int gap)
{
	_gap = gap;
}

void Layout::Draw()
{
	GuiElement::Draw();
	for (auto temp : _children)
	{
		temp->Draw();
	}
}

void Layout::Update()
{
	for (auto temp : _children)
	{
		temp->Update();
	}
}

void Layout::FillParent()
{
	_fillParent = true;
}

void Layout::FillPredefinedSize()
{
	_fillParent = false;
}