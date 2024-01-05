#ifndef _HELICOPTER_DATA_H_
#define _HELICOPTER_DATA_H_


#define HELICOPTER_STATE_ENTRY          0
#define HELICOPTER_STATE_TARAN          1
#define HELICOPTER_STATE_BURST_NAHUI    2

struct helicopter
{
    unsigned char x, y;
    unsigned char state;
    unsigned char substate;
    unsigned char timer;
    unsigned char t;
};

/*
    Босс вертолет:
- Стрельба
    движение к рандомной точке, залп из трёх патронов, повторить
- Таран
    преследование игрока, ЛЕТИМ В НЕГО НАХУЙ
- пулемётный обстрел
    полёт на верхнюю часть экрана, дальше поток пуль двигаясь вниз
*/


#endif