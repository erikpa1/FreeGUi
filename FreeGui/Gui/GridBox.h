#pragma once
#include "GuiElement.h"
#include "VBox.h"
#include "HBox.h"

class EXPORT GridBox : public GuiElement
{

public:

	GridBox(int x, int y, int w, int h);
	~GridBox();

	void SetGrid(int column, int row);	
	void addElement(int column, int row, GuiElement& element);
	void pushElement(GuiElement& element);

private:

	pair<int, int> _matrixSize;

	VBox *_column;
	vector<HBox*> *_boxes;
	
	
		

};




