/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 19:07:09 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 19:57:03 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char		***parse_file(int fd, int *c_blocks)
{
	int		bytes;
	int	i;
	int	j;
	int	k;
	int j_b;
	int	i_b;
	char ***files;
	char	buff[BUFF_SIZE + 1];

	if (!(files = malloc(sizeof(char**) * 26 + 1)))
		return (0);
	i = 0;
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		j = 0;
		files[i] = malloc(sizeof(char*) * 4 + 1);
		j_b = 0;
		while (buff[j])
		{
			if (buff[j] == '\n' && j != 20)
			{
				i_b = j - 1;	
				files[i][j_b] = malloc(sizeof(char) * 4 + 1);
				k = 3;
				while (buff[i_b] != '\n' && buff[i_b])
				{
					files[i][j_b][k] = buff[i_b];
					k--;
					i_b--;
				}
				files[i][j_b][4] = '\0';
				j_b++;
			}
			j++;
		}
		files[i][j_b] = 0;
		//if (!check_error(files[i][j_b], buff[j - 1]))
			//return (NULL);
		i++;
		(*c_blocks)++;
	}
	files[i] = 0;
	return (files);
}
