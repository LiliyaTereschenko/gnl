/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:54:27 by kkihn             #+#    #+#             */
/*   Updated: 2018/12/04 15:23:28 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int validation(int fd, char **line, char **s)
{
    if (fd < 0 || line == NULL)
		return (-1);
	if (!*s)
	{
		if (!(*s = ft_strnew(1)))
			return (-1);
	}
	else
		*s = ft_strjoin(*s, "");
    return (0);
}

int     get_next_line(const int fd, char **line)
{
	static char *s[258];
	int         i;
	char        buf[BUFF_SIZE + 1];
	int         ret;
	char        *temp;

	ret = 1;
	if (validation(fd, line, &s[fd]) == -1)
        return (-1);
    while (ft_strchr(s[fd], '\n') == NULL && ret > 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[ret] = '\0';
		temp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = temp;
	}
	i = 0;
	if (s[fd][i])
	{
		while (s[fd][i] != '\n' && s[fd][i])
			i++;
		(*line) = (i == 0) ? ft_strdup("") : ft_strsub(s[fd], 0, i);
		s[fd] = &s[fd][i + 1];
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}
