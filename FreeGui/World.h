#pragma once
#include "Gui/GuiElement.h"

#include "MeshData.h"

class EXPORT World : public GuiElement
{
public:
	World(int x, int y, int w, int h);
	~World();

	void Draw() override;
	void Update() override;
	void SendEvent(Event& event) override;
	void SetRenderer(RenderWindow* window) override;

private:
	
	MeshData * _mesh = nullptr;

};

