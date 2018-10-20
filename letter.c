/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   letter.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 19:19:39 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 17:35:26 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;
	unsigned int tmp;

	i = 0;
	while (s1[i])
	{
		j = 0;
		tmp = i;
		while (s1[tmp] == s2[j])
		{
			tmp++;
			j++;
		}
		if (j == n - 1)
			return (0);
		i++;
	}
	return (s1 - s2);
}

void	ft_putstr2d(char **tab)
{
	int	i;

	i= -1;
	if (tab)
		while (tab[i++])
			write(1, tab[i], ft_strlen(tab[i]));
}

char	**ft_memalloc2d(int size, int len)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = malloc(sizeof(char*) * size + 1)))
		return (0); 
	while (size--)
	{
		if (!(tab[i] = ft_memalloc(len + 1)))
			return (0);
		i++;
	}
	return (tab);
}

int		**ft_index(char *tab)
{
	static int	*index[19];
	int			piece;
	int			i;
	static int	count = 0;

	i = 0;
	while (i < 19)
	{
		index[i] = malloc(sizeof(int) * 26);
		i++;
	}
	if ((piece = ft_check_pa1(tab)) || (piece = ft_check_pa2(tab)) ||
			(piece = ft_check_pa3(tab)) || (piece = ft_check_pa4_5(tab))
			|| (piece = ft_check_pa6_7(tab)))
	{
		i = 0;
		while (index[piece - 1][i] != 0)
			i++;
		index[piece - 1][i] = count++;
	}
	return (index);
}

char	*ft_search_and_replace(char *src, char c)
{
	int		i;

	i = 0;
	if (src)
		while (src[i])
		{
			if (src[i] == '#')
				src[i] = c;
			i++;
		}
	return (src);
}

char	*ft_search_string(int i)
{
	if (i == 1)
		return (P1_DISP);
	if (i == 2)
		return (P2_DISP);
	if (i == 3)
		return (P3_DISP);
	if (i == 4)
		return (P4_DISP);
	if (i == 5)
		return (P5_DISP);
	if (i == 6)
		return (P6_DISP);
	if (i == 7)
		return (P7_DISP);
	if (i == 8)
		return (P8_DISP);
	if (i == 9)
		return (P9_DISP);
	if (i == 10)
		return (P10_DISP);
	if (i == 11)
		return (P11_DISP);
	if (i == 12)
		return (P12_DISP);
	if (i == 13)
		return (P13_DISP);
	if (i == 14)
		return (P14_DISP);
	if (i == 15)
		return (P15_DISP);
	if (i == 16)
		return (P16_DISP);
	if (i == 17)
		return (P17_DISP);
	if (i == 18)
		return (P18_DISP);
	if (i == 19)
		return (P19_DISP);
	return (0);
}

char	**ft_input_letter(int bloc, int **index)
{
	char			**tab;
	static char		c;
	int				i;
	int				j;
	int				k;

	i = 0;
	c = 'A';
	if (!(tab = ft_memalloc2d(bloc, 9)))
		return (0);
	while (bloc--)
	{
		j = 0;
		while (index[i][j])
		{
			k = index[i][j] - 1;
			tab[k] = ft_search_and_replace(ft_search_string(i), c + (index[i][j] - 1));
			j++;
		}
		i++;
	}
	return (tab);
}
