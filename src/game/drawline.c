#include "wolf3d.h"

void				drawline(int *texture, int x, t_pr *w)
{
	int i;
	int k;
	int iter;
	int	text;
	double wallX;

	if (side == 0)
		wallX = w->posy + w->perpwalldist * w->raydiry;
	else
		wallX = w->posy + w->perpwalldist * w->raydirx;
	wallX -= floor((wallX));
	text = 0;
	k = 0;
	i = w->drawstart;
	iter = (w->drawend - i) / 64;
	if (iter == 0)
		iter = 1;
	while (i != w->drawend)
	{
		if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
		{
			if (k == iter && text < 64)
			{
				k = 0;
				text++;
			}
			w->imgdata[i * WW + x] = texture[x + 64 * text];
		}
		if (w->drawend > WH && i == WH)
			break ;
		else if (w ->drawend < 0 && i == 0)
			break ;
		if (i < w->drawend)
			i++;
		else
			i--;
		k++;
	}
}
