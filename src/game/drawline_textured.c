#include "wolf3d.h"

static void	floordraw(int i, int x, t_pr *w)
{
	while (i != 0 && i != WH)
	{
		if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
			w->imgdata[i * WW + x] = 5719381;
		i++;
	}	
}

static void	ceilingdraw(int i, int x, t_pr *w)
{
	while (i != 0 && i != WH)
	{
		if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
			w->imgdata[i * WW + x] = 6165077;
		i--;
	}
}

void		drawline_textured(int *texture, int x, t_pr *w)
{
	int i;
	int k;
	int iter;
	int	text;

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
	floordraw(i, x, w);
	i = w->drawstart;
	ceilingdraw(i, x, w);
	
}
