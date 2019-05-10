#pragma once
#include "GuiElement.h"

class EXPORT ScrollBar : public GuiElement
{
public:

	ScrollBar(int x, int y, int w, int h);
	~ScrollBar();

	void SetDimension(int x, int y) override;
	void SetPosition(int x, int y) override;
	void Draw() override;

	void SetSliderPosition(int topElementIndex, int elementCount);
	void SetSliderDimension(int elementCount);

private:

	int _lastSliderIndex = 1;
	int _sliderElementsSize = 1;
			
	RectangleShape _slider;
	RectangleShape _background;



};

