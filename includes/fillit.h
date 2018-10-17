/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 13:11:53 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 18:45:38 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

#include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define LINE_L 0
# define HASH_N 1


typedef struct	s_coords
{
	int line;
	int col;	
}				t_coords;


typedef struct s_tetri
{
	t_coords *coords[4]; // tetri1(x, y), tetri2(x, y), tetri3(x, y), tetri4(x, y).pos[i]->x, tetri[i]->pos[i]->x		
}				t_tetri;

#endif
