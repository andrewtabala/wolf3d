/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlsmenu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:55:51 by atabala           #+#    #+#             */
/*   Updated: 2019/06/14 12:55:53 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	controlsmenu(t_pr *w)
{
	int y;
	int col;

	y = 0;
	col = 1428412;
	mlx_string_put(w->mlx_ptr, w->win_ptr, 60, y += 5, col,
					"Controls");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, y += 65, col,
					"Move: Key Arrows/WASD");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, y += 50, col,
					"Sprint: Left/Right Shift");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, y += 50, col,
					"Change drawing type: T");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, y += 50, col,
					"Exit: Esc or Red Button");
}
