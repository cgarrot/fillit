/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 17:42:58 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 18:46:37 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_sqrt(int nb)
{
	int a;

	a = 0;
	if (nb > 0)
	{
		while (a <= nb)
		{
			if (nb == a * a)
				return (a);
			if (a == nb)
				return (0);
			else
				a++;
		}
	}
	else
		return (0);
	return (0);
}

char	**ft_reduct(char **files)
{
	int		i;
	int		j;

	i = 0;
	while (files[i])
	{
		j = 0;
		while (files[i][j])
		{
			if (files[i][j] != '#' && files[i][j] != '\n')
				files[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (files);
}

char	**ft_changetoletter(char **files)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	c = 'A';
	while (files[i])
	{
		j = 0;
		while (files[i][j])
		{
			if (files[i][j] == '#')
				files[i][j] = c;
			j++;
		}
		c++;
		i++;
	}
	return (files);
}

char	**ft_setgrid(int blocks)
{
	char	**grid;
	int		i;
	int		j;
	int		size;

	size =  ft_sqrt(blocks * 4);
	i = size;
	j = 0;
	if (!(grid = (char**)malloc(sizeof(char*) * size)))
		return (0);
	while (size--)
		if (!(grid[j++] = (char*)malloc(sizeof(char) * size + 1)))
			return (0);
	return (grid);
}
