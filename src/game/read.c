/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:14:31 by atabala           #+#    #+#             */
/*   Updated: 2019/06/03 18:26:29 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		readmap(t_pr *w)
{
	int		i;
	int		k;
	char	*line;

	k = 0;
	i = 0;
	w->fd = open(w->argv, O_RDONLY);
	w->map = (int**)malloc(4096 * sizeof(int*));
	while (get_next_line(w->fd, &line) > 0)
	{
		w->map[i] = (int*)malloc(4096 * sizeof(int));
		while (line[k])
		{
			if (ft_isdigit(line[k]) == 0 && line[k] != ' ')
			{
				ft_putstr("Invalid map\n");
				free(line);
				exit (0);
			}
			w->map[i][k] = ft_atoi(&line[k]);
			k++;
		}
		free(line);
		k = 0;
		i++;
	}
	free(line);
	w->map[i] = NULL;
	close(w->fd);
}
