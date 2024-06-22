#include <stdio.h>
#include <stdlib.h>

typedef struct s_point
{
	int x;
	int y;
} t_point;

void	fill_zone(int x, int y, t_point size, char target, char **tab)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return;
	if (tab[y][x] != target)
		return;
	tab[y][x] = 'F';
	fill_zone(x + 1, y, size, target, tab);
	fill_zone(x - 1, y, size, target, tab);
	fill_zone(x, y + 1, size, target, tab);
	fill_zone(x, y - 1, size, target, tab);
}
void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill_zone(begin.x, begin.y, size, tab[begin.y][begin.x], tab);
}