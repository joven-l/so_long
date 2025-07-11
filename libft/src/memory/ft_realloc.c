/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:57:40 by joloo             #+#    #+#             */
/*   Updated: 2025/07/07 18:55:53 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// modifying an array to have more memory size but contents are the same
// Null terminator is at the same place
// auto adds null terminator so is new_size + 1
// frees the old buffer for you
// currently only works on strings
char	*ft_realloc(char **buffer, int start, int old_size, int new_size)
{
	char	*newbuf;
	int		i;

	newbuf = malloc(sizeof(char) * (new_size + 1));
	if (newbuf == NULL)
	{
		return (NULL);
	}
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
	newbuf[i] = '\0';
	*buffer = newbuf;
	return (newbuf);
}
