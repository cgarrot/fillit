/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detect_piece2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 18:36:36 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 22:07:25 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_check_2pa3(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (j - 1 > 0 && i + 1 < 4 && j - 2 >= 0)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i
							+ 1][j - 1] == '#') && (tab[i + 1][j - 2] == '#'))
					return (11);
			if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
						(tab[i + 2][j] == '#') && (tab[i + 2][j + 1] == '#'))
					return (12);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_pa4_5(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i + 1 < 4 && j + 1 < 4 && j - 1 >= 0)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i +
							1][j] == '#') && (tab[i + 1][j - 1] == '#'))
					return (13);
			if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i +
							1][j + 1] == '#') && (tab[i + 2][j + 1] == '#'))
					return (14);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_2pa4_5(char **tab)
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
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i +
							1][j + 1] == '#') && (tab[i + 1][j + 2] == '#'))
					return (15);
			if (j + 1 < 4 && i - 1 >= 0 && i - 2 >= 0)
				if ((tab[i][j] == '#') && (tab[i - 1][j] == '#') && (tab[i -
							1][j + 1] == '#') && (tab[i - 2][j + 1] == '#'))
					return (16);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_pa6_7(char **tab)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (j + 3 < 4 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') &&
						(tab[i][j + 2] == '#') && (tab[i][j + 3] == '#'))
					return (17);
			if (i + 3 < 4 && i + 2 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
						(tab[i + 2][j] == '#') && (tab[i + 3][j] == '#'))
					return (18);
			if (i + 1 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') &&
						(tab[i + 1][j + 1] == '#') && (tab[i][j + 1] == '#'))
					return (19);
			j++;
		}
	}
	return (0);
}
