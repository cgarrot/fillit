/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 18:24:41 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 13:40:45 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		check_len(char *file)
{
	int i;
	int j;
	int count_l;

	i = 0;
	count_l = 0;
	while (file[i])
	{
		if (file[i] == '\n' && file[i + 1] != '\0')
		{
			j = i;
			count_l = 0;
			while (j-- && file[j] && file[j] != '\n')
				count_l++;
			if (count_l != 4)
				return (0);
		}	
		i++;
	}
	return (1);
}


int		check_next_to(char *file)
{
	int i;
	int c_con;

	c_con = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '#')
		{
				if ((file[i - 1] && file[i - 1] == '#') || (file[i + 1] && file[i + 1] == '#'))
					c_con++;
				if ((file[i + 2] && file[i + 5] == '#') || (file[i - 2]  && file[i - 5] == '#'))
					c_con++;
		}
		i++;
	}
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
			files[i][j] = '\0';
			if (files[i][j - 1] != '\n')
				return (0);
			if (ft_strfind(files[i], '#') != 4)
				return (0);
			if (!check_len(files[i]))
				return (0);
			check_next_to(files[i]);
			//printf("%s", files[i]);
		}
		i++;
	}
	// TEST : print_tab(files);
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
		ft_putstr("malloc error");
		return (0);	
	}
	if (ac != 2)
		write(1, "usage /fillit [file]\n", 21);
	else
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("error");
			return (0);
		}
		if (!parse_file(fd, files))
			ft_putstr("error\n");
	}
}
