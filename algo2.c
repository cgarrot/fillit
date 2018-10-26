/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 05:41:37 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 06:16:35 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_space(char *shape, char **grid, t_tetri *tetri, t_compt *comp)
{
	t_compt	*comp_space;

	comp_space = malloc(sizeof(t_compt));
	comp_space->x = comp->a;
	comp_space->y = comp->b;
	comp_space->c_place = 0;
	comp_space->i = -1;
	while (shape[++(comp_space->i)])
	{
		if (shape[comp_space->i] == '\n' && comp_space->x++ != -1)
			comp_space->y = comp->b;
		if (comp_space->x == tetri->size || comp_space->y == tetri->size)
			return (0);
		if (shape[comp_space->i] == '#' &&
				grid[comp_space->x][comp_space->y] == '.')
		{
			comp_space->c_place++;
			comp_space->y++;
		}
		if (shape[comp_space->i] == '.')
			comp_space->y++;
	}
	if (comp_space->c_place < 4)
		return (0);
	return (1);
}

void	clear_piece(char **grid, char *shape, t_compt *comp, t_tetri *tetri)
{
	int		x;
	int		y;
	int		i;
	int		j;

	j = -1;
	i = 0;
	x = comp->a;
	y = comp->b;
	while (shape[++j])
	{
		if (shape[j] == '\n' && x++ != -1)
			y = comp->b;
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
	}
}

char	**init_grid(int size)
{
	int		i;
	int		j;
	char	**grid;

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
	if (!grid[i + 1])
		ft_putchar('\n');
}

char	*get_piece(char ***file, int block)
{
	if (file[block] != NULL)
		return (call_all(ft_check_all(file[block])));
	return (NULL);
}
