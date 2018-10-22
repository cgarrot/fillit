/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detect_piece.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
<<<<<<< HEAD
/*   Created: 2018/10/18 16:40:51 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 19:20:28 by cgarrot     ###    #+. /#+    ###.fr     */
=======
/*   Created: 2018/10/22 18:04:29 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 19:12:28 by thbrouss    ###    #+. /#+    ###.fr     */
>>>>>>> a0fedf3ca0db3a61966f4d1ad56635d568c07b9c
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "libft.h"

/*int		ft_check_patern(char **tab, int i)
  {
  int	k;

  k = 0;
  while (tab[i])
  {
  if (tab[i] == '#')
  k++;
  i++;
  }
  if (k != 4)
  return (0);
  return (1);
  }*/

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
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i + 1][j + 2] == '#'))
					return (1);
<<<<<<< HEAD
			if (i + 2 < 4 && j - 1 > 0 && i + 1 < 4)
=======
			if (i + 2 < 4 && i + 1 < 4 && j - 1 > 0)
>>>>>>> a0fedf3ca0db3a61966f4d1ad56635d568c07b9c
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 2][j - 1] == '#'))
					return (2);
			if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j + 1] == '#') && (tab[i + 1][j + 2] == '#'))
					return (3);
			if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#'))
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
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i + 1][j + 1] == '#'))
					return (5);
			if (i + 2 < 4 && j - 1 > 0 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 1][j - 1] == '#'))
					return (6);
			if (i - 1 > 0 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i - 1][j + 1] == '#') && (tab[i][j + 2] == '#'))
					return (7);
			if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 1][j + 1] == '#'))
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
			if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i + 1][j] == '#'))
					return (9);
			if (i + 2 < 4 && j - 1 < 0 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i][j - 1] == '#'))
					return (10);
			if (i - 1 > 0 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i - 1][j + 2] == '#'))
					return (11);
			if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 2][j + 1] == '#'))
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
			if (i + 1 < 4 && j + 1 < 4 && j - 1 > 0)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j - 1] == '#'))
					return (13);
			if (i + 2 < 4 && j + 1 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j + 1] == '#') && (tab[i + 2][j + 1] == '#'))
					return (14);
			if (i + 1 < 4 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i + 1][j + 1] == '#') && (tab[i + 1][j + 2] == '#'))
					return (15);
			if (i + 2 < 4 && j - 1 > 0 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j - 1] == '#') && (tab[i + 2][j - 1] == '#'))
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
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (j + 3 < 4 && j + 2 < 4 && j + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i][j + 3] == '#'))
					return (17);
			if (i + 3 < 4 && i + 2 < 4 && i + 1 < 4)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 3][j] == '#'))
					return (18);
			if (i + 1 < 5 && j + 1 < 5)
				if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j + 1] == '#') && (tab[i][j + 1] == '#'))
					return (19);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_all(char **tab)
{
	int res;

	if ((res = ft_check_pa1(tab)))
		return (res);
	else if ((res = ft_check_pa2(tab)))
		return (res);
	else if ((res = ft_check_pa3(tab)))
		return (res);
	else if ((res = ft_check_pa4_5(tab)))
		return (res);
	else if ((res = ft_check_pa6_7(tab)))
		return (res);
	return (0);
}
