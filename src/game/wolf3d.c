/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:25:23 by atabala           #+#    #+#             */
/*   Updated: 2019/06/08 15:49:02 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			closewin(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			key_press(int key, void *param)
{
	t_pr	*w;

	w = (t_pr *)param;
	if (key == 53)
		exit(0);
	if (key == 123 || key == 126 || key == 124 || key == 125 ||
		key == 0 || key == 13 || key == 2 || key == 1)
		move(key, w);
	if (key == 257 || key == 258)
		w->movespeed = 0.3;
	if (key == 17)
		textured(w);
	return (0);
}

int			key_release(int key, void *param)
{
	t_pr	*w;

	w = (t_pr *)param;
	if (key == 257 || key == 258)
		w->movespeed = 0.1;
	return (0);
}

void		setup_controls(t_pr *w)
{
	mlx_hook(w->win_ptr, 2, 0, key_press, w);
	mlx_hook(w->win_ptr, 3, 0, key_release, w);
	mlx_hook(w->win_ptr, 6, 0, mouse_move, w);
	mlx_hook(w->win_ptr, 17, 0, closewin, w);
}

int			main(int argc, char **argv)
{
	t_pr	w;

	validation(argc, argv, &w);
	setup_controls(&w);
	img(&w);
	settextures(&w);
	draw(&w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr,
		w.img_ptr, 0, 0);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr,
		w.img_awp, 500, 210);
	mlx_loop(w.mlx_ptr);
}
