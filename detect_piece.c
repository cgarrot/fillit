/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detect_piece.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 19:25:09 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 18:26:14 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_pat1(char **tab, int i, int j)
{
	if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') &&
				(tab[i][j + 2] == '#') && (tab[i + 1][j + 2] == '#'))
			return (1);
	if (i + 2 < 4 && i + 1 < 4 && j - 1 >= 0)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
				(tab[i + 2][j] == '#') && (tab[i + 2][j - 1] == '#'))
			return (2);
	if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i +
					1][j + 1] == '#') && (tab[i + 1][j + 2] == '#'))
			return (3);
	if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') &&
				(tab[i + 1][j] == '#') && (tab[i + 2][j] == '#'))
			return (4);
	if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') &&
				(tab[i][j + 2] == '#') && (tab[i + 1][j + 1] == '#'))
			return (5);
	if (i + 1 < 4 && j - 1 >= 0 && i + 2 < 4)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
				(tab[i + 1][j - 1] == '#') && (tab[i + 2][j] == '#'))
			return (6);
	return (0);
}

int		check_pat2(char **tab, int i, int j)
{
	if (j - 1 >= 0 && i + 1 < 4 && j + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i +
					1][j + 1] == '#') && (tab[i + 1][j - 1] == '#'))
			return (7);
	if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
				(tab[i + 2][j] == '#') && (tab[i + 1][j + 1] == '#'))
			return (8);
	if (i - 1 >= 0 && j + 1 < 4 && j + 2 < 4)
		if ((tab[i][j] == '#') && (tab[i - 1][j] == '#') && (tab[i -
					1][j + 1] == '#') && (tab[i - 1][j + 2] == '#'))
			return (9);
	if (i + 1 < 4 && j + 1 < 4 && i + 2 < 4)
		if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i +
					1][j + 1] == '#') && (tab[i + 2][j + 1] == '#'))
			return (10);
	if (j - 1 > 0 && i + 1 < 4 && j - 2 >= 0)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i
					+ 1][j - 1] == '#') && (tab[i + 1][j - 2] == '#'))
			return (11);
	if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
				(tab[i + 2][j] == '#') && (tab[i + 2][j + 1] == '#'))
			return (12);
	return (0);
}

int		check_pat3(char **tab, int i, int j)
{
	if (i + 1 < 4 && j + 1 < 4 && j - 1 >= 0)
		if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i +
					1][j] == '#') && (tab[i + 1][j - 1] == '#'))
			return (13);
	if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i +
					1][j + 1] == '#') && (tab[i + 2][j + 1] == '#'))
			return (14);
	if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i +
					1][j + 1] == '#') && (tab[i + 1][j + 2] == '#'))
			return (15);
	if (j + 1 < 4 && i - 1 >= 0 && i - 2 >= 0)
		if ((tab[i][j] == '#') && (tab[i - 1][j] == '#') && (tab[i -
					1][j + 1] == '#') && (tab[i - 2][j + 1] == '#'))
			return (16);
	if (j + 3 < 4 && j + 2 < 4 && j + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') &&
				(tab[i][j + 2] == '#') && (tab[i][j + 3] == '#'))
			return (17);
	if (i + 3 < 4 && i + 2 < 4 && i + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
				(tab[i + 2][j] == '#') && (tab[i + 3][j] == '#'))
			return (18);
	return (0);
}

int		check_pat4(char **tab, int i, int j)
{
	if (i + 1 < 4 && j + 1 < 4)
		if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
				(tab[i + 1][j + 1] == '#') && (tab[i][j + 1] == '#'))
			return (19);
	return (0);
}

int		get_checker(char **tab)
{
	int i;
	int j;
	int res;

	i = 0;
	res = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((res = check_pat1(tab, i, j)))
				return (res);
			else if ((res = check_pat2(tab, i, j)))
				return (res);
			else if ((res = check_pat3(tab, i, j)))
				return (res);
			else if ((res = check_pat4(tab, i, j)))
				return (res);
			j++;
		}
		i++;
	}
	return (0);
}
