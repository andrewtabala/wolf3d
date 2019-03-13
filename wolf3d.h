#ifndef WOLF3D_H
# define WOLF3D_H

# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WW w->win_width
# define WH w->win_height

typedef struct  	s_pr
{
	int		fd;
	int		**map;
	char	**parsemap;

	void	*mlx_ptr;
	void	*win_ptr;

	int		win_width;
	int		win_height;

	void	*win_minimap;

	void	*img_ptr;
	void	*img_stone;
	void	*img_mossy;	
	void	*img_redbrick;
	void	*img_sand;
	void	*img_sky;
	void	*img_wood;
	int		*imgdata;


	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;

	double	camerax;
	double	raydirx;
	double	raydiry;

	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;

	double	olddirx;
	double	oldplanex;

	double	movespeed;
	double	rotspeed;
	
	int		hit;
	int		side;

	int		lineheight;
	int		drawstart;
	int		drawend;

	int		mapwidth;
	int		mapheight;
	
	char	*argv;
	int		color;
}					t_pr;

void	readmap(t_pr *w);
void	count(t_pr *w);
void	img(t_pr *w);

void	settextures(t_pr *w);
void	draw(t_pr *w);
void	drawline(int x, t_pr *w);
void	move(int i, t_pr *w);
int		parsemap(t_pr *w);

#endif
