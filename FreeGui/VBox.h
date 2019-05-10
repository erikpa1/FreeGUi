#pragma once
#include "Box.h"


class EXPORT VBox : public Box
{

public:

	VBox(int x, int y, int w, int h);
	~VBox();

	void operator=(const GuiElement & other) override;

	void AddElement(GuiElement & element) override;
	void removeElement(int position) override;

	void SetPosition(int x, int y) override;
	void SetDimension(int x, int y) override;



};


