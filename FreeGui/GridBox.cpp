#include "stdafx.h"
#include "GridBox.h"

GridBox::GridBox(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{


}

GridBox::~GridBox()
{
}

void GridBox::SetGrid(int column, int row)
{
	;
}


void GridBox::addElement(int column, int row, GuiElement& renderable)
{

	/*renderable.SetRenderer(GetRenderWindow());

	if (_boxElements.empty())
	{
	_boxElements.push_back(&renderable);
	renderable.SetPosition(GetPositionX(), GetPositionY());
	}
	else
	{
	int x = _boxElements.back()->GetPositionX();
	int w = _boxElements.back()->GetDimensionX();

	renderable.SetPosition(x + w + _gap, GetPositionY());

	_boxElements.push_back(&renderable);
	}*/

}

void GridBox::pushElement(GuiElement& element)
{

}
