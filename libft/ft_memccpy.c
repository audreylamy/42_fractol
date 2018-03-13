/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:27:54 by alamy             #+#    #+#             */
/*   Updated: 2017/11/14 12:55:13 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dest1;
	unsigned char	*src1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		if (c1 == (dest1[i]))
		{
			return ((unsigned char*)&dest1[i + 1]);
		}
		i++;
	}
	return (NULL);
}
