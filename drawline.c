#include "wolf3d.h"

void	drawline(int x, t_pr *w)
{
	int i;

	i = w->drawstart;
	while (i != w->drawend)
	{
	if ((x >= 0 && x < 512) && (i >= 0 && i < 384))
		w->imgdata[i * WW + x] = w->color;
		if (w->drawend > 384 && i == 384)
			break ;
		else if (w ->drawend < 0 && i == 0)
			break ;
		if (i < w->drawend)
			i++;
		else
			i--;
	}
}
