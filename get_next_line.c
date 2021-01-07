/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:52:33 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/05 18:57:25 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*check_remainder(char *reaminder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (reaminder)
		if ((p_n = ft_strchr(reaminder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strjoin(reaminder, "");
			ft_strcpy(reaminder, ++p_n);
		}
		else
		{
			*line = ft_strjoin(reaminder, "");
			while (*reaminder)
				*reaminder++ = '\0';
		}
	else
		*line = ft_strnew(1);
	return (p_n);
}

void	str_join(char **line, char **buf)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(*line, *buf);
	free(tmp);
	free(*buf);
}

int		back(char **buf)
{
	free(*buf);
	return (-1);
}

void    ream(char **p_n, char **reaminder)
{
	char *tmp;

	**p_n = '\0';
	++*p_n;
	tmp = *reaminder;
	*reaminder = ft_strjoin(*p_n, "");
	free(tmp);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	int				byte_was_read;
	char			*p_n;
	static char		*remainder;

	byte_was_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	p_n = check_remainder(remainder, line);
	while (!p_n && byte_was_read > 0)
	{
		if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		|| (byte_was_read = read(fd, buf, BUFFER_SIZE)) == -1)
			return (back(&buf));
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
			ream(&p_n,&remainder);
		str_join(line, &buf);
	}
	return ((byte_was_read == 0) ? 0 : 1);
}
