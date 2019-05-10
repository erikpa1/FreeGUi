#include "stdafx.h"
#include "ProgressBar.h"


ProgressBar::ProgressBar(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{
	_bar.setPosition(x, y);
	_bar.setSize(Vector2f(w, h));
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::Start()
{
}

void ProgressBar::Update()
{
}

void ProgressBar::Draw()
{
}

void ProgressBar::SetPosition(int x, int y)
{
}

void ProgressBar::SetDimension(int x, int y)
{
}

void ProgressBar::SetRenderer(RenderWindow* window)
{
}

void ProgressBar::SetFontColor(int r, int g, int b, int a)
{
}

void ProgressBar::SetColor(int r, int g, int b, int a)
{
}

void ProgressBar::SetText(string text)
{
}
