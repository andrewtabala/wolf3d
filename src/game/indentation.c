/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indentation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:40:16 by atabala           #+#    #+#             */
/*   Updated: 2019/05/31 17:47:15 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	indentation(char *argv, t_pr *w)
{
	int 	wid = 64;
	int 	hei = 64;

	w->win_width = 1024;
	w->win_height = 576;
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, w->win_width, w->win_height, "wolf3d");
	w->argv = argv;
	w->prevxmouse = w->win_width / 2;
	w->movespeed = 0.1;
	w->rotspeed = 0.1;
	w->posx = 3;
	w->posy = 2;
	w->dirx = -1;
	w->diry = 0;
	w->planex = 0;
	w->planey = 0.66;
	w->prevp = 1;
	w->x_text = 0;
	w->textured = 1;
}
