/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 19:07:09 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 20:00:40 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char		**parse_file(int fd, int *c_blocks)
{
	int		bytes;
	size_t	i;
	size_t	j;
	char **files;
	char	buff[BUFF_SIZE + 1];

	if (!(files = (char **)malloc(sizeof(char*) * 26 + 1)))
		return (0);
	i = 0;
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (ft_strcount(buff, '\n') && ft_strcount(buff, '#'))
		{
			j = 0;
			files[i] = ft_memalloc(ft_strlen(buff) + 1);
			while (buff[j])
			{
				files[i][j] = buff[j];
				j++;
			}
			files[i][j] = '\0';
			if (!check_error(files[i], files[i][j - 1]))
				return (NULL);
			i++;
		}
		(*c_blocks)++;
	}
	files[i] = 0;
	return (files);
}
