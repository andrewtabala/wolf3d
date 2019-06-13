/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:16:15 by atabala           #+#    #+#             */
/*   Updated: 2019/06/08 14:40:44 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		settextures(t_pr *w)
{
	int		wid;
	int		hei;
	int		bpp;
	int		sl;
	int		e;

	wid = 64;
	hei = 64;
	w->img_t1 = mlx_xpm_file_to_image(w->mlx_ptr, "text/t1.xpm", &wid, &hei);
	w->img_t1_d = (int*)mlx_get_data_addr(w->img_t1, &bpp, &sl, &e);
	w->img_t2 = mlx_xpm_file_to_image(w->mlx_ptr, "text/wood.xpm", &wid, &hei);
	w->img_t2_d = (int*)mlx_get_data_addr(w->img_t2, &bpp, &sl, &e);
	w->img_t3 = mlx_xpm_file_to_image(w->mlx_ptr, "text/t3.xpm", &wid, &hei);
	w->img_t3_d = (int*)mlx_get_data_addr(w->img_t3, &bpp, &sl, &e);
	w->img_t4 = mlx_xpm_file_to_image(w->mlx_ptr, "text/t4.xpm", &wid, &hei);
	w->img_t4_d = (int*)mlx_get_data_addr(w->img_t4, &bpp, &sl, &e);
	w->img_awp = mlx_xpm_file_to_image(w->mlx_ptr, "text/awp.xpm", &wid, &hei);
	w->img_awp_d = (int*)mlx_get_data_addr(w->img_awp, &bpp, &sl, &e);
	w->img_sky = mlx_xpm_file_to_image(w->mlx_ptr, "text/sky.xpm", &wid, &hei);
	w->img_sky_d = (int*)mlx_get_data_addr(w->img_sky, &bpp, &sl, &e);
}
