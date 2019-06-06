/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:14:31 by atabala           #+#    #+#             */
/*   Updated: 2019/06/06 13:54:26 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	inv()
{
	ft_putstr("Invalid map\n");
	exit (0);	
}

void		readmap(t_pr *w)
{
	int		i;
	int		k;
	char	*line;
	char	*line2;

	k = 0;
	i = 0;
	w->fd = open(w->argv, O_RDONLY);
	w->map = (int**)malloc(4096 * sizeof(int*));
	while (get_next_line(w->fd, &line) > 0)
	{
		w->map[i] = (int*)malloc(4096 * sizeof(int));
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
		line2 = ft_strdup(line);
		free(line);
		k = 0;
		i++;
	}
	k = -1;
	while (line2[++k])
		if (line2[k] == '0')
		{
			free(line2);
			inv();
		}
	free(line);
	w->map[i] = NULL;
	close(w->fd);
}
