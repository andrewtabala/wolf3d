/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:14:12 by atabala           #+#    #+#             */
/*   Updated: 2019/05/31 18:14:22 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img(t_pr *w)
{
	int		bpp;
	int		sl;
	int		e;

	w->img_ptr = mlx_new_image(w->mlx_ptr, WW, WH);
	w->imgdata = (int*)mlx_get_data_addr(w->img_ptr, &bpp, &sl, &e);
}
