#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include <stdint.h>
#include <list>
#include "bullet.h"
#include "unit.h"

using namespace sf;

const int PLAYER_W = 64;
const int PLAYER_H = 64;

/*
 * Класс PlayerShip описывает юнит, который находится под управлением игрока
 */

class PlayerShip :public Unit
{
private:
    void control(); // Функция, где происходит считывание нажатий клавиш игроком
    virtual void shoot(std::list<Bullet *>& p_bulletList); // Используется лист, так как пуль может быть несколько

public:
    PlayerShip(float p_x, float p_y, uint16_t p_w, uint16_t p_h);
    void update(); // Эта функция отвечает за изменение скорости и направления движения
                   // Определяет траекторию движения объекта
    void increaseShootTimer(float p_time, std::list<Bullet*>& p_bulletList); // Добавляем время в таймер выстрела.
                                                    // Если выстрел произошел метод добавляет пули в лист
                                                    // Используется лист, потому что пуль может быть больше чем одна.
    void die();
};

#endif // PLAYER_H
