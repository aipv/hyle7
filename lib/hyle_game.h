
/*******************************************************************************

*******************************************************************************/

#ifndef _HYLE_GAME_H
#define _HYLE_GAME_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct 
{
	uint8_t     color;
	uint8_t     pos;
	uint8_t     src;
	uint8_t     dst;
} Hyle_Partie;

typedef struct 
{
    uint8_t     move;
    uint8_t     player;
    uint8_t     bag[HYLE_BAG_SIZE];
    uint8_t     board[HYLE_BOARD_SIZE];
    Hyle_Partie partie[HYLE_NUM_OF_MOVE];
} Hyle_Game;

#define HYLE_GAME_SIZE         sizeof(Hyle_Game)

void hyle_game_print(uint8_t *game);
void hyle_game_init(uint8_t *game);
int8_t hyle_game_get_move(uint8_t *game);
int8_t hyle_game_get_player(uint8_t *game);
int8_t hyle_game_draw_counter(uint8_t *game);
int32_t hyle_game_place_counter(uint8_t *game, uint8_t pos);
int32_t hyle_game_slide_counter(uint8_t *game, uint8_t src, uint8_t dst);
uint8_t hyle_game_get_default_position(uint8_t *game);

#ifdef __cplusplus
}
#endif

#endif /* _HYLE_GAME_H */
