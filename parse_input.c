/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_input.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:58:11 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 15:58:49 by thbrouss    ###    #+. /#+    ###.fr     */
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

char	***parse_file(int fd, int *c_blocks, char ***files)
{
	int			bytes;
	char		buff[BUFF_SIZE + 1];
	t_compt		*comp;

	comp = malloc(sizeof(t_compt));
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
		if (!check_error(files[comp->i]))
			return (NULL);
		comp->i++;
	}
	if (buff[ft_strlen(buff) - 1] == '\n' && buff[ft_strlen(buff) - 2] == '\n')
		return (NULL);
	files[comp->i] = 0;
	return (files);
}
