/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detect_piece.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:40:51 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 19:18:21 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "libft.h"

int		ft_check_patern(char *tab, int i)
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
}

int		ft_check_pa1(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#' && tab[i + 1] == '#' && tab[i + 2] == '#' && tab[i + 6] == '#')
			return (1);
		else if (tab[i] == '#' && tab[i + 3] == '#' && tab[i + 5] == '#' && tab[i + 6] == '#')
			return (2);
		else if (tab[i] == '#' && tab[i + 4] == '#' && tab[i + 5] == '#' && tab[i + 6] == '#')
			return (3);
		else if (tab[i] == '#' && tab[i + 2] == '#' && tab[i + 3] == '#' && tab[i + 6] == '#')
			return (4);
		i++;
	}
	return (0);
}

int		ft_check_pa2(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#' && tab[i + 1] == '#' && tab[i + 2] == '#' && tab[i + 5] == '#')
			return (5);
		else if (tab[i] == '#' && tab[i + 2] == '#' && tab[i + 3] == '#' && tab[i + 6] == '#')
			return (6);
		else if (tab[i] == '#' && tab[i + 3] == '#' && tab[i + 4] == '#' && tab[i + 5] == '#')
			return (7);
		else if (tab[i] == '#' && tab[i + 3] == '#' && tab[i + 4] == '#' && tab[i + 6] == '#')
			return (8);
			i++;
	}
	return (0);
}

int		ft_check_pa3(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#' && tab[i + 1] == '#' && tab[i + 2] == '#' && tab[i + 4] == '#')
			return (9);
		else if (tab[i] == '#' && tab[i + 1] == '#' && tab[i + 4] == '#' && tab[i + 7] == '#')
			return (10);
		else if (tab[i] == '#' && tab[i + 2] == '#' && tab[i + 3] == '#' && tab[i + 4] == '#')
			return (11);
		else if (tab[i] == '#' && tab[i + 3] == '#' && tab[i + 6] == '#' && tab[i + 7] == '#')
			return (12);
		i++;
	}
	return (0);
}

int		ft_check_pa4_5(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '.' && tab[i + 1] == '#' && tab[i + 2] == '#' && tab[i + 4] == '#' && tab[i + 5] == '#' && tab[i + 6] == '.')
			return (13);
		else if (tab[i] == '#' && tab[i + 3] == '#' && tab[i + 4] == '#' && tab[i + 7] == '#')
			return (14);
		else if (tab[i] == '#' && tab[i + 1] == '#' && tab[i + 5] == '#' && tab[i + 6] == '#')
			return (15);
		else if (tab[i] == '#' && tab[i + 2] == '#' && tab[i + 3] == '#' && tab[i + 5] == '#')
			return (16);
		i++;
	}
	return (0);
}

int		ft_check_pa6_7(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '#' && tab[i + 1] == '#' && tab[i + 2] == '#' && tab[i + 3] == '#')
			return (17);
		else if (tab[i] == '#' && tab[i + 2] == '#' && tab[i + 4] == '#' && tab[i + 6] == '#')
			return (18);
		else if (tab[i] == '#' && tab[i + 1] == '#' && tab[i + 3] == '#' && tab[i + 4] == '#')
			return (19);
		i++;
	}
	return (0);
}

int		ft_check_all(char *tab)
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
