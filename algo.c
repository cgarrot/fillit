/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 15:45:48 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 14:47:36 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	print_grid(char **grid, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{

		j = 0;
		while (grid[i][j])
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}		
}

int 	calc_space(char *line, char *piece, int x, int size)
{
	int i;
	int j;
	int next_line;
	int space;

	i = 0;
	next_line = 0;
	space = 0;
	while (line[j])
	{
		if (line[j] == '\n' && piece[x + 1][i] == '.' && x + 1 < size)
		{
			new_line++;
			x++;
		}

		if ((line[j] == '#' || line[j] == '.') && piece[x][i] == '.')
		{
			i++;
			space++;
		}
		j++;
	}
	if (new_line + space == ft_strlen(line))
		return (1);
	return (0);
}	

char	*get_piece(char ***file, int block)
{
	return (call_all(ft_check_all(file[block])));
}

int		*ft_putable(char **grid, char ***file, int i, int size)
{
	int x;
	int y;
	char *shape;
	t_tetri *tetri;

	x = 0;
	tetri = malloc(sizeof(t_tetri));
	shape = get_piece(file, i);
	while (grid[x])
	{
		if (calc_space(shape, grid[x], x, size) && x + 1 < size)
		{
			tetri->x = x;
			tetri->y = 
			//coords[1] = y;
			return (coords);
		}
		x++;
	}
	return (0);	
}

void	ft_put(char **grid, char **file, int *coords, int i)
{
	int x;
	int y;
	int j;
	char *piece;

	piece = get_piece(file, i);
	j = 0;
	x = coords[0];
	y = coords[1];
	while (file[i][j])
	{
		grid[x][y] = file[i][j];
		if (file[i][j] == '\n')
		{
			x++;
			while (grid[x][y] == '#')
				y++;
		}
		else
			y++;
		j++;
	}	
}

void	clear_piece(char **grid, char *file, int *coords)
{
	int x;
	int y;
	int i;

	x = coords[0];
	y = coords[1];
	i = 0;
	while (file[i])
	{
		grid[x][y] = '.';
		if (file[i] == '\n')
		{
			x++;
			while (grid[x][y] == '#')
				y++;
		}
		else
			y++;
		i++;
	}
}

char	**init_grid(int size)
{
	int i;
	int j;
	char **grid;

	if (!(grid = (char **)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		grid[i] = (char *)malloc(sizeof(char) * size + 1);
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

int		resolve_algo(char **file, int x, char **grid, int size, int c_blocks)
{
	// 1 ) STOCKER TAB ID FORME => 1 OU PLUSIEURS LETTRES.
	// 2 )  PLACE LA PIECE EN HAUT A GAUCHE ET CHECK SI ON PEUT POSER LES PIECES SUIVANTES DANS CE CARRE, 
	// SI ON PEUT PAS RETOURNE PIECE INI + 1 ET CHECK AVEC TOUTE LES PIECES.
	// JUSQU AU REMPLISSEMENT DU CARRE. SI LE CARRE NE PEUT PAS ETRE REMPLI, AUGEMENTE LA SIZE.
	// 3 ) PREMIER CARRE TROUVE EST LE BON.
	// 4 ) DISPLAY CARRE EN CHECKANT FORME => LETTRE.

	int i;

	i = 0;
	if (x == c_blocks)
		return (1);
	while (i < size)
	{
		// pas besoin des coords... juste iterer dans le tab.
		if (ft_putable(grid, file, x, size))
		{
			ft_put(grid, file, coords, x); // enregistre les coords
			// check si on peut poser la piece suivante du file, juste apres la piece du grid.
			//print_grid(grid, size);
			//printf(" coords x : %d, coords y : %d", coords[0], coords[1]);
			// TODO : FIXE GET PIECE + COORDS !
			// 
			if (resolve_algo(file, x + 1, grid, size, c_blocks))
				return (1);
		}
		i++;
	}
	clear_piece(grid, file[x], coords); // supprime forme de piece a partir des coords (x, y).
	// si peut pas poser la piece dans le grid, enleve la piece.
	return (0);
}

int		next_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i + 1 * i + 1);
}

int		res_algo(char ***file, int c_blocks)
{
	int x;
	int size;
	char **grid;

	x = 0;
	size = 16;
	// quand init le grid, put la 1er piece.
	grid = init_grid(size);
	while (!(resolve_algo(file, x, grid, size, c_blocks)))
	{
		size = next_sqrt(size);
		grid = init_grid(size);
	}
	//print_grid(grid, size);
	return (0);
}
