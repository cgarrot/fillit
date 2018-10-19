/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 18:24:41 by thbrouss     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/10/19 16:27:11 by cgarrot     ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/10/19 15:17:51 by thbrouss    ###    #+. /#+    ###.fr     */
>>>>>>> f48be8260f3808e62338e72c1d5825f0a2a3a3c7
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
