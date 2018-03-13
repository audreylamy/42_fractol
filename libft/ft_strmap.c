/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:35:28 by alamy             #+#    #+#             */
/*   Updated: 2017/11/17 18:58:34 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*strnew;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	size = ft_strlen((char *)s);
	strnew = (char *)malloc(sizeof(*strnew) * size + 1);
	if (!strnew)
		return (NULL);
	if (s == NULL && f == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		strnew[j] = (*f)(s[i]);
		i++;
		j++;
	}
	strnew[i] = '\0';
	return (strnew);
}
