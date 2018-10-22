/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 14:57:52 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:38:28 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	print_tab(char ***tab)
{
	int i;
	int j;
	int k;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			k = 0;
			while (tab[i][j][k])
			{
				ft_putchar(tab[i][j][k]);
				k++;
			}
			//ft_putchar('\n');
			j++;
		}
		//ft_putchar('\n');
		i++;
	}
}



int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	***files;
	int		c_blocks;

	i = 0;
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
		print_tab(files);
		//res_algo(files, c_blocks);
	}
}
