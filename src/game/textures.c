#include "wolf3d.h"

void	settextures(t_pr *w)
{
	int 	wid;
	int 	hei;
	int		bpp;
	int		sl;
	int		e;

	wid = 64;
	hei = 64;

	w->img_stone = mlx_xpm_file_to_image(w->mlx_ptr, "textures/stone.xpm", &wid, &hei);
	w->img_stone_data = (int*)mlx_get_data_addr(w->img_stone, &bpp, &sl, &e);

	w->img_sand = mlx_xpm_file_to_image(w->mlx_ptr, "textures/sand.xpm", &wid, &hei);
	w->img_sand_data = (int*)mlx_get_data_addr(w->img_sand, &bpp, &sl, &e);

	w->img_redbrick = mlx_xpm_file_to_image(w->mlx_ptr, "textures/redbrick.xpm", &wid, &hei);
	w->img_redbrick_data = (int*)mlx_get_data_addr(w->img_redbrick, &bpp, &sl, &e);

	w->img_mossy = mlx_xpm_file_to_image(w->mlx_ptr, "textures/mossy.xpm", &wid, &hei);
	w->img_mossy_data = (int*)mlx_get_data_addr(w->img_mossy, &bpp, &sl, &e);
	wid = WW;
	hei = WH;
	w->img_sky = mlx_xpm_file_to_image(w->mlx_ptr, "textures/sky.xpm", &wid, &hei);
}
