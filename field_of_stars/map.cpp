#include "map.h"

void randomMapGenerate(){//рандомно расставляем камни
    int randomElementX = 0;//переменная для хранения случайного элемента по горизонтали
    int randomElementY = 0;//переменная для хранения случайного элемента по вертикали
    int countStone = 5;//количество камней
    while (countStone>0){
        randomElementX = 1 + rand() % (WIDTH_MAP - 1);//псевдослучайное значение по “x” от 1 до
        //ширина карты-1. Ограничение введено чтобы не получать числа бордюра карты
        randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//по “y”
        if (TileMap[randomElementY][randomElementX] == ' ') {//если встретили символ пробел,
            TileMap[randomElementY][randomElementX] = 's'; //то ставим туда камень.
            countStone--;
        }
    }
};

std::string TileMap[HEIGHT_MAP] = {
   "0000000000000000000000000",
   "0                       0",
   "0    s   s   f          0",
   "0                       0",
   "0                      f0",
   "0                       0",
   "0               s       0",
   "0    00000    h         0",
   "0  h                    0",
   "0                       0",
   "0         f             0",
   "0                       0",
   "0s                      0",
   "0      h                0",
   "0                       0",
   "0              f  s     0",
   "0                       0",
   "0   h       f           0",
   "0                       0",
   "0000000000000000000000000",
};
