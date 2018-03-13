/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:26:14 by alamy             #+#    #+#             */
/*   Updated: 2018/02/14 14:08:08 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *str1, const char *str2)
{
	const char *s1 = str1;
	const char *s2;

	while (*s1)
	{
		s2 = str2;
		while (1)
		{
			if (*s1 == *s2)
				break ;
			else if (*s2++ == '\0')
				return (s1 - str1);
		}
		s1++;
	}
	return (s1 - str1);
}
