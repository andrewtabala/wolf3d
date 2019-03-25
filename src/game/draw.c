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
				w->color = 10604827;
			else if (w->map[w->mapx][w->mapy] == 2)
				w->color = 1778897;
			else if (w->map[w->mapx][w->mapy] == 3)
				w->color = 13704097;
			else if (w->map[w->mapx][w->mapy] == 4)
				w->color = 13703966;
			else if (w->map[w->mapx][w->mapy] == 5)
				w->color = 13357339;
			else if (w->map[w->mapx][w->mapy] == 6)
				w->color = 1823182;	
			if (w->side == 1)
				w->color /= 2;
			drawline(x, w);
			x++;
	}
}
