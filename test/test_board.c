#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "hyle_profile.h"
#include "hyle_board.h"

void test_hyle_board()
{
    uint8_t   board[HYLE_BOARD_SIZE];
    int8_t    ret;

    hyle_board_init(board);
    hyle_board_print(board);
    ret = hyle_board_validate_place(board, 3, 22);
    printf("Validation Add 3 to 22 : %d\n", ret);
    hyle_board_place_counter(board, 3, 22);    
    hyle_board_print(board);
    ret = hyle_board_validate_slide(board, 22, 9);
    printf("Validation 22 => 9 : %d\n", ret);
    ret = hyle_board_validate_slide(board, 22, 36);
    printf("Validation 22 => 36 : %d\n", ret);
    hyle_board_slide_counter(board, 22, 36);    
    hyle_board_print(board);
    ret = hyle_board_validate_slide(board, 36, 36);
    printf("Validation 36 => 36 : %d\n", ret);
    hyle_board_slide_counter(board, 36, 36);    
    hyle_board_print(board);
}

int main()
{
    test_hyle_board();
}