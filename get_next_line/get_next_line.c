/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:31:38 by atabala           #+#    #+#             */
/*   Updated: 2018/11/27 11:37:27 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				errcheck(int fd, char **line, char *buffer)
{
	if (!line || (read(fd, buffer, 0) == -1) || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	return (1);
}

int				errcheck2(int bts)
{
	if (bts == -1)
		return (-1);
	return (1);
}

char			*metoddcp(char *buffer, char *temporary, char *temporary2)
{
	free(buffer);
	buffer = temporary2;
	free(temporary);
	return (buffer);
}

int				charcopy(int const fd, char **buffer, int mode)
{
	int		bts;
	char	*temporary;
	char	*temporary2;

	if (mode == 1)
	{
		temporary = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		if (temporary == NULL)
			return (-1);
		bts = read(fd, temporary, BUFF_SIZE);
		if (errcheck2(bts) == -1)
			return (-1);
		temporary[bts] = '\0';
		temporary2 = ft_strjoin(*buffer, temporary);
		*buffer = metoddcp(*buffer, temporary, temporary2);
		return (bts);
	}
	if (mode == 2)
	{
		if (*buffer == NULL)
			return (0);
		ft_strdel(buffer);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buffer = NULL;
	char			*temporary;
	int				bts;

	bts = 1;
	if (errcheck(fd, line, buffer) == -1)
		return (-1);
	if (!buffer)
		buffer = ft_strnew(0);
	while (ft_strchr(buffer, '\n') == NULL && bts != 0)
		bts = charcopy(fd, &buffer, 1);
	if (errcheck2(bts) == -1)
		return (-1);
	if ((temporary = ft_strchr(buffer, '\n')) != NULL)
	{
		temporary[0] = '\0';
		*line = ft_strdup(buffer);
		ft_memmove(buffer, temporary + 1, ft_strlen(temporary + 1) + 1);
		return (1);
	}
	*line = buffer;
	charcopy(fd, &buffer, 2);
	if (ft_strlen(*line) > 0)
		return (1);
	return (0);
}
