/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 15:45:48 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 20:23:12 by thbrouss    ###    #+. /#+    ###.fr     */
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

int 	calc_long(int k, char *piece)
{
	int i;

	i = 0;
	while (piece[i] && piece[i] != '\n' && piece[i] != '.')
		i++;
	if (k == i)
		return (1);
	return (0);
}	

char	*get_piece(char **file, int x)
{
	int y;
	int len;
	int i;
	char *tetri;

	len = 0;
	y = 0;
	while (file[x][y])
	{

		if (file[x][y] == '#')
		{
			len++;
			while (file[x][y] == '#')
			{
				y++;
				len++;
			}
			len++;
		}
		y++;
	}
	if (!(tetri = malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	y = 0;
	while (file[x][y])
	{
		if (file[x][y] == '#')
		{
			while (file[x][y] == '#')
			{
				tetri[i] = file[x][y];
				i++;
				y++;
			}
			tetri[i] = '\n';
		}
		y++;
	}
	tetri[i] = '\0';
	return (tetri);	
}



int		*ft_putable(char **grid, char **file, int i)
{
	int x;
	int y;
	static int coords[2];
	int k;

	x = 0;
	while (grid[x])
	{
		y = 0;
		while (grid[x][y])
		{
			if (grid[x][y] == '.')
			{
				k = 0;
				while (grid[x][y + k] == '.' && grid[x][y + k] != '#')
					k++;
				if (calc_long(k, get_piece(file, i)))
				{
					coords[0] = x;
					coords[1] = y;
					return (coords);
				}
			}	
			y++;
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

void	clear_grid(char **grid, char *file, int *coords)
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
	int *coords;

	i = 0;
	if (x == c_blocks)
		return (1);
	while (i < size)
	{
		if ((coords = ft_putable(grid, file, x)))
		{
			ft_put(grid, file, coords, x);
			// check si on peut poser la piece suivante du file, juste apres la piece du grid.
			//print_grid(grid, size);
			printf(" coords x : %d, coords y : %d", coords[0], coords[1]);
			if (resolve_algo(file, x + 1, grid, size, c_blocks))
				return (1);
			else
				clear_grid(grid, file[x], coords);
		}
		i++;
	}
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

int		res_algo(char **file, int c_blocks)
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
