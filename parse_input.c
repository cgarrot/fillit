/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 18:24:41 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 22:12:05 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	display_help(void)
{
	write(1, "usage /fillit [args] files\n", 27);
}


void	store_input(char **files, char *line, int pos)
{
	int len;
	int i;

	len = ft_strlen(*line);
	i = 0;
	// files[i] = 1 blocs, files[i][j] = line /n, line /n, line /n. 
	files = (char**)malloc(sizeof(char*) * 1 + 1);
	ft_realloc(files[pos], ft_strlen(*line) + 1); 
	while (i < len)
	{
		files[pos][i] = line[i]; 
		i++;
	}
}


int		check_error(int c_hash, char *line, int type)
{
	int i;
		
	if (type == 0 && ft_strlen(line) > 4)
	{
		ft_pustr("error\n");
		return (0);
	}else if (type == 1 && c_hash != 4)
	{	
		ft_putstr("error\n")
		return (0);
	}
	return (1);
}	

int		parse_file(int fd, char **files)
{
	char **line;
	int c_line;
	int c_hash;
	int c_total;

	c_hash = 0;
	c_line = 0;
	c_total = 0;
	while (get_next_line(fd, &line))
	{
		if (!check_error(c_hsah, *line, 0))
			return (0);
		// TODO : bloc en contact sur l'un des 4 cotes -----> +1Droite, +1Gauche, +1Haut, +1Bas. ------> ....
		if (c_line == 5 && !ft_strchr(*line, '\n') && c_hash != 4)
			return (0);
		if (ft_strchr(*line, '#'))
			c_hash++;
		if (ft_strchr(*line, '\n'))
		{
			if (!check_error(c_hash, *line, 1))
				return (0);
			c_total++;
			c_line = 0;
			c_hsah = 0;
		}
		store_input(files, line, c_total);
		c_line++;
	}
	return (1);	
}


void	display_help(void)
{
	write(1, "usage /fillit [args] files\n", 27);
}

int main(int ac, char **av)
{
	int i;
	int fd;
	char **files;

	i = 1;
	if (ac != 1)
		display_help();
	else
	{
		fd = open(av[i], O_RDONLY);
		if (!parse_file(fd, files))
			ft_putstr("error\n");
	}
}
