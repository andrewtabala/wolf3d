/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:47:21 by atabala           #+#    #+#             */
/*   Updated: 2019/06/03 16:45:03 by atabala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/wolf3d.h"

static void	validate_map(t_pr *w)
{

}

void		validation(int argc, char **argv, t_pr *w)
{
	int i;
	if (argc != 2)
	{
		ft_putstr("You can only call one argument\n");
		ft_putstr("Usage: ./wolf3d map_name\n");
		exit (0);
	}
	i = open(argv[1], O_RDONLY);
	if (i < 0)
	{
		ft_putstr("You can only call a valid file\n");
		ft_putstr("Usage: ./wolf3d map_name\n");
		exit (0);
	}
	indentation(argv[1], w);
	readmap(w);
	validate_map(w);
}
