#include "enemy.h"
#include <cmath>
#include "global.h"

Enemy::Enemy(uint16_t p_w, uint16_t p_h, std::string p_type)
    : Unit(rand()%(SCREEN_W - p_w - 20) + 10, rand()%(SCREEN_H - p_h - 220) + 10, p_w, p_h, 50, 1200)
{
    m_type = p_type;
    m_cost = 100;
    m_speed = 0.15;
    m_dir = rand()%360; // Случайный начальный угол

    if(m_dir > 45 && m_dir <= 90) // Уменьшаем угол, если он слишком крутой
        m_dir = 45;
    if(m_dir > 90 && m_dir <= 135)
        m_dir = 135;
    if(m_dir < -45 && m_dir >= -90)
        m_dir = -45;
    if(m_dir < 90 && m_dir >= 135)
        m_dir = -135;

    m_dx = m_speed * cos((float)m_dir/180 * PI);
    m_dy = -m_speed * sin((float)m_dir/180 * PI);

    if(m_type == "threebullet")
    {
        m_cost = 150;
        m_shootTime = 1500;
    } else
    if(m_type == "strong")
    {
        m_cost = 200;
        m_shootTime = 1000;
        m_speed = 0.2;
        setHealth(100);
    }

    m_shootTimer = rand()%m_shootTime; // Задаем случайное начальное значение для таймера
    // чтобы враги не стреляли одновременно
}

void Enemy::shoot(std::list<Bullet *> &p_bulletList)
{
    if(m_type == "threebullet")
    {
        p_bulletList.push_back(new Bullet(-60, 0.4f, m_x + (m_w - BULLET_W)/2, m_y + m_h, BULLET_W, BULLET_H, 15));
        p_bulletList.back()->setImage(m_bulletImage);
        p_bulletList.push_back(new Bullet(-90, 0.4f, m_x + (m_w - BULLET_W)/2, m_y + m_h, BULLET_W, BULLET_H, 15));
        p_bulletList.back()->setImage(m_bulletImage);
        p_bulletList.push_back(new Bullet(-120, 0.4f, m_x + (m_w - BULLET_W)/2, m_y + m_h, BULLET_W, BULLET_H, 15));
        p_bulletList.back()->setImage(m_bulletImage);
    } else
        if(m_type == "strong")
        {
            p_bulletList.push_back(new Bullet(-90, 0.5f, m_x + (m_w - BULLET_W)/2, m_y + m_h, BULLET_W, BULLET_H, 30));
            p_bulletList.back()->setImage(m_bulletImage);
        } else
        {
            p_bulletList.push_back(new Bullet(-90, 0.45f, m_x + (m_w - BULLET_W)/2, m_y + m_h, BULLET_W, BULLET_H, 20));
            p_bulletList.back()->setImage(m_bulletImage);
        }
}

void Enemy::update()
{
    if(isAlive())
    {
        bool angleChanged = false; // Объявляем флаг изменения направления чтобы пересчитывать
                                   // скорости только когда направление меняется

        if (m_x <= 10){ // Столкновение с левой границей
            m_x = 10;
            m_dir = 180 - m_dir + (rand()% 10 - 5); // Изменяем направление движения
            angleChanged = true;
        }
        if (m_y <= 10){ // Столкновение с верхней границей
            m_y = 10;
            m_dir = - m_dir + (rand()% 10 - 5);
            angleChanged = true;
        }
        if (m_x + m_w >= SCREEN_W - 10){ // Столкновение с правой границей
            m_x = SCREEN_W - 10 - m_w;
            m_dir = 180 - m_dir + (rand()% 10 - 5);
            angleChanged = true;
        }
        if (m_y + m_h >= SCREEN_H-210){ // Столкновение с нижней границей
            m_y = SCREEN_H - 210 - m_h;
            m_dir = - m_dir + (rand()% 10 - 5);
            angleChanged = true;
        }

        if(angleChanged)
        {
            if(m_dir >=  360) m_dir -= 360;
            if(m_dir <= -360) m_dir += 360;

            if(m_dir > 45 && m_dir <= 90) // Уменьшаем угол, если он становится слишком крутым
                m_dir = 45;
            if(m_dir > 90 && m_dir <= 135)
                m_dir = 135;
            if(m_dir < -45 && m_dir >= -90)
                m_dir = -45;
            if(m_dir < 90 && m_dir >= 135)
                m_dir = -135;

            m_dx = m_speed * cos((float)m_dir/180 * PI);
            m_dy = -m_speed * sin((float)m_dir/180 * PI);
        }
    }
}

uint16_t Enemy::getCost()
{
    return m_cost;
}

