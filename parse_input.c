/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 18:24:41 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 19:43:55 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdio.h>

static void		store_input(char **files, char *line, int pos)
{
	int len;
	int i;

	len = ft_strlen(line);
	i = 0;
	ft_realloc(files[pos], ft_strlen(line) + 1);
	while (i < len)
	{
		files[pos][i] = line[i]; 
		i++;
	}
}

static void		store_coords(char **files, int pos, t_tetri **tetri)
{
	int len;
	int i;
	int c_coords;

	i = 0;
	len = 0;
	c_coords = 0;
	while (i < len)
	{
		if (files[pos][i] == '#' && c_coords < 5)
		{
			tetri[pos]->coords[c_coords]->line = pos;
			tetri[pos]->coords[c_coords]->col = i;
			c_coords++;
		}	
		i++;
	}

}

int		check_error(int c_hash, char *line, int type)
{
	if (type == LINE_L && ft_strlen(line) > 4)
	{
		ft_putstr("error\n");
		return (0);
	}else if (type == HASH_N && c_hash != 4)
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
	while (file[pos][i])
	{
		if (file[pos][i] == '#')
		{
			if (pos + 1 < 5 || pos - 1 > 0)
			{
				if (file[pos - 1][i] == '#' || file[pos + 1][i] == '#')
					c_con++;
			}else if (i + 1 < 5 || i - 1 > 0)
			{
				if (file[pos][i + 1] == '#' || file[pos][i - 1] == '#')
					c_con++;
			}
		}	
		i++;
	}
	if (c_con == 6 || c_con == 8)
		return (1);
	return (0);	
}

int		parse_file(int fd, char **files, t_tetri **tetri)
{
	char *line;
	int c_line;
	int c_hash;
	int c_total;

	c_hash = 0;
	c_line = 0;
	c_total = 0;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		//if (c_total > 26)
			//return (0);
		//if (!check_error(c_hash, line, LINE_L))
			//return (0);
		if (c_line == 5 && !ft_strchr(line, '\n') && c_hash != 4)
			return (0);
		if (ft_strchr(line, '#'))
			c_hash++;
		if (c_line == 5 && *line != '\n')
			return (0);
		if (c_line == 5 && *line == '\n')
		{
			if (!check_next_to(files, c_total)) 
				return (0);
			if (!check_error(c_hash, line, HASH_N))
				return (0);
			c_total++;
			c_line = 0;
			c_hash = 0;
		}
		if (c_line == 4)
		{
			store_input(files, line, c_total);
			store_coords(files, c_total, tetri);
		}
		c_line++;
	}
	return (1);	
}

static	void	init_lst(t_tetri **tetri)
{	
	int i;
	int j;

	i = 0;
	while (i < 26)
	{
		tetri[i] = (t_tetri *)malloc(sizeof(t_tetri));
		j = 0;
		while (j < 4)
		{
			tetri[i]->coords[j] = (t_coords *)malloc(sizeof(t_coords));
			j++;
		}
		i++;
	}
}	

int		main(int ac, char **av)
{
	int i;
	int fd;
	char **files;
	t_tetri **tetri;

	i = 1;
	tetri = malloc(sizeof(t_tetri*));
	init_lst(tetri);
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
		if (!parse_file(fd, files, tetri))
			ft_putstr("error\n");
	}
}
