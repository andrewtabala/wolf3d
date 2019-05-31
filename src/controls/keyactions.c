#include "../game/wolf3d.h"

void		textured(t_pr *w)
{
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ft_bzero(w->imgdata, sizeof(int) * WW * WH);
	if (w->textured == 0)
		w->textured = 1;
	else
		w->textured = 0;
	draw(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_ptr, 0, 0);
	mlx_loop(w->mlx_ptr);
}

void		move(int i, t_pr *w)
{
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	ft_bzero(w->imgdata, sizeof(int) * WW * WH);
	if (i == 123 || i == 0)
	{
		w->olddirx = w->dirx;
		w->dirx = w->dirx * cos(w->rotspeed) - w->diry * sin(w->rotspeed);
		w->diry = w->olddirx * sin(w->rotspeed) + w->diry * cos(w->rotspeed);
		w->oldplanex = w->planex;
		w->planex = w->planex * cos(w->rotspeed) - w->planey * sin(w->rotspeed);
		w->planey = w->oldplanex * sin(w->rotspeed) + w->planey * cos(w->rotspeed);
	}
	else if (i == 126 || i == 13)
	{
		if(w->map[(int)(w->posx + w->dirx * w->movespeed)][(int)w->posy] == 0)
			w->posx += w->dirx * w->movespeed;
		if(w->map[(int)w->posx][(int)(w->posy + w->diry * w->movespeed)] == 0)
			w->posy += w->diry * w->movespeed;
	}
	else if (i == 124 || i == 2)
	{
		w->olddirx = w->dirx;
		w->dirx = w->dirx * cos(-w->rotspeed) - w->diry * sin(-w->rotspeed);
		w->diry = w->olddirx * sin(-w->rotspeed) + w->diry * cos(-w->rotspeed);
		w->oldplanex = w->planex;
		w->planex = w->planex * cos(-w->rotspeed) - w->planey * sin(-w->rotspeed);
		w->planey = w->oldplanex * sin(-w->rotspeed) + w->planey * cos(-w->rotspeed);
	}
	else if (i == 125 || i == 1)
	{
		if(w->map[(int)(w->posx - w->dirx * w->movespeed)][(int)w->posy] == 0)
			w->posx -= w->dirx * w->movespeed;
		if(w->map[(int)w->posx][(int)(w->posy - w->diry * w->movespeed)] == 0)
			w->posy -= w->diry * w->movespeed;
	}
	draw(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_ptr, 0, 0);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
		w->img_awp,500, 200);
	mlx_loop(w->mlx_ptr);
}
