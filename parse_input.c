/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 16:54:06 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:37:41 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 19:07:09 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 16:52:07 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char		***parse_file(int fd, int *c_blocks)
{
	int		bytes;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t j_b;
	size_t	i_b;
	char ***files;
	char	buff[BUFF_SIZE + 1];

	if (!(files = malloc(sizeof(char**) * 26 + 1)))
		return (0);
	i = 0;
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (ft_strcount(buff, '\n') && ft_strcount(buff, '#'))
		{
			j = 0;
			files[i] = malloc(sizeof(char*) * 4 + 1);
			j_b = 0;
			while (buff[j])
			{
				if (buff[j] == '\n' && j != 20)
				{
					i_b = j - 1;
					files[i][j_b] = malloc(sizeof(char) * 4 + 1);
					//printf("%c", buff[i_b]);
					k = 0;
					while (buff[i_b] && buff[i_b] != '\n')
					{
						files[i][j_b][k] = buff[i_b];
						k++;
						i_b--;
						//printf("%c", files[i][j][k]);
						//printf("%c", files[i][j_b][k]);
					}
					files[i][j_b][k] = '\0';
					j_b++;
				}
				j++;
			}
			files[i][j_b] = 0;
			//if (!check_error(files[i], files[i][j - 1]))
				//return (NULL);
			i++;
		}
		(*c_blocks)++;
	}
	files[i] = 0;
	return (files);
}
