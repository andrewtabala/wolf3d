/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyactions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:55:59 by atabala           #+#    #+#             */
/*   Updated: 2019/06/03 15:03:07 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/wolf3d.h"

static void	calculations1(t_pr *w)
{
	w->olddirx = w->dirx;
	w->dirx = w->dirx * cos(w->rotspeed) -
		w->diry * sin(w->rotspeed);
	w->diry = w->olddirx * sin(w->rotspeed) +
		w->diry * cos(w->rotspeed);
	w->oldplanex = w->planex;
	w->planex = w->planex * cos(w->rotspeed) -
		w->planey * sin(w->rotspeed);
	w->planey = w->oldplanex * sin(w->rotspeed) +
		w->planey * cos(w->rotspeed);
}

static void	calculations2(t_pr *w)
{
	w->olddirx = w->dirx;
	w->dirx = w->dirx * cos(-w->rotspeed) -
		w->diry * sin(-w->rotspeed);
	w->diry = w->olddirx * sin(-w->rotspeed) +
		w->diry * cos(-w->rotspeed);
	w->oldplanex = w->planex;
	w->planex = w->planex * cos(-w->rotspeed) -
		w->planey * sin(-w->rotspeed);
	w->planey = w->oldplanex * sin(-w->rotspeed) +
		w->planey * cos(-w->rotspeed);
}

static void	rotating(int i, t_pr *w)
{
	if (i == 123 || i == 0)
		calculations1(w);
	else if (i == 126 || i == 13)
	{
		if (w->map[(int)(w->posx + w->dirx * w->movespeed)][(int)w->posy] == 0)
			w->posx += w->dirx * w->movespeed;
		if (w->map[(int)w->posx][(int)(w->posy + w->diry * w->movespeed)] == 0)
			w->posy += w->diry * w->movespeed;
	}
	else if (i == 124 || i == 2)
		calculations2(w);
	else if (i == 125 || i == 1)
	{
		if (w->map[(int)(w->posx - w->dirx * w->movespeed)][(int)w->posy] == 0)
			w->posx -= w->dirx * w->movespeed;
		if (w->map[(int)w->posx][(int)(w->posy - w->diry * w->movespeed)] == 0)
			w->posy -= w->diry * w->movespeed;
	}
}

void		textured(t_pr *w)
{
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ft_bzero(w->imgdata, sizeof(int) * WW * WH);
	if (w->textured == 0)
		w->textured = 1;
	else
		w->textured = 0;
	draw(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_ptr, 0, 0);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_awp, 500, 210);
	controlsmenu(w);
	mlx_loop(w->mlx_ptr);
}

void		move(int i, t_pr *w)
{
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ft_bzero(w->imgdata, sizeof(int) * WW * WH);
	rotating(i, w);
	draw(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_ptr, 0, 0);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_awp, 500, 210);
	controlsmenu(w);
	mlx_loop(w->mlx_ptr);
}
