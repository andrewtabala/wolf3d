#ifndef MAPEDITOR_H
# define MAPEDITOR_H

# include "../../minilibx_macos/mlx.h"
# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct 	s_pr
{
	char	*mapname;
	int		mapwidth;
	int		mapheight;
	int		**map;

	int		x1;
	int		x2;
	int		y1;
	int		y2;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*imt_ptr;
	int		*img_data;
}				t_pr;

void		creatematrix(t_pr *map);
void	drawline(t_pr *map);
void	drawlinevert(t_pr *map);

#endif