#include "stdafx.h"
#include "Gui/HBox.h"

HBox::HBox(int x, int y, int w, int h) : Box(x, y, w, h)
{

}

HBox::~HBox()
{

}

void HBox::SetPosition(int x, int y)
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

void HBox::SetDimension(int x, int y)
{
	GuiElement::SetDimension(x, y);
}



void HBox::AddElement(GuiElement& renderable)
{

	renderable.SetRenderer(GetRenderWindow());
	_children.push_back(&renderable);
	if (_affectChildrenDimension != true)
	{
		if (_children.empty())
		{
			renderable.SetPosition(GetPositionX(), GetPositionY());
		}
		else
		{
			int x = _children.back()->GetPositionX();
			int w = _children.back()->GetDimensionX();

			renderable.SetPosition(x + w + _gap, GetPositionY());
		}
	}
	else
	{
		RefreshElements();
	}


}

void HBox::removeElement(int position)
{

}

void HBox::RefreshElements()
{

	if (_affectChildrenDimension == true)
	{
		int positionX = _position.x;
		int positionY = _position.y;
		int dimensionX = _dimension.x / _children.size();
		int dimensionY = _dimension.y;

		for (auto i = 0; i < _children.size(); i++)
		{
			_children[i]->SetPosition(positionX + (i * (dimensionX + _gap)), positionY);
			_children[i]->SetDimension(dimensionX, dimensionY);
		}
	}
}