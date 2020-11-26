#include "entitySpawner.h"

entitySpawn::entitySpawn()
{

    
    spawnPointX = 675;
    spawnPointY[0] = 20;
    spawnPointY[1] = 188;
    spawnPointY[2] = 345;
    spawnTime = 0;
    randY = 0;
    enemy = new enemyEnt(spawnPointX, spawnPointY[randY], 16.0,16.0);
    enemy->randAngle = 0;
    enemy->hitRight = false;
    enemy->hitLeft = false;
}

entitySpawn::~entitySpawn(){}

void entitySpawn::spawnEnemy()
{
    srand(time(NULL));
    if(spawnTime <= 0)
    {   
        enemy->randAngle = rand()%5;
        enemy->x = 675;
        enemy->y = spawnPointY[randY];
        enemies.push_back(*enemy);
        spawnTime++;
        
    }
    if(spawnTime > 0 && spawnTime <= 20)
    {
        spawnTime++;
    }
    else if(spawnTime >= 20)
    {
        spawnTime = 0;
        for(int i = 0; i < 3; i++)
            randY = rand()%3;
        
    }
    

    for(size_t i = 0; i < enemies.size(); i++)
    {

        if(randY == 0 || enemies[i].y <= 0)
        {
            enemies[i].y += cos(enemies[i].randAngle) * enemies[i].moveSpeed;
        }
        else if(randY == 2 || enemies[i].y >=375)
        {
            enemies[i].y -= cos(enemies[i].randAngle) * enemies[i].moveSpeed;
        }
        
        enemies[i].x -= enemy->moveSpeed;
        
         
      
       
       

       
        
    }

}

void entitySpawn::draw()
{
      for(size_t i = 0; i < enemies.size(); i++)
    {

        enemies[i].draw(enemies[i].x, enemies[i].y, enemies[i].width, enemies[i].height);
       
        
        if(enemies[i].x <= 0)
        {
           enemies.erase(i + enemies.begin());
            
        }
    }
}