#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "hyle_error.h"
#include "hyle_profile.h"
#include "hyle_board.h"

#ifdef __cplusplus
extern "C"
{
#endif

uint8_t hyle_board_is_path_blocked(uint8_t *board, uint8_t src, uint8_t dst)
{
    uint8_t   step;
    uint8_t   ret;
    uint8_t   i;

    step = ((src / HYLE_DEEP_SIZE) == (dst / HYLE_DEEP_SIZE)) ? 1 : HYLE_DEEP_SIZE;
    ret = 0;
    if (dst < src)
    {
        for (i = dst; i < src; i += step)
        {
            ret += board[i];
        }
    }
    else
    {
        for (i = dst; i > src; i -= step)
        {
            ret += board[i];
        }
    }

    return ret;
}

int8_t hyle_board_validate_slide(uint8_t *board, uint8_t src, uint8_t dst)
{
    if (src == dst)
    {
        return HYLE_SUCCESS;
    }
    if (src >= HYLE_NUM_OF_CELL)
    {
        return HYLE_ERROR_INVALID_SRC;
    }
    if (dst >= HYLE_NUM_OF_CELL)
    {
        return HYLE_ERROR_INVALID_DST;
    }
    if (board[src] == 0)
    {
        return HYLE_ERROR_EMPTY_SRC;
    }
    if (board[dst] != 0)
    {
        return HYLE_ERROR_OCCUPIED_DST;
    }
    if (((src / HYLE_DEEP_SIZE) != (dst / HYLE_DEEP_SIZE)) && ((src % HYLE_DEEP_SIZE) != (dst % HYLE_DEEP_SIZE)))
    {
        return HYLE_ERROR_INVALID_PATH;
    }
    if (hyle_board_is_path_blocked(board, src, dst) > 0)
    {
        return HYLE_ERROR_BLOCKED_PATH;
    }
    return HYLE_SUCCESS;
}

int8_t hyle_board_validate_place(uint8_t *board, uint8_t color, uint8_t position)
{
    if ((color == 0) || (color >= HYLE_NUM_OF_STATUS))
    {
        return HYLE_ERROR_INVALID_COLOR;
    }
    if (position >= HYLE_NUM_OF_CELL)
    {
        return HYLE_ERROR_INVALID_POS;
    }
    if (board[position] != 0)
    {
        return HYLE_ERROR_OCCUPIED_POS;
    }

    return HYLE_SUCCESS;
}

void hyle_board_print(uint8_t *board)
{
    uint8_t   i;

    printf("  +---+---+---+---+---+---+---+\n");
    for (i = 0; i < HYLE_DEEP_SIZE; i++)
    {
        printf("%d | %c | %c | %c | %c | %c | %c | %c |\n", HYLE_DEEP_SIZE - i,
            hyle_get_status(board[(6 - i) * HYLE_DEEP_SIZE + 0]),
            hyle_get_status(board[(6 - i) * HYLE_DEEP_SIZE + 1]),
            hyle_get_status(board[(6 - i) * HYLE_DEEP_SIZE + 2]),
            hyle_get_status(board[(6 - i) * HYLE_DEEP_SIZE + 3]),
            hyle_get_status(board[(6 - i) * HYLE_DEEP_SIZE + 4]),
            hyle_get_status(board[(6 - i) * HYLE_DEEP_SIZE + 5]),
            hyle_get_status(board[(6 - i) * HYLE_DEEP_SIZE + 6])
        );
        printf("  +---+---+---+---+---+---+---+\n");
    }
    printf("    A   B   C   D   E   F   G\n");
}

void hyle_board_init(uint8_t *board)
{
    uint8_t   i;

    for (i = 0; i < HYLE_NUM_OF_CELL; i++)
    {
        board[i] = 0;
    }
}

int32_t hyle_board_place_counter(uint8_t *board, uint8_t color, uint8_t position)
{
    int32_t    ret;

    ret = hyle_board_validate_place(board, color, position);
    if (ret == HYLE_SUCCESS)
    {
        board[position] = color;
    }
    return ret;
}

int32_t hyle_board_slide_counter(uint8_t *board, uint8_t src, uint8_t dst)
{
    int32_t    ret;

    ret = hyle_board_validate_slide(board, src, dst);
    if ((ret == HYLE_SUCCESS) && (src != dst))
    {
        board[dst] = board[src];
        board[src] = 0;
    }
    return ret;
}

uint8_t hyle_board_get_default_position(uint8_t *board)
{
    uint8_t    i;

    for (i = 0; i < HYLE_NUM_OF_CELL; i++)
    {
        if (board[i] == 0)
        {
            return i;
        }
    }
    return i;
}

uint32_t hyle_item_calculate_score(uint8_t *item, uint8_t offset)
{
    uint32_t   i;

    for (i = 0; i < (offset + 1) / 2; i++)
    {
        if ((item[i] == 0) || (item[offset - i] == 0) || (item[i] != item[offset-i]))
        {
            return 0;
        }
    }

    return offset + 1;
}

uint32_t hyle_line_calculate_score(uint8_t *line, uint8_t size)
{
    uint32_t   ret;
    uint32_t   i;
    uint32_t   j;

    ret = 0;
    for (i = 0; i < size; i++)
    {
        for (j = i+1; j < size; j++)
        {
            ret += hyle_item_calculate_score(line + i, j - i);
        }
    }
    return ret;
}

uint32_t hyle_board_calculate_score(uint8_t *board)
{
    uint8_t    line[HYLE_DEEP_SIZE];
    uint32_t   ret;
    uint32_t   i;
    uint32_t   j;

    ret = 0;
    for (i = 0; i < HYLE_DEEP_SIZE; i++)
    {
        ret += hyle_line_calculate_score(board + HYLE_DEEP_SIZE * i, HYLE_DEEP_SIZE);
    }
    for (i = 0; i < HYLE_DEEP_SIZE; i++)
    {
        for (j = 0; j < HYLE_DEEP_SIZE; j++)
        {
            line[j] = board[HYLE_DEEP_SIZE * j + i];
        }
        ret += hyle_line_calculate_score(line, HYLE_DEEP_SIZE);
    }

    return ret;
}

#ifdef __cplusplus
}
#endif