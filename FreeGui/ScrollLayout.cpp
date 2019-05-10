#include "stdafx.h"
#include "ScrollLayout.h"


ScrollLayout::ScrollLayout(int x, int y, int w, int h) : Layout(x, y, w, h)
{
	_background.setFillColor(Color(75, 75, 75, 255));
	_background.setPosition(x, y);
	_background.setSize(Vector2f(w, h));
}

ScrollLayout::~ScrollLayout()
{
	delete _scrollBar;
	_scrollBar = nullptr;
}

void ScrollLayout::AddElement(GuiElement& element)
{
	element.SetDimension(_dimension.x, element.GetDimensionY() - _scrollBarSize);
	_children.push_back(&element);
	RefreshElements();

	if (_scrollBar != nullptr)
	{
		_scrollBar->SetSliderDimension(_children.size());
	}
}

void ScrollLayout::SetScrollBarSize(int size)
{
	_scrollBarSize = size;
	if (_scrollBar == nullptr)
	{
		_scrollBar = new ScrollBar(_position.x + _dimension.x - _scrollBarSize, _position.y, _scrollBarSize, _dimension.y);
	}
	else
	{
		_scrollBar->SetDimension(_scrollBarSize, _dimension.y);
		_scrollBar->SetPosition(_position.x + _dimension.x - _scrollBarSize, _position.y);
	}

}

void ScrollLayout::SetRenderer(RenderWindow* window)
{
	Layout::SetRenderer(window);
	if (_scrollBar != nullptr)
	{
		_scrollBar->SetRenderer(window);
	}
}

void ScrollLayout::SendEvent(Event& event)
{
	for (auto i = _lowVisibleIndex; i <= _highVisibleIndex; i++)
	{
		_children[i]->SendEvent(event);
	}

	switch (event.type)
	{

	case Event::MouseMoved:
		_lastMouseX = event.mouseMove.x;
		_lastMouseY = event.mouseMove.y;
		break;

	case Event::MouseWheelScrolled:
		if (MouseOnElement(_lastMouseX, _lastMouseY))
		{
			if (event.mouseWheelScroll.delta < 0)
			{
				if (_lowVisibleIndex + 1 < _children.size())
				{
					_previousVisibleValue = _lowVisibleIndex;
					_lowVisibleIndex += 1;
					RefreshElements();
				}
			}
			if (event.mouseWheelScroll.delta > 0)
			{
				if (_lowVisibleIndex > 0)
				{
					_lowVisibleIndex -= 1;
					RefreshElements();
				}
			}
		}
		break;
	}
}

void ScrollLayout::Draw()
{
	GetRenderWindow()->draw(_background);
	if (_scrollBar != nullptr)
	{
		_scrollBar->Draw();
	}
	for (auto i = _lowVisibleIndex; i <= _highVisibleIndex; i++)
	{
		_children[i]->Draw();
	}
}

void ScrollLayout::RefreshElements()
{
	int lowIndex = _lowVisibleIndex;
	int elementsSizeCount = 0;
	bool overflowed = false;

	int index = 0;
	for (auto i = _lowVisibleIndex; i < _children.size(); i++)
	{
		_children[lowIndex]->SetPosition(_position.x, _position.y + ((_gap + _children[lowIndex]->GetDimensionY()) * index));
		_children[lowIndex]->SetDimension(_dimension.x - _scrollBarSize, _children[lowIndex]->GetDimensionY());
		elementsSizeCount += _children[lowIndex]->GetDimensionY() + _gap;

		if (elementsSizeCount <= _dimension.y)
		{
			if (lowIndex < _children.size())
			{
				lowIndex++;
			}
		}
		else
		{
			_highVisibleIndex = lowIndex;
			overflowed = true;
			if (_scrollBar != nullptr)
			{
				_scrollBar->SetSliderPosition(_lowVisibleIndex, _children.size() - _lowVisibleIndex);
			}
			return;
		}
		index++;
	}

	if (overflowed == false)
	{
		_lowVisibleIndex = _previousVisibleValue;
		_highVisibleIndex = _children.size() - 1;

	}
	else
	{
		_highVisibleIndex = lowIndex;
	}

	if (_scrollBar != nullptr)
	{
		_scrollBar->SetSliderPosition(_lowVisibleIndex, _children.size() - _lowVisibleIndex);
	}
}