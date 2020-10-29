#pragma once

#include "ship.h"
#include "bullet.h"
#include <iostream>
#include <vector>
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>




#define GRRLIB_BLACK     0x000000FF
#define GRRLIB_RED		 0xFF0000FF
#define GRRLIB_WHITE     0xFFFFFFFF

class entity
{
    
public:

	entity(){}
    ~entity(){}

    float x, y, width, height;
	int start;
	std::vector<firstBullet*> bullets;
	firstBullet* pBullet;

    int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	int getWidth()
	{
		return width;
	}
	
	int getHeight()
	{
		return height;
	}


};

class enemyEnt : public entity
{
public:
	

	enemyEnt(float _x, float _y, float _width, float _height);

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	int getWidth()
	{
		return width;
	}
	
	int getHeight()
	{
		return height;
	}

	~enemyEnt();

	void draw();
	
};

class playerEnt : public entity
{
public:
	
	float moveSpeed;
	GRRLIB_texImg *playerSprite;
	
	
	

	void MovePlayer();


	void moveBullet();

	void draw(GRRLIB_ttfFont *text); 


	void collision(int enemyX, int enemyY, int enemyW, int enemyH, GRRLIB_texImg* text);

	playerEnt(float _x, float _y, float _width, float _height);

	~playerEnt();

	
};