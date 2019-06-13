/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:52:51 by atabala           #+#    #+#             */
/*   Updated: 2019/06/03 15:02:42 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/wolf3d.h"

void	calculations1(int x, t_pr *w)
{
	w->olddirx = w->dirx;
	w->dirx = w->dirx * cos(0.02 * (w->prevxmouse - x)) -
		w->diry * sin(0.02 * (w->prevxmouse - x));
	w->diry = w->olddirx * sin(0.02 * (w->prevxmouse - x)) +
		w->diry * cos(0.02 * (w->prevxmouse - x));
	w->oldplanex = w->planex;
	w->planex = w->planex * cos(0.02 * (w->prevxmouse - x)) -
		w->planey * sin(0.02 * (w->prevxmouse - x));
	w->planey = w->oldplanex * sin(0.02 * (w->prevxmouse - x)) +
		w->planey * cos(0.02 * (w->prevxmouse - x));
}

void	calculations2(int x, t_pr *w)
{
	w->olddirx = w->dirx;
	w->dirx = w->dirx * cos(-0.02 * (x - w->prevxmouse)) -
		w->diry * sin(-0.02 * (x - w->prevxmouse));
	w->diry = w->olddirx * sin(-0.02 * (x - w->prevxmouse)) +
		w->diry * cos(-0.02 * (x - w->prevxmouse));
	w->oldplanex = w->planex;
	w->planex = w->planex * cos(-0.02 * (x - w->prevxmouse)) -
		w->planey * sin(-0.02 * (x - w->prevxmouse));
	w->planey = w->oldplanex * sin(-0.02 * (x - w->prevxmouse)) +
		w->planey * cos(-0.02 * (x - w->prevxmouse));
}

int		mouse_move(int x, int y, t_pr *w)
{
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ft_bzero(w->imgdata, sizeof(int) * WW * WH);
	if (x >= 0 && x <= WW && y >= 0 && y <= WH)
	{
		if (x < w->prevxmouse)
			calculations1(x, w);
		else if (x > w->prevxmouse)
			calculations2(x, w);
	}
	w->prevxmouse = x;
	draw(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_ptr, 0, 0);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_awp, 500, 210);
	controlsmenu(w);
	mlx_loop(w->mlx_ptr);
	return (0);
}
