/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:36:58 by alamy             #+#    #+#             */
/*   Updated: 2017/11/17 18:52:43 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*strnew;
	int		len;
	int		compteur;
	int		i;

	if (!s || !f)
		return (0);
	len = ft_strlen((char *)s);
	i = 0;
	compteur = 0;
	strnew = (char *)malloc(sizeof(*strnew) * (len + 1));
	if (s == NULL && f == NULL)
		return (NULL);
	if (!strnew)
		return (NULL);
	while (s[i])
	{
		strnew[i] = f(compteur, s[i]);
		i++;
		compteur++;
	}
	strnew[i] = '\0';
	return (strnew);
}
