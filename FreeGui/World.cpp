#include "stdafx.h"
#include "World.h"
#include <glew.h>


World::World(int x, int y, int w, int h) : GuiElement(x, y, w, h)
{
	
	// Set the color and depth clear values
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 1.f);

	// Enable Z-buffer read and write
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	// Disable lighting and texturing
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	_mesh = new MeshData();

	
}


World::~World()
{
	
}

void World::Draw()
{
	_mesh->Draw();
}

void World::Update()
{
	_mesh->Update();
}

void World::SendEvent(Event& event)
{

}

void World::SetRenderer(RenderWindow* window)
{
	GuiElement::SetRenderer(window);
	_mesh->SetRenderer(window);
	
}
