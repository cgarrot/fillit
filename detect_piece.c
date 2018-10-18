/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   detect_piece.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:40:51 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 17:54:39 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_check_patern(char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				k++;
			j++;
		}
		i++;
	}
	if (k != 4)
		return (0);
	return (1);
}

int		ft_check_pa1(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i + 1][j + 2] == '#'))
				return (1);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 2][j - 1] == '#'))
				return (2);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j + 1] == '#') && (tab[i + 1][j + 2] == '#'))
				return (3);
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#'))
				return (4);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_pa2(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i + 1][j + 1] == '#'))
				return (5);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 1][j - 1] == '#'))
				return (6);
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i - 1][j + 1] == '#') && (tab[i][j + 2] == '#'))
				return (7);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 1][j + 1] == '#'))
				return (8);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_pa3(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i + 1][j] == '#'))
				return (9);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i][j - 1] == '#'))
				return (10);
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i - 1][j + 2] == '#'))
				return (11);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 2][j + 1] == '#'))
				return (12);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_pa4_5(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j - 1] == '#'))
				return (13);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j + 1] == '#') && (tab[i + 2][j + 1] == '#'))
				return (14);
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i + 1][j + 1] == '#') && (tab[i + 1][j + 2] == '#'))
				return (15);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j - 1] == '#') && (tab[i + 2][j - 1] == '#'))
				return (16);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_pa6_7(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == '#') && (tab[i][j + 1] == '#') && (tab[i][j + 2] == '#') && (tab[i][j + 3] == '#'))
				return (17);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 2][j] == '#') && (tab[i + 3][j] == '#'))
				return (18);
			if ((tab[i][j] == '#') && (tab[i + 1][j] == '#') && (tab[i + 1][j + 1] == '#') && (tab[i][j + 1] == '#'))
				return (19);
			j++;
		}
		i++;
	}
	return (0);
}