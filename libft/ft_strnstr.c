/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:50:32 by alamy             #+#    #+#             */
/*   Updated: 2017/11/17 18:23:31 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;
	size_t			tmp;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		tmp = i;
		while (s1[i] == s2[j] && i < n)
		{
			if (s2[j + 1] == '\0')
			{
				return ((char *)&s1[tmp]);
			}
			i++;
			j++;
		}
		i = tmp;
		i++;
	}
	return (NULL);
}
