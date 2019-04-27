/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:52:00 by atabala           #+#    #+#             */
/*   Updated: 2019/01/29 14:52:36 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include "fdf.h"

void	img(t_pr *pr)
{
	int		bpp;
	int		sl;
	int		e;
	int 	wid;
	int 	hei;

	wid = 64;
	hei = 64;

	pr->img_ptr = mlx_new_image(pr->mlx_ptr, 1280, 720);
	pr->imgdata = (int*)mlx_get_data_addr(pr->img_ptr, &bpp, &sl, &e);

	pr->img_stone = mlx_xpm_file_to_image(pr->mlx_ptr, "textures/stone.xpm", &wid, &hei);
	pr->img_stone_data = (int*)mlx_get_data_addr(pr->img_stone, &bpp, &sl, &e);

	pr->img_sand = mlx_xpm_file_to_image(pr->mlx_ptr, "textures/sand.xpm", &wid, &hei);
	pr->img_sand_data = (int*)mlx_get_data_addr(pr->img_sand, &bpp, &sl, &e);

	pr->img_redbrick = mlx_xpm_file_to_image(pr->mlx_ptr, "textures/redbrick.xpm", &wid, &hei);
	pr->img_redbrick_data = (int*)mlx_get_data_addr(pr->img_redbrick, &bpp, &sl, &e);

	pr->img_mossy = mlx_xpm_file_to_image(pr->mlx_ptr, "textures/mossy.xpm", &wid, &hei);
	pr->img_mossy_data = (int*)mlx_get_data_addr(pr->img_mossy, &bpp, &sl, &e);

	pr->img_clear = mlx_xpm_file_to_image(pr->mlx_ptr, "textures/clear.xpm", &wid, &hei);
}
