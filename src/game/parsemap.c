#include "wolf3d.h"

int		parsemap(t_pr *w)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (w->parsemap[y])
	{
		while (w->parsemap[y][x])
		{
			if ((y == 0 || y == w->mapheight) && (x % 2 == 0) && (ft_atoi(&w->parsemap[y][x]) == 0))
			{
				printf("%s\n", "1");
				return (1);
			}
			if (ft_atoi(&w->parsemap[y][x]) < 0 || ft_atoi(&w->parsemap[y][x]) > 6)
			{
				printf("%s\n", "2");
				return (1);
			}
			if (x == 0 && ft_atoi(&w->parsemap[y][x]) == 0)
			{
				printf("%s\n", w->parsemap[y]);
				printf("%d %c\n", ft_atoi(&w->parsemap[y][x]), w->parsemap[y][x]);
				printf("%d %d %s\n", y, x, "3");
				return (1);
			}
			if (x % 2 != 0 && w->parsemap[y][x] != ' ')
			{
				printf("%s\n", "4");
				return (1);
			}
			if (!w->parsemap[y][x + 1] && w->parsemap[y][x] == 0)
			{
				printf("%s\n", "5");
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}