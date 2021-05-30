
/*******************************************************************************

*******************************************************************************/

#ifndef _HYLE_ERROR_H
#define _HYLE_ERROR_H

#ifdef __cplusplus
extern "C"
{
#endif

#define HYLE_SUCCESS              0
#define HYLE_ERROR_INVALID_COLOR -1

#define HYLE_ERROR_INVALID_POS   -2
#define HYLE_ERROR_OCCUPIED_POS  -3

#define HYLE_ERROR_EMPTY_SRC     -4
#define HYLE_ERROR_INVALID_SRC   -5
#define HYLE_ERROR_INVALID_DST   -6
#define HYLE_ERROR_OCCUPIED_DST  -7
#define HYLE_ERROR_INVALID_PATH  -8
#define HYLE_ERROR_BLOCKED_PATH  -9

#ifdef __cplusplus
}
#endif

#endif /* _HYLE_ERROR_H */
