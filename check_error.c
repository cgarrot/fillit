/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 14:53:04 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/28 19:17:52 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_line(char **line)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] != '.' && line[i][j] != '#')
				return (-1);
			if (line[i][j] == '.')
				l++;
			j++;
		}
		i++;
	}
	if (l != 12)
		return (-1);
	return (0);
}

int		check_error(char **files)
{
	if (check_line(files) == -1)
		return (0);
	if (ft_check_all(files) < 1)
		return (0);
	return (1);
}
