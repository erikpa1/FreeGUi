#include "stdafx.h"
#include "GuiPair.h"




GuiPair::GuiPair(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{
		   

}

GuiPair::GuiPair() : GuiElement(0, 0, 0, 0)
{
}

GuiPair::~GuiPair()
{

}

void GuiPair::Update()
{
	if (_element1 != nullptr)
	{
		_element1->Update();
	}
	if (_element2 != nullptr)
	{
		_element2->Update();
	}
}

void GuiPair::Draw()
{
	if (_element1 != nullptr)
	{
		_element1->Draw();
	}
	if (_element2 != nullptr)
	{
		_element2->Draw();
	}
}

void GuiPair::SendEvent(Event& event)
{
	if (_element1 != nullptr)
	{
		_element1->SendEvent(event);
	}
	if (_element2 != nullptr)
	{
		_element2->SendEvent(event);
	}
}

void GuiPair::RecalculateYourSelf()
{
	if (_isRelative)
	{
		SetDimension(_parent->GetDimensionX(), _parent->GetDimensionY());
	}
	RecalculateElements();
}

void GuiPair::SetPosition(int x, int y)
{
	GuiElement::SetPosition(x, y);
	RecalculateElements();
}

void GuiPair::SetDimension(int x, int y)
{
	GuiElement::SetDimension(x, y);	
	RecalculateElements();	
}

void GuiPair::SetAbsolute()
{
	GuiElement::SetAbsolute();
	RecalculateElements();
}

void GuiPair::SetRelative()
{
	GuiElement::SetRelative();
	RecalculateElements();
}

void GuiPair::SetParent(Renderable* parent)
{
	GuiElement::SetParent(parent);
	RecalculateYourSelf();
}

void GuiPair::SetRenderer(RenderWindow* window)
{
	if (_element1 != nullptr)
	{
		_element1->SetRenderer(window);
	}
	if (_element2 != nullptr)
	{
		_element2->SetRenderer(window);
	}
}

void GuiPair::SetRatio(double ratio)
{
	_pomer = ratio;
}

void GuiPair::SetElements(GuiElement* element1, GuiElement* element2, double percent)
{
	_element1 = element1;
	_element2 = element2;
	_element1->SetParent(this);
	_element2->SetParent(this);

	_pomer = percent;

	RecalculateElements();

}

void GuiPair::RecalculateElements()
{

	int x = GetPositionX();
	int y = GetPositionY();

	int w = GetDimensionX();
	int h = GetDimensionY();

	if (_element1 != nullptr)
	{
		_element1->SetDimension(w * _pomer, h);
	}

	if (_element2 != nullptr)
	{
		_element2->SetDimension(w * (1 - _pomer), h);
	}

	if (_element1 != nullptr)
	{
		_element1->SetPosition(x, y);
	}
	if (_element2 != nullptr)
	{
		_element2->SetPosition(x + ((double)GetDimensionX() * _pomer), y);
	}
	
	cout << "New X is " << x + (GetDimensionX() * _pomer) << endl;
}
