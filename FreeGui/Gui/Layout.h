#pragma once
#include "GuiElement.h"
#include "Definitions.h"


class EXPORT Layout : public GuiElement
{

public:

	Layout(int x, int y, int w, int h);
	
	virtual void AddElement(GuiElement & element);

	void setGap(int gap);
	void Draw() override;
	void Update() override;

	void FillParent();
	void FillPredefinedSize();
	
	
protected:

	int _gap = 0;
	bool _fillParent = false;

	
};


