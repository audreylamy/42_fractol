/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:23:41 by alamy             #+#    #+#             */
/*   Updated: 2017/11/10 16:11:30 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		y;
	size_t	j;

	j = 0;
	y = 0;
	i = 0;
	while (dest[y] != '\0')
		y++;
	while ((src[i] != '\0') && (j < n))
	{
		dest[y + i] = src[i];
		i++;
		j++;
	}
	dest[y + i] = '\0';
	return (dest);
}
