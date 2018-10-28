/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 12:56:23 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/28 20:37:01 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_op(char **grid, char *shape, t_tetri *tetri, int type, t_shape **shape_op)
{
	char c;
	int j;
	int x;
	int y;
	int c_place;
	int prev;
	int i;
	x = tetri->curr_x;
	y = tetri->curr_y;
	c_place = 0;
	prev = y;
	c = 0;
	j = 0;
	i = 0;
	if (type == PUT || type == CHECK)
		c = '.';
	else if (type == CLEAR)
		c = '#';
	while (shape[j])
	{
		if (shape[j] == '\n')
		{
			y = prev;
			x++;
		}
		if (x == tetri->size || y == tetri->size)
			return (0);
		if (shape[j] == '#' && grid[x][y] == c)
		{
			if (type == CLEAR)
				grid[x][y] = '.';
			else if (type == PUT)
			{
				shape_op[tetri->curr_block]->pos_x[i] = x;
				shape_op[tetri->curr_block]->pos_y[i] = y;
				grid[x][y] = shape[j];
				i++;
			}
			else if (type == CHECK)
				c_place++;
			y++;
		}
		if (shape[j] == '.')
			y++;
		j++;
	}
	if (type == CHECK && c_place < 4)
		return (0);
	return (1);
}


char	*get_piece(char ***file, int block)
{
	if (file[block] != NULL)
		return (call_all(ft_check_all(file[block])));
	return (NULL);
}

/*int		ft_put(char **grid, char *shape, t_tetri *tetri)
  {
  int x;
  int y;
  int j;
  int prev;

  j = 0;
  prev = 0;
  x = tetri->curr_x;
  y = tetri->curr_y;	
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
  y++;
  }
  if (shape[j] == '.')
  y++;
  j++;
  }
  return (1);
  }*/



int		is_putable(char **grid, char ***file, t_tetri *tetri, int block, t_shape **shape_info)
{
	char *shape;

	shape = get_piece(file, block);
	/*if (tetri->curr_x + 1 == tetri->size || tetri->curr_y + 1 == tetri->size
			|| tetri->curr_y < 0 || tetri->curr_x < 0)
		return (0);*/
	/*if (!check_space(shape, grid, tetri))
	  return (0);*/
	if (!ft_op(grid, shape, tetri, CHECK, shape_info))
		return (0);
	ft_op(grid, shape, tetri, PUT, shape_info);
	//ft_put(grid, shape, tetri);
	return (1);	
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
}

/*void	clear_piece(char **grid, char *shape, t_tetri *tetri)
  {
  int x;
  int y;
  int j;
  int prev;

  j = 0;
  x = tetri->curr_x;
  y = tetri->curr_y;
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
  y++;
  }
  if (shape[j] == '.')
  y++;
  j++;
  }
  }*/

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

int		search_algo(char ***file, char **grid, t_tetri *tetri, int block, t_shape **shape_info)
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
			tetri->curr_x = i;
			tetri->curr_y = j;
			tetri->curr_block = block;
			if (is_putable(grid, file, tetri, block, shape_info))
			{
				if (search_algo(file, grid, tetri, block + 1, shape_info))
					return (1);
				tetri->curr_x = i;
				tetri->curr_y = j;
				ft_op(grid, get_piece(file, block), tetri, CLEAR, shape_info);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_shape(t_shape **shape, int c_blocks)
{
	int i;

	i = 0;
	while (i < c_blocks)
	{
		shape[i] = malloc(sizeof(t_shape));
		i++;
	}
}

void	to_letter(char **grid, int c_blocks, t_shape **shape)
{
	int i;
	int j;
	int k;
	int g;
	int c_put;
	char c;


	i = 0;
	c = 'A';
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			k = 0;
			c_put = 0;
			while (k < c_blocks)
			{
				if (c_put >= 4)
				   break;
				g = 0;
				while (g < 4)
				{
					if ((shape[k]->pos_x[g] == i && shape[k]->pos_y[g] == j))
					{	
						grid[shape[k]->pos_x[g]][shape[k]->pos_y[g]] = c + k;
						c_put++;
					}
					g++;		
				}
				k++;
			}
			j++;
		}
		i++;
	}
}


int		res_algo(char ***file, int c_blocks)
{
	int			size;
	char		**grid;
	t_tetri		*tetri;
	t_shape		**shape;

	size = 2;
	grid = init_grid(size);
	shape = malloc(sizeof(t_shape*) * 26);
	init_shape(shape, c_blocks);
	tetri = malloc(sizeof(t_tetri));
	tetri->c_blocks = c_blocks;
	tetri->size = size;
	while (!(search_algo(file, grid, tetri, 0, shape)))
	{
		tetri->size++;
		grid = init_grid(tetri->size);
		tetri->curr_block = 0;
	}
	to_letter(grid, c_blocks, shape);
	print_grid(grid);
	free(grid);
	return (0);
}
