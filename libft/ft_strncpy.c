#include "libft.h"

char  *ft_strncpy(char *dst, char *src, size_t size)
{
    size_t  idx;

    idx = 0;
    while (src[idx] && idx < size)
    {
        dst[idx] = src[idx];
        idx++;
    }
    return (dst);
}