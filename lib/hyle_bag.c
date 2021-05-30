#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "hyle_error.h"
#include "hyle_profile.h"
#include "hyle_bag.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hyle_bag_print(uint8_t *bag)
{
    uint8_t   i;

    printf("Counters in Bag (%d) : ", bag[0]);
    for (i = 0; i < bag[0]; i++)
    {
        printf("%c ", hyle_get_status(bag[i+1]));
    }
    printf("\n");
}

void hyle_bag_init(uint8_t *bag)
{
    uint8_t   i;

    bag[0] = HYLE_NUM_OF_COUNTER;
    for (i = 0; i < HYLE_NUM_OF_COUNTER; i++)
    {
        bag[i + 1] = i / HYLE_DEEP_SIZE + 1;
    }
}

int8_t hyle_bag_draw_counter(uint8_t *bag)
{
    uint8_t   color;
    uint8_t   dice;
    uint8_t   i;

    if (bag[0] == 0)
    {
        return 0;
    }

    srand (time(NULL));
    dice = (uint8_t)((rand() % bag[0]) + 1); /* random value between 1 ~ num_of_counter */
    color = bag[dice];
    for (i = dice; i < bag[0]; i++)
    {
        bag[i] = bag[i + 1];
    }
    bag[0]--;

    return color;
}

uint8_t hyle_bag_get_size(uint8_t *bag)
{
    return bag[0];
}

#ifdef __cplusplus
}
#endif