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
			*line = ft_strdup(reaminder);
			ft_strcpy(reaminder, ++p_n);
		}
		else
		{
			*line = ft_strdup(reaminder);
			while (*reaminder)
				*reaminder++ = '\0';
		}
	else
		*line = ft_strnew(1);
	return (p_n);
}

char	*str_join(char **line, char **buf, char **p_n)
{
	char *tmp;
	char *remainder = NULL;

	if ((p_n = (char **) ft_strchr((const char *) buf, '\n')))
	{
		**p_n = '\0';
		++p_n;
		tmp = remainder;
		remainder = ft_strdup((char *) p_n);
		free(tmp);
	} else
	{
		tmp = *line;
		*line = ft_strjoin(*line, *buf);
		free(tmp);
		free(*buf);
	}
	return remainder;
}

int		back(char **buf)
{
	free(*buf);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	int				byte_was_read;
	char			*p_n;
	static char		*remainder;
//	char *tmp;

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
//		if ((p_n = ft_strchr(buf, '\n')))
//		{
//			*p_n = '\0';
//			++p_n;
//			tmp = remainder;
//			remainder = ft_strdup(p_n);
//			free(tmp);
//		}
		remainder = str_join(line, &buf,&p_n);
	}
	return ((byte_was_read == 0) ? 0 : 1);
}
