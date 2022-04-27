#include "libft.h"

void	ft_free(void *arr, size_t len)
{
	if (!arr)
		return ;
	ft_bzero(arr, len);
	free(arr);	
}
