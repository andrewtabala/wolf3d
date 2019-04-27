#include "wolf3d.h"

void	draw(t_pr *w)
{
	int x;

	x = 0;
		while(x < WW)
		{
			w->camerax = 2 * x / (double)WW - 1;
			w->raydirx = w->dirx + w->planex * w->camerax;
			w->raydiry = w->diry + w->planey * w->camerax;

			w->mapx = (int)w->posx;
			w->mapy = (int)w->posy;

			w->deltadistx = fabs(1 / w->raydirx);
			w->deltadisty = fabs(1 / w->raydiry);

			w->hit = 0;

			if (w->raydirx < 0)
			{
				w->stepx = -1;
				w->sidedistx = (w->posx - w->mapx) * w->deltadistx;
			}
			else
			{
				w->stepx = 1;
				w->sidedistx = (w->mapx + 1.0 - w->posx) * w->deltadistx;
			}
			if (w->raydiry < 0)
			{
				w->stepy = -1;
				w->sidedisty = (w->posy - w->mapy) * w->deltadisty;
			}
			else
			{
				w->stepy = 1;
				w->sidedisty = (w->mapy + 1.0 - w->posy) * w->deltadisty;
			}
			while (w->hit == 0)
			{
				if (w->sidedistx < w->sidedisty)
				{
					w->sidedistx += w->deltadistx;
					w->mapx += w->stepx;
					w->side = 0;
				}
				else
				{
					w->sidedisty += w->deltadisty;
					w->mapy += w->stepy;
					w->side = 1;
				}
				if (w->map[w->mapx][w->mapy] != 0)
					w->hit = 1;
			}
			if (w->side == 0)
				w->perpwalldist = (w->mapx - w->posx + (1 - w->stepx) / 2) / w->raydirx;
			else	
				w->perpwalldist = (w->mapy - w->posy + (1 - w->stepy) / 2) / w->raydiry;
			w->lineheight = (int)(WH / w->perpwalldist);
			w->drawstart = -w->lineheight / 2 + WH / 2;
			if (w->drawstart < 0)
				w->drawstart = 0;
			w->drawend = w->lineheight / 2 + WH / 2;
			if (w->drawend >= WH)
				w->drawend = WH - 1;
			if (w->map[w->mapx][w->mapy] == 1)
				w->texture = w->img_stone_data;
			else if (w->map[w->mapx][w->mapy] == 2)
				w->texture = w->img_sand_data;
			else if (w->map[w->mapx][w->mapy] == 3)
				w->texture = w->img_redbrick_data;
			else if (w->map[w->mapx][w->mapy] == 4)
				w->texture = w->img_mossy_data;
			else
				w->texture = w->img_mossy_data;	
			if (w->side == 1)
				w->color /= 2;
			drawline(w->texture, x, w);
			x++;
	}
}
