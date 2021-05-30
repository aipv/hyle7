
/*******************************************************************************

*******************************************************************************/

#ifndef _HYLE_BOARD_H
#define _HYLE_BOARD_H

#ifdef __cplusplus
extern "C"
{
#endif

void hyle_board_print(uint8_t *board);
void hyle_board_init(uint8_t *board);
int32_t hyle_board_place_counter(uint8_t *board, uint8_t color, uint8_t position);
int32_t hyle_board_slide_counter(uint8_t *board, uint8_t src, uint8_t dst);
int8_t hyle_board_validate_place(uint8_t *board, uint8_t color, uint8_t position);
int8_t hyle_board_validate_slide(uint8_t *board, uint8_t src, uint8_t dst);
uint8_t hyle_board_get_default_position(uint8_t *board);
uint32_t hyle_board_calculate_score(uint8_t *board);

#ifdef __cplusplus
}
#endif

#endif /* _HYLE_BOARD_H */
