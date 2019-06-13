/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_set_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 18:44:05 by atabala           #+#    #+#             */
/*   Updated: 2019/06/08 14:45:47 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_textures(int x, t_pr *w)
{
	if (w->side == 1)
	{
		if (w->map[w->mapx][w->mapy] == 1)
			w->texture = w->img_t1_d;
		else if (w->map[w->mapx][w->mapy] == 2)
			w->texture = w->img_t2_d;
		else if (w->map[w->mapx][w->mapy] == 3)
			w->texture = w->img_t3_d;
		else
			w->texture = w->img_t4_d;
	}
	else
	{
		if (w->map[w->mapx][w->mapy] == 1)
			w->texture = w->img_t1_1_d;
		else if (w->map[w->mapx][w->mapy] == 2)
			w->texture = w->img_t2_1_d;
		else if (w->map[w->mapx][w->mapy] == 3)
			w->texture = w->img_t3_1_d;
		else
			w->texture = w->img_t4_1_d;
	}
	drawline_textured(w->texture, x, w);
}

void	set_color(int x, t_pr *w)
{
	if (w->map[w->mapx][w->mapy] == 1)
		w->color = 11248298;
	else if (w->map[w->mapx][w->mapy] == 2)
		w->color = 12556376;
	else if (w->map[w->mapx][w->mapy] == 3)
		w->color = 9381672;
	else
		w->color = 3105077;
	if (w->side == 1)
		w->color /= 2;
	drawline_untextured(x, w);
}
