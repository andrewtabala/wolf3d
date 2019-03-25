#include "wolf3d.h"

void	readmap(t_pr *w)
{
	int 	i;
	int		k;
	char	*line;

	k = 0;
	i = 0;
	w->fd = open(w->argv, O_RDONLY);
	w->map = (int**)malloc(4096 * sizeof(int*));
	w->parsemap = (char**)malloc(4096 * sizeof(char*));
	while (get_next_line(w->fd, &line) > 0)
	{
		w->map[i] = (int*)malloc(4096 * sizeof(int));
		w->parsemap[i] = (char*)malloc(4096 * sizeof(char));
		w->parsemap[i] = line;
		while(line[k])
		{
			w->map[i][k] = ft_atoi(&line[k]);
			k++;
		}
		free(line);
		k = 0;
		i++;
	}
	w->mapheight = i;
	w->map[i] = NULL;
	w->parsemap[i] = NULL;
	count(w);
	close(w->fd);
}

void	count(t_pr *w)
{
	int		k;

	k = 0;
	while (w->parsemap[1][k])
		k++;
	w->mapwidth = k;
}
