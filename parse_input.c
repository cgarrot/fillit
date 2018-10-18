/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 18:24:41 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 20:19:37 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		check_error(int c_hash, char *line, int type)
{
	if (type == LINE_L && ft_strlen(line) > 4)
	{
		ft_putstr("error\n");
		return (0);
	}else if (type == HASH_N && c_hash > 4)
	{	
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}	

int		check_next_to(char **file, int pos)
{
	int i;
	int c_con;

	c_con = 0;
	i = 0;
	while (i < 20)
	{
		if (file[pos][i] == '#')
		{
				if (file[pos - 1][i] == '#' || file[pos + 1][i] == '#')
					c_con++;
				if (file[pos][i + 1] == '#' || file[pos][i - 1] == '#')
					c_con++;
		}
		i++;
	}
	printf("%d", c_con);	
	if (c_con == 6 || c_con == 8)
		return (1);
	return (0);	
}

int		ft_strfind(char *str, int c)
{
	int count;

	count = 0;
	while(*str)
	{
		if (*str == c)
			count++;
		str++;		
	}
	return (count);
}

void	print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
}

int		parse_file(int fd, char **files)
{
	int bytes;
	int len;
	int i;
	int j;
	char buff[BUFF_SIZE + 1];
	
	files = (char **)malloc(sizeof(char *) * 26 + 1);
	i = 0;
	len = 0;
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			j = 0;
			len = ft_strlen(buff);
			files[i] = (char*)malloc(sizeof(char)*ft_strlen(buff) + 1);
			while (j < len)
			{
				files[i][j] = buff[j];
				j++;
			}
		}
		i++;
	}
	print_tab(files);
	files[i] = 0;
	return (1);
}

int		main(int ac, char **av)
{
	int i;
	int fd;
	char **files;

	i = 1;
	if(!(files = (char **)malloc(sizeof(char) * 26 + 1)))
	{
		ft_putstr("error");
		return (0);		
	}
	if (ac != 2)
		write(1, "usage /fillit [file]\n", 27);
	else
	{
		fd = open(av[i], O_RDONLY);
		if (!parse_file(fd, files))
			ft_putstr("error\n");
	}
}
