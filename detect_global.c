/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dectect_global.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 18:23:27 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 15:40:11 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	*call_pa2(int n)
{
	if (n == 13)
		return (P13);
	if (n == 14)
		return (P14);
	if (n == 15)
		return (P15);
	if (n == 16)
		return (P16);
	if (n == 17)
		return (P17);
	if (n == 18)
		return (P18);
	if (n == 19)
		return (P19);
	return (NULL);
}

char	*call_pa1(int n)
{
	if (n == 1)
		return (P1);
	if (n == 2)
		return (P2);
	if (n == 3)
		return (P3);
	if (n == 4)
		return (P4);
	if (n == 5)
		return (P5);
	if (n == 6)
		return (P6);
	if (n == 7)
		return (P7);
	if (n == 8)
		return (P8);
	if (n == 9)
		return (P9);
	if (n == 10)
		return (P10);
	if (n == 11)
		return (P11);
	if (n == 12)
		return (P12);
	return (NULL);
}

char	*call_all(int n)
{
	if (n > 0 && n < 13)
		return (call_pa1(n));
	if (n > 12 && n < 20)
		return (call_pa2(n));
	return (NULL);
}

int		ft_check_all(char **tab)
{
	return (get_checker(tab));
}
