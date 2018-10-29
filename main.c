/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:59:57 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 18:20:01 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int				main(int ac, char **av)
{
	int		fd;
	char	***files;
	int		c_blocks;

	c_blocks = 0;
	files = malloc(sizeof(char**) * 27);
	if (ac != 2)
		write(1, "usage /fillit [file]\n", 21);
	else
	{
		if (!(fd = open(av[1], O_RDONLY)))
		{
			ft_putstr("error");
			return (0);
		}
		if (!(files = parse_file(fd, &c_blocks, files)) || c_blocks == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		res_algo(c_blocks, store_pattern(files));
	}
}
