/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:02:07 by atabala           #+#    #+#             */
/*   Updated: 2019/01/29 15:55:03 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	controlsmenu(t_pr *pr)
{
	mlx_put_image_to_window(pr->mlx_ptr, pr->win_ptr, pr->img_stone, 288, 40);
	mlx_put_image_to_window(pr->mlx_ptr, pr->win_ptr, pr->img_sand, 501, 40);
	mlx_put_image_to_window(pr->mlx_ptr, pr->win_ptr, pr->img_redbrick, 714, 40);
	mlx_put_image_to_window(pr->mlx_ptr, pr->win_ptr, pr->img_mossy, 928, 40);
	mlx_put_image_to_window(pr->mlx_ptr, pr->win_ptr, pr->img_clear, 608, 140);
}

int		key_press(int key, void *param)
{
	t_pr	*pr;

	pr = (t_pr *)param;
	if (key == 53)
		exit(0);
	if (key == 123 || key == 126 || key == 124 || key == 125)
		move(key, pr);
	if (key == 27 || key == 24 || key == 5 || key == 4)
		zoom(key, pr);
	return (0);
}

void	setup_controls(t_pr *pr)
{
	mlx_hook(pr->win_ptr, 2, 0, key_press, pr);
	mlx_hook(pr->win_ptr, 4, 0, mouse_press, pr);
	mlx_hook(pr->win_ptr, 5, 0, mouse_release, pr);
	mlx_hook(pr->win_ptr, 6, 0, mouse_move, pr);
}

int		main(int argc, char **argv)
{
	t_pr	pr;

	if (argc == 2)
	{
		pr.mlx_ptr = mlx_init();
		pr.win_ptr = mlx_new_window(pr.mlx_ptr, 1280, 720, "Fil de Fer");
		pr.argv = argv[1];
		pr.fd = open(argv[1], O_RDONLY);
		pr.prevfd = open(argv[1], O_RDONLY);
		pr.xstart = 320;
		pr.ystart = 200;
		img(&pr);
		setup_controls(&pr);
		readfile(&pr);
		mainpar(&pr);
		mlx_loop(pr.mlx_ptr);
		free(pr.file);
	}
}
