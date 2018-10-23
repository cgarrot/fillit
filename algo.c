/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 15:45:48 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 21:19:52 by thbrouss    ###    #+. /#+    ###.fr     */
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

int		get_dim2(char *line)
{
	int c_l;

	c_l = 0;
	while (*line)
	{
		if (*line == '\n')
			c_l++;
		line++;
	}
	return (c_l);
}

int	get_dim(char *line)
{
	int c_l;

	c_l = 0;
	while (*line != '\n')
	{
		c_l++;
		line++;
	}
	return (c_l);
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
	int longeur;

	i = 0;
	x = tetri->curr_x;
	k = 0;
	l = 0;
	longeur = 0;
	next_line = 0;
	if (line == NULL)
		return (0);
	j = 0;
	space = 0;
	while (grid[x][i])
	{
		k = x;
		l = i;
		longeur = 0;
		while (line[j])
		{
			if (line[j] == '\n' && k + 1 < tetri->size && grid[k + 1][l] == '.')
			{
				next_line++;
				k++;
			}
			if (line[j] == '#' && grid[k][l] == '.' && l + 1 < tetri->size)
			{	
				l++;
				space++;
			}
			if (line[j] == '.' && grid[k][l] == '.' && l + 1 < tetri->size)
			{
				l++;
				space++;
			}		
			j++;
		}
		if (next_line + space == ft_strlen(line))
		{
			if (tetri->curr_block == 0)
				tetri->curr_y = 0;
			else
			{
				tetri->curr_x = x;
				tetri->curr_y = get_dim(line) + 1;
			}
			return (1);
		}
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

void	ft_put(char **grid, char *shape, t_tetri *tetri)
{
	int x;
	int y;
	int j;
	int tmp;

	j = 0;
	tmp = 0;
	x = tetri->curr_x;
	y = tetri->curr_y;
	if (x + 1 == tetri->size || y + 1 == tetri->size)
		return ;
	while (shape[j])
	{
		if (shape[j] == '\n')
		{
			x++;
			y = tetri->curr_y;
		}
		if (shape[j] == '.' && grid[x][y] == '.')
			y++;
		if (shape[j] == '#' && grid[x][y] == '.')
		{
			grid[x][y] = shape[j];
			y++;
		}
		j++;
	}	
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
			printf("X : %d, Y: %d\n", tetri->curr_x, tetri->curr_y);
			ft_put(grid, shape, tetri);
			print_grid(grid, tetri->size);
			return (1);
		}
		x++;
	}
	return (0);	
}

void	clear_piece(char **grid, char *shape, t_tetri *tetri)
{
	int x;
	int y;
	int j;

	j = 0;
	x = tetri->curr_x;
	y = tetri->curr_y;
	if (x + 1 == tetri->size || y + 1 == tetri->size)
		return ;
	while (shape[j])
	{
		if (shape[j] == '\n')
		{
			x++;
			y = tetri->curr_y;
		}
		if (shape[j] == '.' && grid[x][y] == '.')
			y++;
		if (shape[j] == '#' && grid[x][y] == '.')
		{
			grid[x][y] = shape[j];
			y++;
		}
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
	clear_piece(grid, get_piece(file, tetri), tetri); 
	return (0);
}

int		res_algo(char ***file, int c_blocks)
{
	int size;
	char **grid;
	t_tetri *tetri;

	size = 4;
	grid = init_grid(size);
	tetri = malloc(sizeof(t_tetri));
	tetri->c_blocks = c_blocks;
	tetri->curr_x = 0;
	tetri->curr_y = 0;
	tetri->size = size;
	tetri->curr_block = 0;
	while (!(resolve_algo(file, grid, tetri)))
	{
		tetri->size++;
		grid = init_grid(tetri->size);
		//tetri->curr_block = 0;
	}
	print_grid(grid, size);
	return (0);
}
