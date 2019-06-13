/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:14:31 by atabala           #+#    #+#             */
/*   Updated: 2019/06/08 15:34:07 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	inv(void)
{
	ft_putstr("Invalid map\n");
	exit(0);
}

static void	kostil(char *line, char *line2, int i, t_pr *w)
{
	int		k;

	k = -1;
	while (line2[++k])
	{
		if (line2[k] == '0')
		{
			free(line);
			free(line2);
			inv();
		}
	}
	free(line2);
	free(line);
	w->map[i] = NULL;
	close(w->fd);
}

static void	kostil2(char *line, int k, int i, t_pr *w)
{
	while (line[k])
	{
		if ((ft_isdigit(line[k]) == 0 && line[k] != ' ') ||
			(i == 0 && line[k] == '0') ||
			(k == 0 && line[k] == '0') ||
			(!line[k + 1] && line[k] == '0'))
		{
			free(line);
			inv();
		}
		w->map[i][k] = ft_atoi(&line[k]);
		k++;
	}
}

void		readmap(t_pr *w)
{
	int		i;
	int		k;
	char	*line;
	char	*line2;

	line2 = NULL;
	k = 0;
	i = 0;
	w->fd = open(w->argv, O_RDONLY);
	w->map = (int**)malloc(4096 * sizeof(int*));
	while (get_next_line(w->fd, &line) > 0)
	{
		if (line2 != NULL)
			free(line2);
		w->map[i] = (int*)malloc(4096 * sizeof(int));
		kostil2(line, k, i, w);
		line2 = ft_strdup(line);
		free(line);
		k = 0;
		i++;
	}
	kostil(line, line2, i, w);
}
