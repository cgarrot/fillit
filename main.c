/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 14:57:52 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 22:27:01 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

char	**ft_lol(char *tab)
{
	int l;
	int j;
	int k;
	char	**yes;

	l = 0;
	j = 0;
	k = 0;
	yes = ft_memalloc2d(4, 5);
	while (tab[l])
	{
		if (tab[l] == '\n' && tab[l + 1] == '\n')
		{
			yes[j][k] = '\0';
			return (yes);
		}
		if (tab[l] == '\n')
		{
			yes[j][k] = '\0';
			j++;
			k = 0;
		}
		ft_strcpy(yes[j], tab);
		l++;
		k++;
	}
	return (yes);
}

void	ft_testrqk(int bloc, char **files)
{
	int i;

	i = 0;
	while (files[i])
	{
		ft_putstr2d(ft_input_letter(bloc, ft_index(ft_lol(files[i]))));
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	char	**files;
	int		c_blocks;

	c_blocks = 0;
	files = NULL;
	if (ac != 2)
		write(1, "usage /fillit [file]\n", 21);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("error");
			return (0);
		}
		if (!(files = parse_file(fd, &c_blocks)))
		{
			ft_putstr("error\n");
			return (0);
		}
		ft_testrqk(c_blocks, files);
	}
}
