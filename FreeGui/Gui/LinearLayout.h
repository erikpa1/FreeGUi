#pragma once
#include "GuiElement.h"
#include "Layout.h"

class EXPORT LinearLayout : public Layout

{
public:

	LinearLayout(int x, int y , int w, int h);
	~LinearLayout();

	void AddElement(GuiElement & element) override;
	void SetRenderer(RenderWindow* window) override;

private:

	void RefreshElements();

};
