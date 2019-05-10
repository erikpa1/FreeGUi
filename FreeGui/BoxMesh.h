#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;

class BoxMesh 
{
public:

	BoxMesh(RenderWindow * window);
	~BoxMesh();

	void Draw();
	void Update();
	
private:

	RenderWindow * _window;



};

