#ifndef BATTLESCREEN_H
#define BATTLESCREEN_H

#include <SFML/Graphics.hpp>
#include <list>
#include <ctime>
#include "global.h"
#include "playership.h"
#include "entity.h"
#include "enemy.h"
#include "bullet.h"

using namespace sf;

/*
 * Класс battlecsreen описывает работу игрового экрана и взаимодействия
 * игрока, врагов, снарядов
 */

class BattleScreen
{
private:

    Font createFont();
    void control();
    void updateObjects(float p_time, PlayerShip p_player, std::list<Bullet*> p_plBullets, std::list<Enemy*> p_enemies, std::list<Bullet*> p_enBullets);
    void collisionCheck(PlayerShip p_player, std::list<Bullet*> p_plBullets, std::list<Enemy*> p_enemies, std::list<Bullet*> p_enBullets);
public:
    void play();

};

#endif // BATTLESCREEN_H