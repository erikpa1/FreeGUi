#include "stdafx.h"
#include "Gui/VBox.h"


VBox::VBox(int x, int y, int w, int h) : Box(x, y, w, h)
{

}


VBox::~VBox()
{
}

void VBox::operator=(const GuiElement& other)
{
	GuiElement::operator=(other);
}


void VBox::SetPosition(int x, int y)
{
	GuiElement::SetPosition(x, y);

	if (!_children.empty())
	{
		_children[0]->SetPosition(x, y);

		for (auto i = 1; i < _children.size(); i++)
		{
			int x = _children[i - 1]->GetPositionX() + _children[i - 1]->GetDimensionX();
			int y = _children[i - 1]->GetDimensionY() + _children[i - 1]->GetDimensionY();

			_children[i]->SetPosition(x, y);
		}
	}
}

void VBox::SetDimension(int x, int y)
{
	GuiElement::SetDimension(x, y);

}


void VBox::AddElement(GuiElement & renderable)
{
	renderable.SetRenderer(GetRenderWindow());

	if (_children.empty())
	{
		_children.push_back(&renderable);
		renderable.SetPosition(GetPositionX(), GetPositionY());
	}
	else
	{
		int y = _children.back()->GetPositionY();
		int h = _children.back()->GetDimensionY();

		renderable.SetPosition(GetPositionX(), y + h + _gap);

		_children.push_back(&renderable);

	}
}

void VBox::removeElement(int position)
{

}
