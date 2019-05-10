#pragma once
#include "SFML/Graphics.hpp"
#include "Renderable.h"

static sf::Vector2f GetMiddlePosition(Renderable *parent, Renderable *child)
{
	sf::Vector2f temporary = parent->GetPosition();
	temporary.x = parent->GetPosition().x + parent->GetDimension().x / 2 - parent->GetDimension().x / 2;
	temporary.y = parent->GetPosition().y + parent->GetDimension().y / 2 - parent->GetDimension().y / 2;

	return temporary;

}