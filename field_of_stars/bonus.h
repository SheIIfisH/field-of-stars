#ifndef BONUS_H_
#define BONUS_H_

#include "entity.h"
#include <stdint.h>

const int BONUS_W = 32;
const int BONUS_H = 32;

class Bonus: public Entity
{
    uint16_t m_recovery;    //сколько здоровья прибавиться игроку
public:
    Bonus(uint16_t p_w, uint16_t p_h, uint16_t p_recovery);
    void update();
    uint16_t getRecovery();
    void setRecovery(uint16_t p_recovery);
};

#endif // BONUS_H
