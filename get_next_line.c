/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:54:27 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/29 12:54:48 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readcontent(char *s, int fd)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		s = ft_strjoin(s, buf);
	}
	int i = 0;
	while (i < BUFF_SIZE + 1)
	{
		buf[i] = 0;
		i++;
	}
	return (s);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[258];
	int			i;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!s[fd])
		if (!(s[fd] = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	s[fd] = readcontent(s[fd], fd);
	if (s[fd] == NULL)
		return (-1);
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
