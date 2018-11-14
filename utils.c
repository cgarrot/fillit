/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 15:28:27 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 20:19:06 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char		**init_grid(int size)
{
	int		i;
	int		j;
	char	**grid;

	if (!(grid = (char **)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * size + 1)))
			return (0);
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

void		print_grid(char **grid)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		write(1, grid[i], ft_strlen(grid[i]));
		ft_putchar('\n');
		i++;
	}
}

void		set_info(t_tetri *tetri, int i, int j, int block)
{
	tetri->curr_x = i;
	tetri->curr_y = j;
	tetri->curr_block = block;
}

t_shape		**store_pattern(char ***files)
{
	int		i;
	t_shape **shape;
	char	*tmp;

	shape = malloc(sizeof(t_shape*) * 26);
	i = 0;
	while (files[i])
	{
		if (!(shape[i] = malloc(sizeof(t_shape))))
			return (0);
		tmp = malloc(sizeof(char) * 10);
		shape[i]->pattern = tmp;
		free(tmp);
		shape[i]->pattern = call_all(get_checker(files[i]));
		i++;
	}
	return (shape);
}

void		ft_free2d(char **tab)
{
	int		i;

	i = 0;
	if (tab)
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	free(tab);
	tab = NULL;
}

void		ft_free3d(char ***tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tab)
		while (tab[i])
		{
			while (tab[i][j])
			{
				free(tab[i][j]);
				j++;
			}
			free(tab[i]);
			i++;
		}
	free(tab);
	tab = NULL;
}
