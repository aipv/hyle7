
/*******************************************************************************

*******************************************************************************/

#ifndef _HYLE_PROFILE_H
#define _HYLE_PROFILE_H

#ifdef __cplusplus
extern "C"
{
#endif

#define HYLE_DEEP_SIZE           (7)
#define HYLE_NUM_OF_PLAYERS      (2)
#define HYLE_NUM_OF_STATUS       (HYLE_DEEP_SIZE + 1)
#define HYLE_NUM_OF_CELL         (HYLE_DEEP_SIZE * HYLE_DEEP_SIZE)
#define HYLE_NUM_OF_COUNTER      (HYLE_DEEP_SIZE * HYLE_DEEP_SIZE)
#define HYLE_NUM_OF_MOVE         (HYLE_DEEP_SIZE * HYLE_DEEP_SIZE)

#define HYLE_BAG_SIZE            (HYLE_NUM_OF_COUNTER + 1)
#define HYLE_BOARD_SIZE          HYLE_NUM_OF_CELL


#define HYLE_PLAYERS             {"Chaos", "Order"}
#define HYLE_STATUS              {' ', 'R', 'O', 'Y', 'G', 'B', 'I', 'V'}
#define HYLE_COLORS              {"", "Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"}

uint8_t hyle_is_valid_pos(uint8_t pos);
uint8_t hyle_get_status(uint8_t status);
uint8_t hyle_get_row(uint8_t pos);
uint8_t hyle_get_column(uint8_t pos);
char *hyle_get_color(uint8_t status);
char *hyle_get_player(uint8_t player);

#ifdef __cplusplus
}
#endif

#endif /* _HYLE_PROFILE_H */
