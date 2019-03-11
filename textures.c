#include "wolf3d.h"

void	settextures(t_pr *w)
{
	int 	wid;
	int 	hei;

	wid = 64;
	hei = 64;
	w->img_wood = mlx_xpm_file_to_image(w->mlx_ptr, "textures/wood.xpm", &wid, &hei);
	w->img_stone = mlx_xpm_file_to_image(w->mlx_ptr, "textures/stone.xpm", &wid, &hei);
	w->img_sand = mlx_xpm_file_to_image(w->mlx_ptr, "textures/sand.xpm", &wid, &hei);
	w->img_redbrick = mlx_xpm_file_to_image(w->mlx_ptr, "textures/redbrick.xpm", &wid, &hei);
	w->img_mossy = mlx_xpm_file_to_image(w->mlx_ptr, "textures/mossy.xpm", &wid, &hei);
	wid = 512;
	hei = 512;
	w->img_sky = mlx_xpm_file_to_image(w->mlx_ptr, "textures/sky.xpm", &wid, &hei);
}
