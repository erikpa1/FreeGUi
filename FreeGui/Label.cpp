#include "stdafx.h"
#include "Gui/Label.h"
#include "Gui/Fonts.h"


inline Label::Label() : GuiElement(0, 0, 0, 0)
{
	this->CommonConstructor();
}

inline Label::Label(int x, int y, int w, int h, string text) : GuiElement(x, y, w, h)
{
	this->CommonConstructor();
}

inline void Label::CommonConstructor()
{
	this->_font.loadFromFile(FONT_MICROSS);
	this->_actualText.setFont(_font);
	this->_actualText.setStyle(Text::Bold);
	this->_actualText.setString("Default");
	this->_actualText.setCharacterSize(20);
	this->_actualText.setFillColor(Color::White);
	this->_drawable = &_actualText;
}


inline Label::~Label()
{

}

inline void Label::Start()
{
	Renderable::Start();
}

inline void Label::Update()
{
	Renderable::Update();
}

inline void Label::Draw()
{
	Renderable::Draw();
	this->_window->draw(this->_actualText);
}

inline void Label::SetPosition(int x, int y)
{
	Renderable::SetPosition(x, y);
	this->_actualText.setPosition(x, y);
}

inline void Label::SetDimension(int x, int y)
{
	Renderable::SetDimension(x, y);
	this->_actualText.setScale(x, y);
}

inline void Label::SetText(string text)
{
	this->_actualText.setString(text.c_str());

	Renderable * parent;

	if (_parent == nullptr)
	{
		parent = this;
	} else
	{
		parent = _parent;
	}

	if (_actualText.getCharacterSize() * _actualText.getString().getSize() >= parent->GetDimensionX())
	{
		_actualText.setCharacterSize(parent->GetDimensionX() / _actualText.getString().getSize());
	}
}

inline void Label::SetButtonColor(int r, int g, int b, int a)
{
	this->_actualText.setFillColor(Color(r, g, b, a));
}

inline int Label::GetDimensionX() const
{
	return this->_actualText.getGlobalBounds().width;
}

inline int Label::GetDimensionY() const
{
	return this->_actualText.getGlobalBounds().height;
}
