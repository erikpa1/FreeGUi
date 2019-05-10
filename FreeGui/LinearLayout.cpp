#include "stdafx.h"
#include "LinearLayout.h"


LinearLayout::LinearLayout(int x, int y, int w, int h) : Layout(x, y, w, h)
{

}


LinearLayout::~LinearLayout()
{

}

void LinearLayout::AddElement(GuiElement& element)
{
	Layout::AddElement(element);
	if (GetRenderWindow() != nullptr)
	{
		RefreshElements();
	}

}

void LinearLayout::SetRenderer(RenderWindow* window)
{
	Layout::SetRenderer(window);
	RefreshElements();

}

void LinearLayout::RefreshElements()
{
	int positionX = 0;
	int positionY = 0;
	int dimensionX = 0;
	int dimensionY = 0;

	if (_fillParent == true)
	{
		if (_parent != nullptr)
		{
			positionX = _parent->GetPositionX();
			positionY = _parent->GetPositionY();
			dimensionX = _parent->GetDimensionX();
			dimensionY = (_parent->GetDimensionY() + (_gap * _children.size())) / _children.size();
		}
		else
		{
			positionX = 0;
			positionY = 0;
			dimensionX = GetRenderWindow()->getSize().x;
			dimensionY = (GetRenderWindow()->getSize().y + (_gap * _children.size())) / _children.size();
		}
	}
	else
	{
		positionX = _position.x;
		positionY = _position.y;
		dimensionX = _dimension.x;
		dimensionY = (_dimension.y + (_gap * _children.size())) / _children.size();
	}

	for (int a = 0; a < _children.size(); a++)
	{
		_children[a]->SetDimension(dimensionX, dimensionY / _children.size());
		_children[a]->SetPosition(positionX, positionY + ((dimensionY / _children.size() + _gap) * a));
	}
}
