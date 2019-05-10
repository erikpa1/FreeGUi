#pragma once
#include "Box.h"
class EXPORT HBox : public Box
{
public:

	HBox(int x, int y, int w ,int h);
	~HBox();
	
	void SetPosition(int x, int y) override;
	void SetDimension(int x, int y) override;
	
	void AddElement(GuiElement & element) override;
	void removeElement(int position) override;



private:

	void RefreshElements();

};

