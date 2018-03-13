/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:41:17 by alamy             #+#    #+#             */
/*   Updated: 2017/11/14 13:25:09 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(*str) * size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i++] = '\0';
	}
	str[i] = '\0';
	return (str);
}
