/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 12:56:23 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 15:45:07 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		set_grid(char **grid, t_tetri *tetri, t_shape **shape_op, char shape)
{
	if (shape == '\n')
	{
		tetri->tmp_y = tetri->curr_y;
		tetri->tmp_x++;
	}
	if (tetri->tmp_x == tetri->size || tetri->tmp_y == tetri->size)
		return (0);
	if (shape == '#' && grid[tetri->tmp_x][tetri->tmp_y] == tetri->c)
	{
		if (tetri->type == CLEAR)
			grid[tetri->tmp_x][tetri->tmp_y] = '.';
		else if (tetri->type == PUT)
		{
			shape_op[tetri->curr_block]->pos_x[tetri->i_pos] = tetri->tmp_x;
			shape_op[tetri->curr_block]->pos_y[tetri->i_pos++] = tetri->tmp_y;
			grid[tetri->tmp_x][tetri->tmp_y] = shape;
		}
		else if (tetri->type == CHECK)
			tetri->c_place++;
		tetri->tmp_y++;
	}
	if (shape == '.')
		tetri->tmp_y++;
	return (1);
}

int		ft_op(char **grid, t_tetri *tetri, int type, t_shape **shape_op)
{
	int		j;
	char	*shape;

	tetri->tmp_x = tetri->curr_x;
	tetri->tmp_y = tetri->curr_y;
	tetri->c_place = 0;
	tetri->type = type;
	tetri->i_pos = 0;
	shape = shape_op[tetri->curr_block]->pattern;
	j = 0;
	if (type == PUT || type == CHECK)
		tetri->c = '.';
	else if (type == CLEAR)
		tetri->c = '#';
	while (shape[j])
	{
		if (!(set_grid(grid, tetri, shape_op, shape[j])))
			return (0);
		j++;
	}
	if (type == CHECK && tetri->c_place < 4)
		return (0);
	return (1);
}

int		search_algo(char **grid, t_tetri *tetri,
		int block, t_shape **shape_info)
{
	int i;
	int j;

	if (tetri->c_blocks == block)
		return (1);
	i = 0;
	while (i < tetri->size)
	{
		j = 0;
		while (j < tetri->size)
		{
			set_info(tetri, i, j, block);
			if (ft_op(grid, tetri, CHECK, shape_info))
			{
				ft_op(grid, tetri, PUT, shape_info);
				if (search_algo(grid, tetri, block + 1, shape_info))
					return (1);
				set_info(tetri, i, j, block);
				ft_op(grid, tetri, CLEAR, shape_info);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		res_algo(int c_blocks, t_shape **shape)
{
	int			size;
	char		**grid;
	t_tetri		*tetri;

	size = 2;
	grid = init_grid(size);
	tetri = malloc(sizeof(t_tetri));
	tetri->c_blocks = c_blocks;
	tetri->size = size;
	while (!(search_algo(grid, tetri, 0, shape)))
	{
		tetri->size++;
		grid = init_grid(tetri->size);
		tetri->curr_block = 0;
	}
	to_letter(grid, tetri, shape);
	print_grid(grid);
	free(grid);
	return (0);
}
