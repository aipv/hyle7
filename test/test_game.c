#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "hyle_profile.h"
#include "hyle_game.h"

void test_hyle_game()
{
    uint8_t   game[HYLE_GAME_SIZE];
    uint8_t   color;

    hyle_game_init(game);
    hyle_game_draw_counter(game);
    hyle_game_place_counter(game, 23);
    hyle_game_slide_counter(game, 23, 22);
    hyle_game_print(game);

    hyle_game_draw_counter(game);
    hyle_game_place_counter(game, 18);
    hyle_game_slide_counter(game, 18, 25);
    hyle_game_print(game);

    hyle_game_draw_counter(game);
    hyle_game_place_counter(game, 17);
    hyle_game_slide_counter(game, 17, 19);
    hyle_game_print(game);

}

int main()
{
    test_hyle_game();
}