/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo3.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 06:19:00 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 06:21:08 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

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

int		calc_size(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}
