#include "wolf3d.h"

int		mouse_move(int x, int y, t_pr *w)
{
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ft_bzero(w->imgdata, sizeof(int) * WW * WH);
	if (x >= 0 && x <= 512 && y >= 0 && y <= 384)
	{
		printf("%d %d %f\n", x, w->prevxmouse, ((float)w->prevxmouse - x / 10.0));
		if (x < w->prevxmouse)
		{
			w->olddirx = w->dirx;
			w->dirx = w->dirx * cos(0.04) - w->diry * sin(0.04);
			w->diry = w->olddirx * sin(0.04) + w->diry * cos(0.04);
			w->oldplanex = w->planex;
			w->planex = w->planex * cos(0.04) - w->planey * sin(0.04);
			w->planey = w->oldplanex * sin(0.04) + w->planey * cos(0.04);
		}
		else if (x > w->prevxmouse)
		{
			w->olddirx = w->dirx;
			w->dirx = w->dirx * cos(-0.04) - w->diry * sin(-0.04);
			w->diry = w->olddirx * sin(-0.04) + w->diry * cos(-0.04);
			w->oldplanex = w->planex;
			w->planex = w->planex * cos(-0.04) - w->planey * sin(-0.04);
			w->planey = w->oldplanex * sin(-0.04) + w->planey * cos(-0.04);
		}
	}
	w->prevxmouse = x;
	draw(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_ptr, 0, 0);
	mlx_loop(w->mlx_ptr);
	return(0);
}