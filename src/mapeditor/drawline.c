/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:11:53 by atabala           #+#    #+#             */
/*   Updated: 2019/01/29 15:49:24 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapeditor.h"

void	drawline(t_pr *map)
{
	int dx = abs(map->x2-map->x1), sx = map->x1<map->x2 ? 1 : -1;
  int dy = abs(map->y2-map->y1), sy = map->y1<map->y2 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, 116777215);
    if (map->x1==map->x2 && map->y1==map->y2) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; map->x1 += sx; }
    if (e2 < dy) { err += dx; map->y1 += sy; }
  }
}
