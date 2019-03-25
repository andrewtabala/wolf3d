#include "mapeditor.h"

int main(int argc, char **argv)
{
	t_pr		map;
	if (argc != 4)
	{
		printf("%s\n", "Usage: ./mapeditor [mapwidth] [mapheight]");
		return (0);
	}
	map.mapname = argv[1];
	map.mapwidth = ft_atoi(argv[2]);
	map.mapheight = ft_atoi(argv[3]);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 800, 800, "mapeditor");
	creatematrix(&map);
	mlx_loop(map.mlx_ptr);
	return (0);
}