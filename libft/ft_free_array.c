#include "libft.h"

void	*ft_free_array(void **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_free(arr[i], ft_strlen(arr[i]));
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}
