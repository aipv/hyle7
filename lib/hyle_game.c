#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "hyle_profile.h"
#include "hyle_board.h"
#include "hyle_bag.h"
#include "hyle_game.h"

#ifdef __cplusplus
extern "C"
{
#endif

void hyle_game_print(uint8_t *game)
{
    Hyle_Game    *G;
    G = (Hyle_Game *)game;
    printf("-------- Move : %d, Score : %d --------\n",
        G->move, hyle_board_calculate_score(G->board));
    hyle_board_print(G->board);
}

void hyle_game_init(uint8_t *game)
{
    Hyle_Game    *G;
    G = (Hyle_Game *)game;
    G->move = 0;
    G->player = 0;
    hyle_bag_init(G->bag);
    hyle_board_init(G->board);
}

int8_t hyle_game_get_move(uint8_t *game)
{
    Hyle_Game    *G;
    uint8_t      move;
    G = (Hyle_Game *)game;
    move = G->move;
    return move;
}

int8_t hyle_game_get_player(uint8_t *game)
{
    Hyle_Game    *G;
    uint8_t      player;
    G = (Hyle_Game *)game;
    player = G->player;
    return player;
}

int8_t hyle_game_draw_counter(uint8_t *game)
{
    Hyle_Game    *G;
    uint8_t      color;
    uint8_t      move;

    G = (Hyle_Game *)game;
    move = G->move;
    color = hyle_bag_draw_counter(G->bag);
    G->partie[move].color = color;
    return color;
}

int32_t hyle_game_place_counter(uint8_t *game, uint8_t pos)
{
    Hyle_Game    *G;
    uint8_t      move;
    int32_t      ret;

    G = (Hyle_Game *)game;
    move = G->move;
    ret = hyle_board_place_counter(G->board, G->partie[move].color, pos);
    if (ret < 0)
    {
        printf("Error place counter : %d %d %d\n", ret, G->partie[move].color, pos);
    }
    else
    {
        G->partie[move].pos = pos;
        G->player = 1;
    }
}

int32_t hyle_game_slide_counter(uint8_t *game, uint8_t src, uint8_t dst)
{
    Hyle_Game    *G;
    uint8_t      move;
    int32_t      ret;

    G = (Hyle_Game *)game;
    move = G->move;
    ret = hyle_board_slide_counter(G->board, src, dst);
    if (ret < 0)
    {
        printf("Error slide counter : %d %d %d\n", ret, src, dst);
    }
    else
    {
        G->partie[move].src = src;
        G->partie[move].dst = dst;
        G->player = 0;
        G->move++;
    }
}

uint8_t hyle_game_get_default_position(uint8_t *game)
{
    Hyle_Game    *G;
    uint8_t      ret;
    G = (Hyle_Game *)game;
    ret = hyle_board_get_default_position(G->board);
    return ret;
}


#ifdef __cplusplus
}
#endif