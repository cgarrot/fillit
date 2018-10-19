/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 18:40:54 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 18:40:58 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		parse_file(int fd, char **files, int *c_blocks)
{
	int		bytes;
	size_t	i;
	size_t	j;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	if (!(files = (char **)malloc(sizeof(char) * 26 + 1)))
		return (0);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			j = -1;
			files[i] = (char*)malloc(sizeof(char) * ft_strlen(buff) + 1);
			while (++j < ft_strlen(buff))
				files[i][j] = buff[j];
			files[i][j] = '\0';
			if (!check_error(files[i], files[i][j - 1]))
				return (0);
		}
		(*c_blocks)++;
		i++;
	}
	files[i] = 0;
	return (1);
}
