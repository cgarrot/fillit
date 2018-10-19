/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   backtrack.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 13:46:02 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 14:27:12 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**ft_memalloc2d(size_t block)
{
	char			**tab;
	unsigned int	i;

	i = 0;
	if (!(tab = ft_memalloc(ft_sqrt(block * 4))))
		return (0); 
	while (tab[i])
	{
		if (!(tab[i] = ft_memalloc(ft_sqrt(block * 4 + 1))))
			return (0);
		i++;
	}
	return (tab);
}

int		*ft_index(char **tab)
{
	static int	*ind[18];
	int			piece;

	if (piece = (ft_check_pa1(tab) || ft_check_pa2(tab) || ft_check_pa3(tab)
				|| ft_check_pa4_5(tab) || ft_check_pa6_7(tab)))
		ind[piece - 1]++;
	return (ind);
}
