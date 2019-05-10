#pragma once


#include "Renderable.h"
#include "Poses.h"
#include "IEventAcceptable.h"

#include <unordered_map>
#include "Variable.h"


class EXPORT GuiElement : public Renderable
{
	
public:	

	GuiElement(int x, int y, int w, int h);	
	~GuiElement();	

	virtual void operator=(const GuiElement & other);
	virtual void SetRenderer(RenderWindow* window) override;

	static void SetAligment(POSE pose, const Renderable &parent, Renderable &child);
	
	void SetOnClick(IEventAcceptable& onClick);
	void ForwardEvent(int event);

	bool MouseOnElement(int x, int y);

	void EnableResizing();
	void DisableResizing();

	virtual void SetPaddings(int top, int down, int left, int right);
	virtual Int4 GetPadding();
	


	virtual void Disable();
	virtual void Enable();

	unordered_map<int, IEventAcceptable*> _events;

protected:

	bool _updateActive = true;

	int _topPadding = 0;
	int _downPadding = 0;
	int _leftPadding = 0;
	int _rightPadding = 0;




	




	
};


