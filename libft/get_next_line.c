/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:36:19 by alamy             #+#    #+#             */
/*   Updated: 2018/02/15 16:13:16 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 32

static	char	*ft_s_to_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	str = ft_strsub(str, 0, i);
	return (str);
}

static	char	*ft_n_to_end(char *str)
{
	int		i;
	int		end;
	char	*tmp;

	i = 0;
	end = ft_strlen(str);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	tmp = ft_strsub(str, i + 1, end);
	free(str);
	return (tmp);
}

static	char	*ft_join_free(char *str, char *buffer, int nb)
{
	char	*tmp;

	buffer[nb] = '\0';
	tmp = ft_strjoin(str, buffer);
	free(str);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				nb;
	char			buffer[BUFF_SIZE + 1];
	static	char	*str[OPEN_MAX];

	if (fd < 0 || !line || fd > OPEN_MAX)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(BUFF_SIZE);
	while ((!ft_strchr(str[fd], '\n')) &&
	(nb = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		str[fd] = ft_join_free(str[fd], buffer, nb);
	}
	if (nb == -1)
		return (-1);
	*line = ft_strchr(str[fd], '\n') ? ft_s_to_n(str[fd]) : ft_strdup(str[fd]);
	if (ft_strchr(str[fd], '\n'))
		str[fd] = ft_n_to_end(str[fd]);
	else
	{
		if (nb == 0 && *str[fd] == '\0')
			return (0);
		ft_strdel(&str[fd]);
	}
	return (1);
}
