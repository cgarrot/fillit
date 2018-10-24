/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 15:45:48 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 17:48:39 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	print_grid(char **grid, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{

		j = 0;
		while (grid[i][j])
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');	
}

int 	calc_space(char *line, char **grid, t_tetri *tetri)
{
	int i;
	int j;
	size_t next_line;
	int x;
	int k;
	int l;
	size_t space;

	i = 0;
	x = tetri->curr_x;
	k = 0;
	l = 0;
	next_line = 0;
	if (line == NULL)
		return (0);
	j = 0;
	space = 0;
	while (grid[x][i])
	{
		k = x;
		l = i;
		while (line[j])
		{
			if (line[j] == '\n' && k + 1 < tetri->size && grid[k + 1][l] == '.')
			{
				next_line++;
				k++;
				l = i;
			}
			if (line[j] == '.' && grid[k][l] == '.' && l + 1 < tetri->size)
			{
				l++;
				space++;
			}
			if (line[j] == '#' && grid[k][l] == '.' && l + 1 < tetri->size)
			{	
				l++;
				space++;
			}
			j++;
		}
		if (k == tetri->size || l == tetri->size)
			return (0);
		if (next_line + space == ft_strlen(line))
			return (1);
		i++;
	}
	return (0);	
}

char	*get_piece(char ***file, t_tetri *tetri)
{
	if (tetri->curr_block < tetri->c_blocks)
		return (call_all(ft_check_all(file[tetri->curr_block])));
	return (NULL);
}

int	*get_next_coords(t_tetri *tetri)
{
	int *coords;
	int max_x;
	int max_y;
	int i;
	
	max_x = 0;
	max_y = 0;
	if (!(coords = malloc(sizeof(int) * 3)))
		return (NULL);
	coords[0] = 0;
	coords[1] = 0;
	i = 0;
	while (i < 4)
	{
		if (tetri->coords[i]->x > max_x)
			max_x = tetri->coords[i]->x;
 		if (tetri->coords[i]->y > max_y)
			max_y = tetri->coords[i]->y;
		i++;
	}
	printf("SIZE %d --- MAX Y %d", tetri->size, max_y);
	if (max_y + 1 == tetri->size)
	{
		coords[0] = max_x + 1;
		coords[1] = 0;
	}
	else
	{	
		coords[0] = tetri->coords[0]->x;
		coords[1] = max_y + 1;
	}
	return (coords);
}

int		ft_put(char **grid, char *shape, t_tetri *tetri)
{
	int x;
	int y;
	int i;
	int j;
	int prev;
	int *next_coord;

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	prev = 0;
	if (tetri->curr_block > 0)
	{
		next_coord = get_next_coords(tetri);
		x = next_coord[0];
		y = next_coord[1];
		printf("\nNEXT X : %d, NEXT Y : %d", next_coord[0], next_coord[1]);

	}
	if (x + 1 == tetri->size || y + 1 == tetri->size)
		return (0);
	printf("\n%s\n", shape);
	prev = y;
	while (shape[j])
	{
		if (/*x + 1 < tetri->size && y + 1 < tetri->size*/ shape[j] == '#' && grid[x][y] == '.')
		{
			grid[x][y] = shape[j];
			tetri->coords[i]->x = x;
			tetri->coords[i]->y = y;
			i++;
			y++;
		}
		if (shape[j] == '\n')
		{
			x++;
			y = prev;
		}
		if (shape[j] == '.')
			y++;
		j++;
	}
	return (1);	
}

int		ft_putable(char **grid, char ***file, t_tetri *tetri)
{
	int x;
	char *shape;

	x = 0;
	shape = get_piece(file, tetri);
	while (grid[x])
	{
		tetri->curr_x = x;
		if (calc_space(shape, grid, tetri) && x + 1 != tetri->size)
		{
			// DEBUG CORRDS : printf("X : %d, Y: %d\n", tetri->curr_x, tetri->curr_y);
			ft_put(grid, shape, tetri);
			print_grid(grid, tetri->size);
			return (1);
		}
		x++;
	}
	return (0);	
}

void	clear_piece(char **grid, t_tetri *tetri)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 4)
	{
		x = tetri->coords[i]->x;
		y = tetri->coords[i]->y;
		grid[x][y] = '.';
		i++;
	}
}

char	**init_grid(int size)
{
	int i;
	int j;
	char **grid;

	if (!(grid = (char **)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		grid[i] = (char *)malloc(sizeof(char) * size + 1);
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = 0;
	return (grid);
}

int		resolve_algo(char ***file, char **grid, t_tetri *tetri)
{
	
	int i;

	i = 0;
	while (i < tetri->size)
	{
		if (ft_putable(grid, file, tetri))
		{
			tetri->curr_block++;
			if (resolve_algo(file, grid, tetri))
				return (1);
		}
		i++;
	}
	clear_piece(grid, tetri);
	return (0);
}

void	init_coords(t_tetri *tetri)
{
	int i;
	
	tetri->coords = (t_coords**)malloc(sizeof(t_coords*) * 4);
	i = 0;
	while (i < 4)
		tetri->coords[i++] = (t_coords*)malloc(sizeof(t_coords));
}

int		res_algo(char ***file, int c_blocks)
{
	int size;
	char **grid;
	t_tetri *tetri;

	size = 5;
	grid = init_grid(size);
	tetri = malloc(sizeof(t_tetri));
	init_coords(tetri);
	tetri->c_blocks = c_blocks;
	tetri->size = size;
	init_coords(tetri);
	while (!(resolve_algo(file, grid, tetri)))
	{
		tetri->size++;
		grid = init_grid(tetri->size);
		//init_coords(tetri);
		//tetri->curr_block = 0;
	}
	print_grid(grid, size);
	return (0);
}
