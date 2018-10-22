/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 17:42:58 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:09:16 by cgarrot     ###    #+. /#+    ###.fr     */
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
		while (a <= nb)
		{
			if (nb == a * a)
				return (a);
			if (a == nb)
				return (0);
			else
				a++;
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

/*char	**tab2d(char **files, int blocks)
{
	char	**tab;
	int		i;
	int		j;
	int		i2;
	int		j2;
	int		size;

	i = 0;
	j = 0;
	i2 = 0;
	size = blocks * 5;
	if (!(tab = (char**)malloc(sizeof(char*) * size)))
		return (0);
	while (size--)
		if (!(tab[j++] = (char*)malloc(sizeof(char) * 5)))
			return (0);
	j = 0;
	size = blocks * 5;
	while (size--)
	{
		j = 0;
		while (files[i2][j2])
		{
			if (files[i2][j2] == '\n')
				break;
			tab[i][j] = files[i2][j2];
//			printf(" %s\n", tab[i]);
			j++;
			j2++;
		}
		j2++;
		if (files[i2][j2])
		{
			j2 = 0;
			i2++;
		}
		i++;
	}
	return (tab);
}*/




