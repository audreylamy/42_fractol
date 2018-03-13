/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:05:50 by alamy             #+#    #+#             */
/*   Updated: 2017/11/16 14:57:16 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int			len;
	int			negatif;
	char		*string;

	negatif = ft_negative(n);
	len = ft_len(n);
	string = (char *)malloc(sizeof(char) * len + 1);
	if (!string)
		return (NULL);
	string[len] = '\0';
	len--;
	while (len >= 0)
	{
		string[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (negatif == -1)
		string[0] = '-';
	return (string);
}
