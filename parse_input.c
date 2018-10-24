/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 19:07:09 by thbrouss     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/10/24 12:50:39 by thbrouss    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/10/24 13:46:23 by cgarrot     ###    #+. /#+    ###.fr     */
>>>>>>> 355a3b6d3c4374e227f4dfa815bc21dbcb0ae09c
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		parse_cpy(char ***files, char *buff, t_compt *comp)
{
	if (buff[comp->j] == '\n' && comp->j != 20)
	{
		comp->i_b = comp->j - 1;
		files[comp->i][comp->j_b] = ft_memalloc(sizeof(char) * 5);
		comp->k = 3;
		while (buff[comp->i_b] != '\n' && buff[comp->i_b])
			files[comp->i][comp->j_b][comp->k--] = buff[comp->i_b--];
		files[comp->i][comp->j_b][4] = '\0';
		comp->j_b++;
		return (1);
	}
	else
		return (0);
}

char	***parse_file(int fd, int *c_blocks)
{
	int			bytes;
	char		***files;
	char		buff[BUFF_SIZE + 1];
	t_compt		*comp;

	comp = malloc(sizeof(t_compt));
	files = ft_memalloc(sizeof(char**) * 27);
	comp->i = 0;
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0 && ((*c_blocks)++ != 27))
	{
		buff[bytes] = '\0';
		files[comp->i] = ft_memalloc(sizeof(char*) * 5);
		comp->j = 0;
		comp->j_b = 0;
		while (buff[comp->j++])
			if (parse_cpy(files, buff, comp) == 1)
				;
		files[comp->i][comp->j_b] = 0;
<<<<<<< HEAD
		//if (!check_error(files[comp->i][comp->j_b], buff[comp->j - 1]))
			//return (NULL);
=======
		if (!check_error(files[comp->i]))
			return (NULL);
>>>>>>> 355a3b6d3c4374e227f4dfa815bc21dbcb0ae09c
		comp->i++;
	}
	files[comp->i] = 0;
	return (files);
}
