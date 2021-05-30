#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "hyle_profile.h"
#include "hyle_bag.h"

void test_hyle_bag()
{
    uint8_t   bag[HYLE_BAG_SIZE];
    int8_t    color;
    int8_t    i;

    hyle_bag_init(bag);
    hyle_bag_print(bag);
    for (i = 0; i < HYLE_NUM_OF_COUNTER + 1; i++)
    {
        color = hyle_bag_draw_counter(bag);
        printf("hyle_bag_get : %s\n", hyle_get_color(color));
        hyle_bag_print(bag);
        printf("------------------------------------------\n");
    }
}

int main()
{
    test_hyle_bag();
}