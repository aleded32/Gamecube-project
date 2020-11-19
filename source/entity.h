#pragma once

#include "ship.h"
#include "bullet.h"
#include "enemysmall.h"
#include "score.h"
#include <iostream>
#include "time.h"
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
	float moveSpeed;
	int start;
	
	std::vector<firstBullet> bullets;
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
	
	int randAngle;
	bool hitLeft;
	bool hitRight;
	GRRLIB_texImg* enemySprite;

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
	void draw(int _x, int _y, float width , float height);
	
};

class playerEnt : public entity
{
public:
	
	
	GRRLIB_texImg *playerSprite;
	bool isGameOver;
	

	void MovePlayer();


	void moveBullet();

	void draw(GRRLIB_ttfFont *text); 


	void Bulletcollision(GRRLIB_texImg* text, std::vector<enemyEnt>& enemy, score* ptrScore);

	void enemyCollision(score* ptrScore, std::vector<enemyEnt>& enemy);

	playerEnt(float _x, float _y, float _width, float _height);

	~playerEnt();

	
};