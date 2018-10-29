/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   letter.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 15:37:02 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 15:46:00 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	set_pos(t_tetri *tetri, char **grid, t_shape **shape, char c)
{
	int g;
	int k;
	int c_put;

	k = 0;
	c_put = 0;
	while (k < tetri->c_blocks)
	{
		if (c_put >= 4)
			break ;
		g = 0;
		while (g < 4)
		{
			if ((shape[k]->pos_x[g] == tetri->curr_x &&
						shape[k]->pos_y[g] == tetri->curr_y))
			{
				grid[shape[k]->pos_x[g]][shape[k]->pos_y[g]] = c + k;
				c_put++;
			}
			g++;
		}
		k++;
	}
}

void	to_letter(char **grid, t_tetri *tetri, t_shape **shape)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = 'A';
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			tetri->curr_x = i;
			tetri->curr_y = j;
			set_pos(tetri, grid, shape, c);
			j++;
		}
		i++;
	}
}
