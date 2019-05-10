#pragma once

#include "GuiElement.h"

class EXPORT ProgressBar : public GuiElement
{
public:

	ProgressBar(int x, int y, int w, int h);
	~ProgressBar();

	void Start() override;
	void Update() override;
	void Draw() override;

	void SetPosition(int x, int y) override;
	void SetDimension(int x, int y) override;

	void SetRenderer(RenderWindow* window);
	void SetFontColor(int r, int g, int b, int a = 255);
	void SetColor(int r, int g, int b, int a = 255) override;

	void SetText(string text);

private:

	RectangleShape _bar;
};



