#pragma once
#include "Layout.h"
#include "ScrollBar.h"
#include <iostream>


class EXPORT ScrollLayout : public Layout
{
public:

	ScrollLayout(int x, int y, int w, int h);
	~ScrollLayout();

	void AddElement(GuiElement & element) override;
	void SetRenderer(RenderWindow* window) override;
	void SendEvent(Event& event) override;
	void Draw() override;
	
	void SetScrollBarSize(int size);

private:
	
	int _previousVisibleValue = 0;
	int _lowVisibleIndex = 0;
	int _highVisibleIndex = 0;

	int _lastMouseX = 0;
	int _lastMouseY = 0;
	int _scrollBarSize = 0;
	
	void RefreshElements();	
	ScrollBar * _scrollBar = nullptr;
	RectangleShape _background;



};


