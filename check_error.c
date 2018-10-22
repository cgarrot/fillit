/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 14:53:04 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 19:22:55 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_len(char *file)
{
	int		i;
	int		j;
	int		count_l;

	i = 0;
	count_l = 0;
	while (file[i])
	{
		if (file[i] == '\n' && file[i + 1] != '\0')
		{
			j = i;
			count_l = 0;
			while (j-- && file[j] && file[j] != '\n')
				count_l++;
			if (count_l != 4)
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_next_to(char *file)
{
	int i;
	int c_con;

	c_con = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '#')
		{
			if (file[i - 1] == '#')
				c_con++;
			if (file[i + 1] == '#')
				c_con++;
			if (file[i + 5] == '#')
				c_con++;
			if (file[i - 5] == '#')
				c_con++;
		}
		i++;
	}
	if (c_con == 6 || c_con == 8)
		return (1);
	return (0);
}

int		check_error(char *file, char n_line)
{
	if (n_line != '\n')
		return (0);
	if (ft_strcount(file, '#') != 4)
		return (0);
	if (!check_len(file))
		return (0);
	if (!check_next_to(file))
		return (0);
	return (1);
}
