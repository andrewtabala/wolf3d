#include "wolf3d.h"

void	readmap(t_pr *w)
{
	int 	i;
	int		k;
	char	*line;

	k = 0;
	i = 0;
	w->fd = open(w->argv, O_RDONLY);
	w->map = (char**)malloc(4096 * sizeof(char*));
	while (get_next_line(w->fd, &line) > 0)
	{
		w->map[i] = (char*)malloc(4096 * sizeof(char));
		w->map[i] = line;
		line = NULL;
		i++;
	}
	w->mapheight = i;
	w->map[i] = NULL;
	count(w);
	close(w->fd);
}

void	count(t_pr *w)
{
	int		k;

	k = 0;
	while (w->map[1][k])
		k++;
	w->mapwidth = k / 2;
}
