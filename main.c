/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 14:57:52 by thbrouss     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/10/23 16:55:34 by thbrouss    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/10/23 15:59:03 by cgarrot     ###    #+. /#+    ###.fr     */
>>>>>>> 95977fc93b55c8512d4204a5d36d1dd6a6a398a6
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
			ft_putchar('\n');
			j++;
		}
		printf("%d\n", i);

		ft_putchar('\n');
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
		printf("%d", c_blocks);
		/*while (i < c_blocks)
		{
			// CALL TEST printf("\n%s\n", call_all(ft_check_all(files[i])));
			i++;
		}*/
		res_algo(files, c_blocks);
	}
}
