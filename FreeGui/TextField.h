#pragma once
#include "Gui/GuiElement.h"
#include "KeyboardReciever.h"

class EXPORT TextField : public GuiElement
{
public:
	
	TextField(int x, int y, int w, int h);
	TextField();
	~TextField();

	void Draw() override;
	void SendEvent(Event& event) override;
	void SetPosition(int x, int y) override;
	void SetDimension(int w, int h) override;

	void SetNumericOnly(bool value);
	void SetPasswordField(bool value);
	void SetMaximumCharCount(int value);	
	void SetKeyboardReciever(KeyboardReciever & reciever);

	bool IsNumberiOnly();
	bool IsPasswordField();	
	int GetMaximumCharCount();
	int GetNumbericValue();

	string GetText();
	

private:

	bool _isClicked = false;
	bool _isNumericOnly = false;
	bool _isPasswordField = false;
	int _maximumCharCount = numeric_limits<int>::max();
	
	Text _actualText;	
	Font _font;	
	RectangleShape _background;
	RectangleShape _cursor;
	KeyboardReciever * _reciever = nullptr;

	void HandleTyping(Event & event);	
	void EnterPressed();
	void RecalculateTextPosition();


};

