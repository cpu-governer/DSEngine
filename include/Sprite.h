#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

#include "vec.h"

class Player
{
public:
	Player();

	void setVelocity(Vector2 vel);

	void update(uint32_t delta);
	void render(SDL_Renderer* target);

private:
	Vector2 accel, velocity;
	AABB boundBox;

	SDL_Texture* sprite;
}

#endif // SPRITE_H