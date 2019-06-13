/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indentation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:40:16 by atabala           #+#    #+#             */
/*   Updated: 2019/06/08 14:39:11 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	set_textures_demensions(t_pr *w)
{
	w->sky_w = 1200;
	w->sky_h = 799;
	w->awp_w = 577;
	w->awp_h = 371;
	w->t_wh = 64;
}

void		indentation(char *argv, t_pr *w)
{
	INIT;
	w->win_width = 1024;
	w->win_height = 576;
	w->mlx_ptr = mlx_init();
	w->win_ptr =
		mlx_new_window(w->mlx_ptr, w->win_width, w->win_height, "wolf3d");
	w->argv = argv;
	w->prevxmouse = w->win_width / 2;
	w->movespeed = 0.1;
	w->rotspeed = 0.1;
	w->dirx = -1;
	w->diry = 0;
	w->planex = 0;
	w->planey = 0.66;
	w->prevp = 1;
	w->x_text = 0;
	w->textured = 0;
	w->found_coord = 0;
	set_textures_demensions(w);
}
