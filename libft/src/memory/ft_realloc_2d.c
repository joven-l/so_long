/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:34:22 by joloo             #+#    #+#             */
/*   Updated: 2025/07/07 18:55:27 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// auto null terminate unlike ft_realloc (no 2d)
char	**ft_realloc_2d(char ***buffer, int start, int old_size, int new_size)
{
	char	**newbuf;
	int		i;

	newbuf = malloc(sizeof(char *) * (new_size + 1));
	if (newbuf == NULL)
		return (NULL);
	i = 0;
	if (*buffer != NULL)
	{
		while (i < old_size && i < new_size)
		{
			newbuf[i] = (*buffer)[i + start];
			i++;
		}
		free(*buffer);
	}
	newbuf[i] = NULL;
	*buffer = newbuf;
	return (newbuf);
}

// int	main(void)
// {
// 	char **arr;

// 	arr = ft_calloc(sizeof(char *) , (1));
// 	arr = ft_realloc_2d(&arr, 0, 1, 2);
// 	arr[1] = "errmm";
// 	ft_printf("%s\n%s\n", arr[0], arr[1]);
// }
