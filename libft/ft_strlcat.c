/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:28:53 by alamy             #+#    #+#             */
/*   Updated: 2017/11/17 18:53:34 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	resultat;

	i = 0;
	j = 0;
	resultat = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != '\0' && i < size)
	{
		i++;
	}
	if (size == i)
	{
		return (size + ft_strlen(src));
	}
	while (i != (size - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (resultat);
}
