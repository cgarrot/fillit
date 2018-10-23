/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detect_piece.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 19:25:09 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 18:39:16 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_check_pa1(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') &&
						(tab[i][j + 2] == '#') && (tab[i + 1][j + 2] == '#'))
					return (1);
			if (i + 2 < 4 && i + 1 < 4 && j - 1 >= 0)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
						(tab[i + 2][j] == '#') && (tab[i + 2][j - 1] == '#'))
					return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_2pa1(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i +
							1][j + 1] == '#') && (tab[i + 1][j + 2] == '#'))
					return (3);
			if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') &&
						(tab[i + 1][j] == '#') && (tab[i + 2][j] == '#'))
					return (4);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_pa2(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') &&
						(tab[i][j + 2] == '#') && (tab[i + 1][j + 1] == '#'))
					return (5);
			if (i + 1 < 4 && j - 1 >= 0 && i + 2 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
						(tab[i + 1][j - 1] == '#') && (tab[i + 2][j] == '#'))
					return (6);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_2pa2(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (j - 1 >= 0 && i + 1 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i +
							1][j + 1] == '#') && (tab[i + 1][j - 1] == '#'))
					return (7);
			if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
						(tab[i + 2][j] == '#') && (tab[i + 1][j + 1] == '#'))
					return (8);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_pa3(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i - 1 >= 0 && j + 1 < 4 && j + 2 < 4)
				if ((tab[i][j] == '#') && (tab[i - 1][j] == '#') && (tab[i -
							1][j + 1] == '#') && (tab[i - 1][j + 2] == '#'))
					return (9);
			if (i + 1 < 4 && j + 1 < 4 && i + 2 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i +
							1][j + 1] == '#') && (tab[i + 2][j + 1] == '#'))
					return (10);
			j++;
		}
		i++;
	}
	return (0);
}
