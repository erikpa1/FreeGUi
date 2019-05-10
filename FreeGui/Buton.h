#pragma once

#include "GuiElement.h"
#include "Label.h"


using namespace sf;

class EXPORT Buton : public GuiElement
{
public:

	Buton(int x, int y, int w, int h);
	~Buton();

	void Start() override;
	void Update() override;
	void Draw() override;

	void SendEvent(Event& event);

	void SetPosition(int x, int y) override;
	void SetDimension(int x, int y) override;	

	void SetRenderer(RenderWindow* window);
	void SetFontColor(int r, int g, int b, int a = 255);
	void SetColor(int r, int g, int b, int a = 255) override;

	void SetText(string text);	


	Label *GetLabel();

	string GetButtonText() { return _buttonText.GetText().getString(); };

private:

	Label _buttonText;
	Image _image;

	Color _onMouseFocusColor = Color(70, 70, 70);
	Color _onMouseClickColor;

	RectangleShape _backgroundShape;

};




