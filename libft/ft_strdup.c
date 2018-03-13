/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:13:15 by alamy             #+#    #+#             */
/*   Updated: 2017/12/18 13:02:39 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char			*s1;
	unsigned int	i;
	unsigned int	len;
	char			*src1;

	src1 = (char*)src;
	len = 0;
	i = 0;
	while (src1[len])
		len++;
	s1 = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = src[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
