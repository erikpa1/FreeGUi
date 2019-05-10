#pragma once
#include "GuiElement.h"
#include "Definitions.h"

class EXPORT GuiPair : public GuiElement
{
public:

	GuiPair(int x, int y, int w, int h);
	GuiPair();
	~GuiPair();

	void Update() override;
	void Draw() override;
	void SendEvent(Event& event) override;
	void RecalculateYourSelf() override;
	void SetPosition(int x, int y) override;
	void SetDimension(int x, int y) override;
	void SetAbsolute() override;
	void SetRelative() override;
	void SetParent(Renderable* parent) override;

	void SetRenderer(RenderWindow* window) override;
	void SetRatio(double ratio);
	void SetElements(GuiElement * element1, GuiElement * element2, double percent);

private:

	GuiElement * _element1 = nullptr;
	GuiElement * _element2 = nullptr;

	double _pomer = 0.5;

	void RecalculateElements();


};

