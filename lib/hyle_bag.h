
/*******************************************************************************

*******************************************************************************/

#ifndef _HYLE_BAG_H
#define _HYLE_BAG_H

#ifdef __cplusplus
extern "C"
{
#endif

void hyle_bag_print(uint8_t *bag);
void hyle_bag_init(uint8_t *bag);
int8_t hyle_bag_draw_counter(uint8_t *bag);
uint8_t hyle_bag_get_size(uint8_t *bag);

#ifdef __cplusplus
}
#endif

#endif /* _HYLE_BAG_H */
