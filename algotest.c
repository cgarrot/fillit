/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algotest.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 22:02:09 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 22:37:44 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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

char	**ft_solve(char ***file; int blocks)
{
	char	**grid;
	int		i;
	int		j;
	int		j_2;
	int		k;
	int		k_2;
	int		ret;

	i = 0;
	k_2 = 0;
	grid = ft_setgrid(blocks);
	
}

#####
..#.#
###.#
###..
.##..

