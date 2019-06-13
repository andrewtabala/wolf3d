/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_textured.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:44:06 by atabala           #+#    #+#             */
/*   Updated: 2019/06/13 14:49:08 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	kostil(int texx, t_pr *w)
{
	if (w->side == 0 && w->raydirx > 0)
		texx = w->t_wh - texx - 1;
	if (w->side == 1 && w->raydiry < 0)
		texx = w->t_wh - texx - 1;
	return (texx);
}

static void	floordraw(int i, int x, t_pr *w)
{
	while (i != 0 && i != WH)
	{
		if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
			w->imgdata[i * WW + x] = 4342338;
		i++;
	}
}

static void	ceilingdraw(int i, int x, t_pr *w)
{
	while (i != w->drawstart && i != WH)
	{
		if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
			w->imgdata[i * WW + x] = w->img_sky_d[x + WW * i];
		i++;
	}
}

void		drawline_textured(int *texture, int x, t_pr *w)
{
	int		iter;
	int		texnum;
	double	wallx;
	int		texy;
	int		texx;

	texnum = w->map[w->mapx][w->mapy] - 1;
	w->texi = w->drawstart;
	if (w->side == 0)
		wallx = w->posy + w->perpwalldist * w->raydiry;
	else
		wallx = w->posx + w->perpwalldist * w->raydirx;
	wallx -= floor((wallx));
	texx = (int)(wallx * (double)(w->t_wh));
	kostil(texx, w);
	while (w->texi != w->drawend)
	{
		w->texd = w->texi * 256 - WH * 128 + w->lineheight * 128;
		texy = ((w->texd * w->t_wh) / w->lineheight) / 256;
		w->imgdata[w->texi * WW + x] = texture[texnum + w->t_wh * texy + texx];
		w->texi++;
	}
	floordraw(w->texi, x, w);
	ceilingdraw(0, x, w);
}
