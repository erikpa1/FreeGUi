#include "stdafx.h"
#include "BoxMesh.h"
#include <glew.h>
#include <SFML/System/Clock.hpp>
#include "Gui/GuiElement.h"




BoxMesh::BoxMesh(RenderWindow* window)
{
	_window = window;
}

BoxMesh::~BoxMesh()
{
}

GLfloat cube[] =
{
	// positions    // colors (r, g, b, a)
	-50, -50, -50,  0, 0, 1, 1,
	-50,  50, -50,  0, 1, 1, 1,
	-50, -50,  50,  0, 1, 1, 1,
	-50, -50,  50,  0, 1, 1, 1,
	-50,  50, -50,  0, 1, 1, 1,
	-50,  50,  50,  1, 0, 1, 1,

	50, -50, -50,  0, 1, 0, 1,
	50,  50, -50,  0, 1, 0, 1,
	50, -50,  50,  0, 1, 0, 1,
	50, -50,  50,  0, 1, 0, 1,
	50,  50, -50,  0, 1, 0, 1,
	50,  50,  50,  0, 1, 0, 1,

	-50, -50, -50,  1, 0, 0, 1,
	50, -50, -50,  1, 0, 1, 1,
	-50, -50,  50,  1, 0, 1, 1,
	-50, -50,  50,  1, 1, 0, 1,
	50, -50, -50,  1, 0, 1, 1,
	50, -50,  50,  1, 1, 0, 1,

	-50,  50, -50,  0, 1, 1, 1,
	50,  50, -50,  0, 1, 1, 1,
	-50,  50,  50,  0, 1, 1, 1,
	-50,  50,  50,  0, 1, 0, 1,
	50,  50, -50,  0, 1, 0, 1,
	50,  50,  50,  0, 0, 1, 1,

	-50, -50, -50,  1, 0, 1, 1,
	50, -50, -50,  1, 0, 1, 1,
	-50,  50, -50,  1, 0, 1, 1,
	-50,  50, -50,  1, 0, 1, 1,
	50, -50, -50,  1, 0, 1, 1,
	50,  50, -50,  1, 0, 1, 1,

	-50, -50,  50,  1, 1, 0, 1,
	50, -50,  50,  1, 0, 0, 1,
	-50,  50,  50,  1, 0, 0, 1,
	-50,  50,  50,  1, 0, 0, 1,
	50, -50,  50,  1, 1, 0, 1,
	50,  50,  50,  1, 1, 0, 1,
};

void BoxMesh::Draw()
{

	
	glViewport(0, 0, _window->getSize().x, _window->getSize().y);
	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat ratio = static_cast<float>(_window->getSize().x) / _window->getSize().y;
	glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

	// Define a 3D cube (6 faces made of 2 triangles composed by 3 vertices)


	// Enable position and color vertex components
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), cube);
	glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), cube + 3);

	// Disable normal and texture coordinates vertex components
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	// Create a clock for measuring the time elapsed
	Clock clock;
	// Clear the color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Apply some transformations to rotate the cube
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.f, 0.f, -200.f);
	glRotatef(clock.getElapsedTime().asSeconds() * 50, 1.f, 0.f, 0.f);
	glRotatef(clock.getElapsedTime().asSeconds() * 30, 0.f, 1.f, 0.f);
	glRotatef(clock.getElapsedTime().asSeconds() * 90, 0.f, 0.f, 1.f);

	// Draw the cube
	glDrawArrays(GL_TRIANGLES, 0, 36);
	
}

void BoxMesh::Update()
{
}
