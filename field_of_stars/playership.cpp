#include "playership.h"
#include <iostream>

PlayerShip::PlayerShip(Image &p_image, Image &p_bulletImage, float p_x, float p_y, uint16_t p_w, uint16_t p_h)
    : Unit(p_image, p_bulletImage, p_x, p_y, p_w, p_h, 100, 300)
{
    m_speed = 0.4;
}

void PlayerShip::shoot(std::list<Bullet *>& p_bulletList)
{
    p_bulletList.push_back(new Bullet(m_bulletImage, 90, 0.6f, m_x + (m_w/2) - BULLET_W/2, m_y - BULLET_H, BULLET_W, BULLET_H, 50));
}

void PlayerShip::increaseShootTimer(float p_time, std::list<Bullet*>& p_bulletList)
{
    if(isAlive())
    {
        m_shootTimer += p_time;

        if(m_shootTimer >= m_shootTime && Keyboard::isKeyPressed(Keyboard::Space))
        {
            shoot(p_bulletList);
            m_shootTimer = 0;
        }
    }
}

void PlayerShip::control()
{
    if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::D)){
        m_dx = 0;
    } else
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        m_dx = -m_speed;
    } else
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        m_dx = m_speed;
    } else {
        m_dx = 0;
    }
}

void PlayerShip::update()
{
    if(isAlive())
    {
        control();

        if(m_x <= 10) //Так как игрок может двигаться только вправо и влево ограничеваем
        {              //его только по этим направлениям
            m_x = 10;
        }
        if(m_x + m_w >= 790)
        {
            m_x = 790-m_w;
        }
    } else {
        m_dx = 0;
    }
}

bool PlayerShip::getDamaged(uint16_t p_damage)
{
    std::cout << "Damage: " << p_damage << std::endl;
    std::cout << "Health: " << getHealth()-p_damage << std::endl;
    return Unit::getDamaged(p_damage);
}

