#include "mapeditor.h"

void		creatematrix(t_pr *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	
	map->x1 = 100;
	map->x2 = map->x1 + 600/map->mapwidth;
	map->y1 = map->y2 = 140;
	map->map = (int**)malloc(sizeof(int*) * 4096);
	while (i < map->mapheight)
	{
		map->map[i] = (int*)malloc(sizeof(int) * 4096);
		while (j < map->mapwidth)
		{
			drawline(map);
			map->x1 = map->x2;
			map->x2 += 600/map->mapwidth;
			map->map[i][j] = 0;
			j++;
		}
		map->x1 = 100;
		map->x2 = map->x1 + 600/map->mapwidth;
		map->y1 += 600/map->mapheight;
		map->y2 = map->y1;
		j = 0;
		while (j < map->mapwidth)
		{
			drawline(map);
			map->x1 = map->x2;
			map->x2 += 600/map->mapwidth;
			j++;
		}
		i++;
	}
}