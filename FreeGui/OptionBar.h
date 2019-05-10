#pragma once
#include "GuiElement.h"
#include "VBox.h"

class EXPORT OptionBar : public GuiElement
{
public:

	OptionBar(int x, int y, int w, int h);
	~OptionBar();

	void Draw() override;
	void Start() override;
	void Update() override;
		
	void SetRenderer(RenderWindow* window) override;	
	void SendEvent(Event& event) override;
	void pushElements(GuiElement & element);
	

private:

	VBox * _elements;


};


