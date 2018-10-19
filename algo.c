/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 15:45:48 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 21:12:29 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"


void	place_piece(char *file, char **grid)
{
		
}

int		put_piece(char **file, int x, int y, char **grid, int a, int b)
{
	int i;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '#' && (grid[i + 1][j] != '#' || grid[i - 1][j] != '#' || grid[i][j + 1] != '#' || grid[i][j - 1] != '#'))
			{
				place_piece(file[x], grid, i);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);	
}

void	clear_grid(char *file, char **grid, int x, int y)
{
	int i;
	int len;
	int j;
	char *tab;

	i = 0;
	len = 0;
	while (file[i])
	{
		if (file[i] == '#')
			len++;
	}
	tab = malloc(sizeof(int) * len);
	i = 0;
	while (file[i])
	{
		if (file == '#')
		{
			tab[j] = i;
			j++;
		}	
		i++;
	}
}

void	init_grid(char **grid)
{
	int i;

	if (!(grid = (char **)malloc(sizeof(char) * 30)))
		return ;
	i = 0;
	while (i < 30)
	{
		grid[i] = (char *)malloc(sizeof(char) * 30);
		while (j < 30)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		resolve_algo(char **file, int x, int y, char **grid)
{
	// 1 ) STOCKER TAB ID FORME => 1 OU PLUSIEURS LETTRES.
	// 2 ) SI ON PEUT PLACER LA PIECE, OK, SI LA PIECE NE PEUT PAS ETRE PLACE REVIENT EN ARRIERE(LA OU OK POUR LE PLACEMENT DE LA PIECE) 
	// ET DECALE LA PIECE DE 1. JUSQU A TROUVE LA SOLUTION = CARRE. (racine(L * l) = entiere = 1 carre). 
	// 3 ) PREMIER CARRE TROUVE EST LE BON.
	// 4 ) DISPLAY CARRE EN CHECKANT FORME => LETTRE.
	
	// si on peut poser la piece de file dans le grid.
	if (put_piece(file, x, y, grid))
	{
		// check si on peut poser la piece suivante du file, juste apres la piece du grid.
		if (resolve_algo(file, x + 1, y, grid))
			return (1);
	}
	// si peut pas poser la piece dans le grid, revient au grid avant la piece.
	clear_grid(grid, file[x], y);
}

int		res_algo(char **file, int x, int y, char **grid)
{
	int x;
	int y;

	x = 0;
	y = 0;
	init_grid(grid);
	resolve_algo(file, x, y, grid);
}

