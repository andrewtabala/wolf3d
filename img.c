#include "wolf3d.h"

void	img(t_pr *w)
{
	int		bpp;
	int		sl;
	int		e;

	w->img_ptr = mlx_new_image(w->mlx_ptr, WW, WH);
	w->imgdata = (int*)mlx_get_data_addr(w->img_ptr, &bpp, &sl, &e);
}
