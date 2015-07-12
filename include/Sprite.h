#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

#include "vec.h"

class Player
{
public:
	Player();

	void set

private:
	Vector2 velocity;
	AABB boundBox;

	SDL_Texture* sprite;
}

#endif // SPRITE_H