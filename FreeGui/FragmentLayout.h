#pragma once

#include "Layout.h"
#include "ScrollLayout.h"
#include "LinearLayout.h"

class EXPORT FragmentLayout : public Layout
{
	FragmentLayout(int windowPercentages);

	void SetDimension(int x, int y) override;
	void SetPosition(int x, int y) override;

	void addFrameng();

private:

	ScrollLayout * _scrollView = nullptr;
	LinearLayout * _window = nullptr;

};




