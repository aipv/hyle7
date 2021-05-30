#include <stdint.h>
#include <assert.h>
#include "hyle_profile.h"

#ifdef __cplusplus
extern "C"
{
#endif

uint8_t hyle_is_valid_pos(uint8_t pos)
{
    uint8_t   ret;
    ret = (pos < HYLE_NUM_OF_CELL) ? 1 : 0;
    return ret;
}

uint8_t hyle_get_status(uint8_t status)
{
    const static uint8_t hyle_status[HYLE_NUM_OF_STATUS] = HYLE_STATUS;
    assert(status < HYLE_NUM_OF_STATUS);
    return hyle_status[status];
}

uint8_t hyle_get_row(uint8_t pos)
{
    uint8_t   ret;
    assert(pos < HYLE_NUM_OF_CELL);
    ret = (pos / HYLE_DEEP_SIZE) + 1;
    return ret;
}

uint8_t hyle_get_column(uint8_t pos)
{
    uint8_t   ret;
    assert(pos < HYLE_NUM_OF_CELL);
    ret = (pos % HYLE_DEEP_SIZE) + 'A';
    return ret;
}

char *hyle_get_color(uint8_t status)
{
    static char *hyle_colors[HYLE_NUM_OF_STATUS] = HYLE_COLORS;
    assert(status < HYLE_NUM_OF_STATUS);
    return hyle_colors[status];
}

char *hyle_get_player(uint8_t player)
{
    static char *hyle_players[HYLE_NUM_OF_PLAYERS] = HYLE_PLAYERS;
    assert(player < HYLE_NUM_OF_PLAYERS);
    return hyle_players[player];
}

#ifdef __cplusplus
}
#endif