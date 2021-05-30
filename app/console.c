#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "hyle_profile.h"
#include "hyle_game.h"

uint8_t hyle_console_read(char *output)
{
    uint8_t pSize;

    pSize = 0;
    output[pSize] = getchar();
    while(output[pSize] != '\n')
    {
        pSize++;
        output[pSize] = getchar();
    }
    pSize++;
    output[pSize] = 0;

    return pSize;
}

uint8_t hyle_console_read_pos(uint8_t color, uint8_t defaultPos)
{
    uint8_t buff[256];
    uint8_t bSize;
    uint8_t pos;

    while(1)
    {
        printf("Get a Counter in color : %s(%c)\n", hyle_get_color(color), hyle_get_status(color));
        printf("Please place the %s Counter into an idle position, by default [%c%d] : ",
            hyle_get_color(color), hyle_get_column(defaultPos), hyle_get_row(defaultPos));
        bSize = hyle_console_read(buff);
        if (bSize < 2)
        {
            return defaultPos;
        }
        if ((bSize >= 2) && (buff[0] >= 'A') && (buff[0] <= 'G') && (buff[1] >= '1') && (buff[1] <= '7'))
        {
            pos = (buff[0] - 'A') + (buff[1] - '1') * HYLE_DEEP_SIZE;
            if (hyle_is_valid_pos(pos))
            {
                return pos;
            }
        }
    }
}

void hyle_console_read_src_dst(uint8_t *src, uint8_t *dst)
{
    uint8_t buff[256];
    uint8_t bSize;
    uint8_t pos;

    while(1)
    {
        printf("Place slide a Counter between two positions, by default [A1A1]: ");
        bSize = hyle_console_read(buff);
        if (bSize < 2)
        {
            *src = 0;
            *dst = 0;
            return;
        }
        if ((bSize >= 4) && (buff[0] == 'P') && (buff[1] == 'A') && (buff[2] == 'S') && (buff[3] == 'S'))
        {
            *src = 0;
            *dst = 0;
            return;
        }
        if ((bSize >= 4) && (buff[0] >= 'A') && (buff[0] <= 'G') && (buff[1] >= '1') && (buff[1] <= '7')
            && (buff[2] >= 'A') && (buff[2] <= 'G') && (buff[3] >= '1') && (buff[3] <= '7'))
        {
            *src = (buff[0] - 'A') + (buff[1] - '1') * HYLE_DEEP_SIZE;
            *dst = (buff[2] - 'A') + (buff[3] - '1') * HYLE_DEEP_SIZE;
            return;
        }
    }
}


void hyle_console_game()
{
    uint8_t   game[HYLE_GAME_SIZE];
    uint8_t   defaultPos;
    uint8_t   color;
    uint8_t   move;
    uint8_t   pos;
    uint8_t   src;
    uint8_t   dst;
    uint8_t   ret;

    hyle_game_init(game);
    while(hyle_game_get_move(game) < HYLE_NUM_OF_MOVE - 1)
    {
        hyle_game_print(game);
        color = hyle_game_draw_counter(game);
        defaultPos = hyle_game_get_default_position(game);
        while (hyle_game_get_player(game) == 0)
        {
            pos = hyle_console_read_pos(color, defaultPos);
            hyle_game_place_counter(game, pos);
        }
        hyle_game_print(game);
        while (hyle_game_get_player(game) != 0)
        {
            hyle_console_read_src_dst(&src, &dst);
            hyle_game_slide_counter(game, src, dst);
        }
    }

    color = hyle_game_draw_counter(game);
    pos = hyle_game_get_default_position(game);
    hyle_game_place_counter(game, pos);
    hyle_game_print(game);
    printf("Game End!\n");
}

int main()
{
    hyle_console_game();
}