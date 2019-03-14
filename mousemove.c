#include "wolf3d.h"

int		mouse_move(int x, int y, t_pr *w)
{
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ft_bzero(w->imgdata, sizeof(int) * WW * WH);
	if (x >= 0 && x <= WW && y >= 0 && y <= WH)
	{
		if (x < w->prevxmouse)
		{
			w->olddirx = w->dirx;
			w->dirx = w->dirx * cos(0.02 * (w->prevxmouse - x)) - w->diry * sin(0.02 * (w->prevxmouse - x));
			w->diry = w->olddirx * sin(0.02 * (w->prevxmouse - x)) + w->diry * cos(0.02 * (w->prevxmouse - x));
			w->oldplanex = w->planex;
			w->planex = w->planex * cos(0.02 * (w->prevxmouse - x)) - w->planey * sin(0.02 * (w->prevxmouse - x));
			w->planey = w->oldplanex * sin(0.02 * (w->prevxmouse - x)) + w->planey * cos(0.02 * (w->prevxmouse - x));
		}
		else if (x > w->prevxmouse)
		{
			w->olddirx = w->dirx;
			w->dirx = w->dirx * cos(-0.02 * (x - w->prevxmouse)) - w->diry * sin(-0.02 * (x - w->prevxmouse));
			w->diry = w->olddirx * sin(-0.02 * (x - w->prevxmouse)) + w->diry * cos(-0.02 * (x - w->prevxmouse));
			w->oldplanex = w->planex;
			w->planex = w->planex * cos(-0.02 * (x - w->prevxmouse)) - w->planey * sin(-0.02 * (x - w->prevxmouse));
			w->planey = w->oldplanex * sin(-0.02 * (x - w->prevxmouse)) + w->planey * cos(-0.02 * (x - w->prevxmouse));
		}
	}
	w->prevxmouse = x;
	draw(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_ptr, 0, 0);
	mlx_loop(w->mlx_ptr);
	return(0);
}