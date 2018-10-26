/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 15:45:48 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 06:20:34 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <unistd.h>

char g_c = 'A';

void	ft_changetoletter(char **files)
{
	int	i;
	int	j;

	i = 0;
	while (files[i])
	{
		j = 0;
		while (files[i][j])
		{
			if (files[i][j] == '#')
				files[i][j] = g_c;
			j++;
		}
		i++;
	}
}

int		ft_put(char **grid, char *shape, t_tetri *tetri, t_compt *comp)
{
	t_compt	*comp_put;

	comp_put = malloc(sizeof(t_compt));
	comp_put->j = -1;
	comp_put->i = 0;
	comp_put->x = comp->a;
	comp_put->y = comp->b;
	while (shape[++(comp_put->j)])
	{
		if (shape[comp_put->j] == '\n' && comp_put->x++ != -1)
			comp_put->y = comp->b;
		if (shape[comp_put->j] == '#' && grid[comp_put->x][comp_put->y] == '.')
		{
			grid[comp_put->x][comp_put->y] = shape[comp_put->j];
			ft_changetoletter(grid);
			tetri->coords[comp_put->i]->x = comp_put->x;
			tetri->coords[comp_put->i]->y = comp_put->y;
			comp_put->i++;
			comp_put->y++;
		}
		if (shape[comp_put->j] == '.')
			comp_put->y++;
	}
	g_c++;
	return (1);
}

int		ft_putable(char **grid, char ***file,
		t_compt *comp, t_tetri *tetri)
{
	char *shape;

	shape = get_piece(file, tetri->bloc_put);
	if (tetri->curr_x + 1 == tetri->size || tetri->curr_y + 1 == tetri->size
			|| tetri->curr_y < 0 || tetri->curr_x < 0)
		return (0);
	if (!check_space(shape, grid, tetri, comp))
		return (0);
	ft_put(grid, shape, tetri, comp);
	return (1);
}

int		resolve_algo(char ***file, char **grid, t_tetri *tetri, int block)
{
	t_compt *comp;

	comp = malloc(sizeof(t_compt));
	tetri->bloc_put = block;
	if (tetri->c_blocks == tetri->bloc_put)
		return (1);
	comp->a = -1;
	while (++(comp->a) < tetri->size)
	{
		comp->b = 0;
		while (comp->b < tetri->size)
		{
			tetri->curr_x = comp->a;
			tetri->curr_y = comp->b;
			if (ft_putable(grid, file, comp, tetri))
			{
				if (resolve_algo(file, grid, tetri, tetri->bloc_put + 1))
					return (1);
				clear_piece(grid, get_piece(file, block), comp, tetri);
			}
			comp->b++;
		}
	}
	return (0);
}

int		res_algo(char ***file, int c_blocks)
{
	int			size;
	char		**grid;
	t_tetri		*tetri;

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
		g_c = 'A';
		tetri->curr_block = 0;
	}
	print_grid(grid);
	return (0);
}
