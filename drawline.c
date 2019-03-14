#include "wolf3d.h"

void	drawline(int x, t_pr *w)
{
	int i;

	i = w->drawstart;
	while (i != w->drawend)
	{
	if ((x >= 0 && x < WW) && (i >= 0 && i < WH))
		w->imgdata[i * WW + x] = w->color;
		if (w->drawend > WH && i == WH)
			break ;
		else if (w ->drawend < 0 && i == 0)
			break ;
		if (i < w->drawend)
			i++;
		else
			i--;
	}
}
