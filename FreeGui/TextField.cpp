#include "stdafx.h"
#include "TextField.h"
#include "Fonts.h"


TextField::TextField(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{
	this->_font.loadFromFile(FONT_MICROSS);
	_actualText.setFont(_font);
	_actualText.setStyle(Text::Bold);	
	_actualText.setString("Text");
	_actualText.setCharacterSize(20);
	_actualText.setFillColor(Color::White);
	_drawable = &_actualText;
	_background.setFillColor(Color(100, 100, 100, 255));
	_background.setPosition(x, y);
	_background.setSize(Vector2f(w, h));
	
}

TextField::TextField() : GuiElement(0, 0, 0, 0)
{
	this->_font.loadFromFile(FONT_MICROSS);
	_actualText.setFont(_font);
	_actualText.setStyle(Text::Bold);
	_actualText.setString("Write text here");
	_actualText.setCharacterSize(20);
	_actualText.setFillColor(Color::White);
	_drawable = &_actualText;
	_background.setFillColor(Color(100, 100, 100, 255));
	_background.setPosition(0, 0);
	_background.setSize(Vector2f(0, 0));
}


TextField::~TextField()
{
}

void TextField::Draw()
{
	_window->draw(_background);
	if (!_isPasswordField)
	{
		_window->draw(_actualText);
	} else
	{
		Text tempTxt;
		String temp;
		for (auto i = 0; i <  _actualText.getString().getSize(); i++)
		{
			temp += '*';
		}
		tempTxt.setString(temp);
		_window->draw(tempTxt);
	}
	
}

void TextField::SendEvent(Event& event)
{
	
	switch (event.type)
	{
	case Event::TextEntered:
		
		if (_isClicked == true)
		{
			this->HandleTyping(event);			
		} 
		break;

	case event.MouseButtonPressed:
			   
		_isClicked = MouseOnElement(event.mouseButton.x, event.mouseButton.y);
		break;
	}
}

void TextField::SetPosition(int x, int y)
{	
	GuiElement::SetPosition(x, y);	
	_background.setPosition(x, y);
	RecalculateTextPosition();
}

void TextField::SetDimension(int w, int h)
{
	GuiElement::SetDimension(w, h);	
	_background.setSize(Vector2f(w, h));
	RecalculateTextPosition();
}

void TextField::SetNumericOnly(bool value)
{
	_isNumericOnly = value;
}

void TextField::SetPasswordField(bool value)
{
	_isPasswordField = value;
}

void TextField::SetMaximumCharCount(int value)
{
	_maximumCharCount = value;
}

void TextField::SetKeyboardReciever(KeyboardReciever & reciever)
{
	_reciever = & reciever;
}

bool TextField::IsNumberiOnly()
{
	return _isNumericOnly;
}

bool TextField::IsPasswordField()
{
	return _isPasswordField;
}

int TextField::GetMaximumCharCount()
{
	return _maximumCharCount;
}

int TextField::GetNumbericValue()
{
	int value = 0;
	
	try
	{
		value = stoi(_actualText.getString().toAnsiString());
	} catch(exception)
	{
		return -1;
	}
	return value;
}

void TextField::HandleTyping(Event& event)
{
	String userInput = _actualText.getString();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		userInput = userInput.substring(0, userInput.getSize() - 1);
		_actualText.setString(userInput);		
	} else
	{
		if (_actualText.getString().getSize() < _maximumCharCount)
		{
			if (!_isNumericOnly)
			{
				userInput += event.text.unicode;
				_actualText.setString(userInput);
				cout << "User wrote " << event.text.unicode << endl;
			}
			else
			{
				if (event.text.unicode >= 48 && event.text.unicode <= 57)
				{
					userInput += event.text.unicode;
					_actualText.setString(userInput);
				}
			}
		}
	}	
}

void TextField::EnterPressed()
{
	_isClicked = false;
	if (_reciever != nullptr)
	{
		_reciever->EnterPressed();
	}

}

void TextField::RecalculateTextPosition()
{
	int newX = GetPositionX() + _leftPadding;
	int newY = GetPositionY() + _actualText.getCharacterSize()/2;
	_actualText.setPosition(newX, newY);
}
