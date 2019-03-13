#include "wolf3d.h"

int			key_press(int key, void *param)
{
	t_pr	*w;

	w = (t_pr *)param;
	if (key == 53)
		exit(0);
	if (key == 123 || key == 126 || key == 124 || key == 125)
		move(key, w);
	if (key == 257 || key == 258)
		w->movespeed = 0.3;
	return (0);
}

int			key_release(int key, void *param)
{
	t_pr	*w;

	w = (t_pr *)param;
	if (key == 257 || key == 258)
		w->movespeed = 0.1;
	return (0);
}

void		setup_controls(t_pr *w)
{
	mlx_hook(w->win_ptr, 2, 0, key_press, w);
	mlx_hook(w->win_ptr, 3, 0, key_release, w);
}

int main(int argc, char **argv)
{
	t_pr	w;
	int 	wid = 64;
	int 	hei = 64;

	w.win_width = 512;
	w.win_height = 384;

	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.win_width, w.win_height, "wolf3d");
	w.argv = argv[1];
	w.movespeed = 0.1;
	w.rotspeed = 0.1;
	w.posx = 3;
	w.posy = 2;
	w.dirx = -1;
	w.diry = 0;
	w.planex = 0;
	w.planey = 0.66;
	setup_controls(&w);
	readmap(&w);
	/*if (parsemap(&w) == 1)
	{
		printf("%s\n", "Invalid map");
		exit(0);
	}*/
	img(&w);
	settextures(&w);
	draw(&w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr,
		w.img_ptr, 0, 0);

	mlx_loop(w.mlx_ptr);
}
