#include "stdafx.h"
#include "ScrollBar.h"
#include <iostream>


ScrollBar::ScrollBar(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{
	_background.setFillColor(Color(100, 100, 100, 255));
	_background.setPosition(x, y);
	_background.setSize(Vector2f(w, h));
	_slider.setFillColor(Color(70, 70, 70, 255));
	_slider.setPosition(x, y);
	_slider.setSize(Vector2f(w, 0));

}

ScrollBar::~ScrollBar()
{

}

void ScrollBar::SetDimension(int x, int y)
{
	_dimension.x = x;
	_dimension.y = y;
	_background.setSize(Vector2f(x, y));
	_slider.setSize(Vector2f(x, y / _lastSliderIndex));

}

void ScrollBar::SetPosition(int x, int y)
{
	_position.x = x;
	_position.y = y;
	_background.setPosition(x, y);
	_slider.setPosition(x, y + (_lastSliderIndex / _sliderElementsSize) * _dimension.y);
}

void ScrollBar::Draw()
{
	GetRenderWindow()->draw(_background);
	GetRenderWindow()->draw(_slider);
}

void ScrollBar::SetSliderPosition(int topElementIndex, int elementCount)
{
	Vector2f positionVector = Vector2f(_position.x, _position.y);
	if (elementCount > 0)
	{
		if (elementCount - topElementIndex > 0)
		{
			positionVector.y = _position.y + (double)_dimension.y * ((double)topElementIndex / (double)elementCount);
			positionVector.x = _position.x;
		}
		else
		{
			positionVector.y = _position.y + _dimension.y - _slider.getSize().y;
			positionVector.x = _position.x;
		}

	}
	cout << "topElementIndex: " << topElementIndex << " elementCount: " << elementCount << endl;
	_slider.setPosition(positionVector);
}

void ScrollBar::SetSliderDimension(int elementCount)
{
	Vector2f sizeVector(_dimension.x, 0);
	if (elementCount <= 0)
	{
		sizeVector.y = _dimension.y;
	}
	else
	{
		sizeVector = Vector2f(_dimension.x, ((double)(_dimension.y) / (double)(elementCount)));
		if (sizeVector.y < 1)
		{
			sizeVector.y = 1;
		}
	}
	_slider.setSize(sizeVector);
}
