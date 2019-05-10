#include "stdafx.h"
#include "Gui/Renderable.h"



Renderable::Renderable()
{
	this->CommonConstructor();

	this->_position.x = 1;
	this->_position.y = 1;
	this->_dimension.x = 200;
	this->_dimension.y = 100;

}


Renderable::Renderable(int x, int y, int w, int h)
{
	this->CommonConstructor();
	this->_position = Vector2i(x, y);
	this->_dimension = Vector2i(w, h);

}

void Renderable::AddChild(Renderable* child)
{
	this->_children.push_back(child);
}

void Renderable::SetParent(Renderable* parent)
{
	this->_parent = parent;
	this->_window = parent->GetRenderWindow();
}

void Renderable::DisconnectFromParent()
{
	this->_parent = nullptr;
}

void Renderable::DisconnectChildren()
{
	this->_children.clear();
}

void Renderable::EraseChildren()
{
	for (auto i = 0; i < this->_children.size(); i++)
	{
		delete this->_children.at(i);
	}

	this->_children.clear();
}

int Renderable::numberOfMe = 0;

void Renderable::CommonConstructor()
{
	this->_ID = rand();
	this->_canBeDrawed = true;
	this->_canRecieveUpdate = true;
	this->_dimension = Vector2i(50, 50);

	numberOfMe++;
	cout << Renderable::numberOfMe << endl;

}

void Renderable::DrawChildren()
{
	for (auto i = 0; i < this->_children.size(); i++)
	{
		this->_children.at(i)->Draw();
	}
}

void Renderable::UpdateChildren()
{
	for (auto i = 0; i < this->_children.size(); i++)
	{
		this->_children.at(i)->Update();
	}
}

Renderable::~Renderable()
{
	//delete _parent;

	if (_drawable != nullptr)
	{
		//delete _drawable;
	}
	
}

void Renderable::Start()
{
}


void Renderable::Update()
{

}

void Renderable::Draw()
{
	if (this->_canBeDrawed && this->_drawable)
	{
		if (this->_window)
		{
			this->_window->draw(*this->_drawable);
		}

		for (auto temp : _children)
		{
			this->DrawChildren();
		}
	}
}


void Renderable::SetRenderer(RenderWindow *window)
{
	this->_window = window;
}

void Renderable::ChangeDrawingStatus(bool value)
{
	this->_canBeDrawed = value;
}

void Renderable::ChangeUpdateStatus(bool value)
{
	this->_canRecieveUpdate = value;
}

void Renderable::SetPosition(int x, int y)
{
	this->_position.x = x;
	this->_position.y = y;
}

void Renderable::SetDimension(int x, int y)
{
	this->_dimension.x = x;
	this->_dimension.y = y;
}


void Renderable::SetID(int ID)
{
	this->_ID = ID;
}

int Renderable::GetID()
{
	return _ID;
}

RenderWindow* Renderable::GetRenderWindow()
{
	return this->_window;
}


void Renderable::SendEvent(Event& event)
{
	for (auto temp : _children)
	{
		temp->SendEvent(event);
	}
}

void Renderable::SetColor(int r, int g, int b, int a)
{
	_color = Color(r, g, b, a);
}

void Renderable::RecalculateYourSelf()
{

}

void Renderable::SetRelative()
{
	_isRelative = true;
}

void Renderable::SetAbsolute()
{
	_isRelative = false;
}




