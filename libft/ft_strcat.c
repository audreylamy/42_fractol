/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:15:42 by alamy             #+#    #+#             */
/*   Updated: 2017/11/10 16:07:53 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int y;

	y = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[y + i] = src[i];
		i++;
	}
	dest[y + i] = '\0';
	return (dest);
}
