/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
<<<<<<< HEAD
/*   Created: 2018/10/22 18:41:24 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 18:41:29 by cgarrot     ###    #+. /#+    ###.fr     */
=======
/*   Created: 2018/10/19 19:07:09 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 19:09:40 by thbrouss    ###    #+. /#+    ###.fr     */
>>>>>>> a0fedf3ca0db3a61966f4d1ad56635d568c07b9c
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char		***parse_file(int fd, int *c_blocks)
{
	int		bytes;
<<<<<<< HEAD
	size_t	i;
	size_t	j;
	size_t	k;
	size_t j_b;
	size_t	i_b;
=======
	int	i;
	int	j;
	int	k;
	int j_b;
	int	i_b;
>>>>>>> a0fedf3ca0db3a61966f4d1ad56635d568c07b9c
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
<<<<<<< HEAD
				if (buff[j] == '\n' && j != 20)
=======
				i_b = j - 1;
				files[i][j_b] = malloc(sizeof(char) * 4 + 1);
				k = 0;
				while (buff[i_b] != '\n' && buff[i_b])
>>>>>>> a0fedf3ca0db3a61966f4d1ad56635d568c07b9c
				{
					files[i][j_b][k] = buff[i_b];
					k++;
					i_b--;
				}
<<<<<<< HEAD
				files[i][j][k] = buff[j];
				j++;
=======
				files[i][j_b][k] = '\0';
				j_b++;
>>>>>>> a0fedf3ca0db3a61966f4d1ad56635d568c07b9c
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
