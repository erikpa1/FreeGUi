#pragma once
#include "GuiElement.h"

class EXPORT TextArea : GuiElement
{
public:

	TextArea(int x, int y, int w, int h);
	~TextArea();

	void Start();
	void Update();
	void Draw();
	void SetPosition(int x, int y);
	void SetDimension(int x, int y);
	void SetText(string text);
	void SetButtonColor(int r, int g, int b, int a);


};


