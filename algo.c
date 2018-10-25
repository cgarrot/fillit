/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 15:45:48 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 20:19:29 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <unistd.h>

void	print_grid(char **grid)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
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

char	*get_piece(char ***file, int block)
{
	if (file[block] != NULL)
		return (call_all(ft_check_all(file[block])));
	return (NULL);
}

int		ft_put(char **grid, char *shape, t_tetri *tetri, int a, int b)
{
	int x;
	int y;
	int i;
	int j;
	int prev;

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	prev = 0;
	x = a;
	y = b;	
	prev = y;
	while (shape[j])
	{
		if (shape[j] == '\n')
		{
			x++;
			y = prev;
		}
		if (shape[j] == '#' && grid[x][y] == '.')
		{
			grid[x][y] = shape[j];
			tetri->coords[i]->x = x;
			tetri->coords[i]->y = y;
			i++;
			y++;
		}
		if (shape[j] == '.')
			y++;
		j++;
	}
	return (1);	
}


int		check_space(char *shape, char **grid, t_tetri *tetri, int a, int b)
{
	int y;
	int i;
	int prev;
	int c_place;
	int x;

	x = a;
	y = b;
	c_place = 0;
	i = 0;
	prev = y;
	while (shape[i])
	{
		if (shape[i] == '\n')
		{
			x++;
			y = prev;
		}
		if (x == tetri->size || y == tetri->size)
			return (0);
		if (shape[i] == '#' && grid[x][y] == '.')
		{
			c_place++;
			y++;
		}
		if (shape[i] == '.')
			y++;
		i++;
	}
	if (c_place < 4)
		return (0);
	return (1);
}

int		ft_putable(char **grid, char ***file, int a, int b, int block, t_tetri *tetri)
{
	char *shape;
	
	shape = get_piece(file, block);
	if (tetri->curr_x + 1 == tetri->size || tetri->curr_y + 1 == tetri->size
			|| tetri->curr_y < 0 || tetri->curr_x < 0)
		return (0);
	if (!check_space(shape, grid, tetri, a, b))
		return (0);
	ft_put(grid, shape, tetri, a, b);
	//sleep(1);
	//print_grid(grid);
	return (1);	
}

void	clear_piece(char **grid, char *shape, int a, int b, t_tetri *tetri)
{
	/*int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 4)
	{
		x = tetri->coords[i]->x;
		y = tetri->coords[i]->y;
		printf("X : %d, Y : %d\n", x, y);
		grid[x][y] = '.';
		i++;
	}
	print_grid(grid, tetri->size);*/
	int x;
	int y;
	int i;
	int j;
	int prev;

	j = 0;
	i = 0;
	x = a;
	y = b;
	prev = y;
	while (shape[j])
	{
		if (shape[j] == '\n')
		{
			x++;
			y = prev;
		}
		if (x == tetri->size || y == tetri->size)
			return ;
		if (shape[j] == '#' && grid[x][y] == '#')
		{
			grid[x][y] = '.';
			i++;
			y++;
		}
		if (shape[j] == '.')
			y++;
		j++;
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

int		resolve_algo(char ***file, char **grid, t_tetri *tetri, int block)
{

	int i;
	int j;
	if (tetri->c_blocks == block)
		return (1);
	i = 0;
	while (i <  tetri->size)
	{
		j = 0;
		while (j < tetri->size)
		{
			tetri->curr_x = i;
			tetri->curr_y = j;
			if (ft_putable(grid, file, i, j, block, tetri))
			{
				if (resolve_algo(file, grid, tetri, block + 1))
					return (1);
				clear_piece(grid, get_piece(file, block), i, j, tetri);
			}
			j++;
		}
		i++;
	}
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

void	reset_coords(t_tetri *tetri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tetri->coords[i]->x = 0;
		tetri->coords[i]->y = 0;
		i++;
	}
}

int  calc_size(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);	
}

int		res_algo(char ***file, int c_blocks)
{
	int size;
	char **grid;
	t_tetri *tetri;

	size = 3;
	grid = init_grid(size);
	tetri = malloc(sizeof(t_tetri));
	init_coords(tetri);
	tetri->c_blocks = c_blocks;
	tetri->size = size;
	while (!(resolve_algo(file, grid, tetri, 0)))
	{
		tetri->size++;
		grid = init_grid(tetri->size);
		reset_coords(tetri);
		tetri->curr_block = 0;
	}
	print_grid(grid);
	return (0);
}
