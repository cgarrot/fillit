/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:59:30 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 06:25:45 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct	s_coords
{
	int		x;
	int		y;
}				t_coords;

typedef struct	s_compt
{
	int		i;
	int		j;
	int		k;
	int		i_b;
	int		j_b;
	int		a;
	int		b;
	int		x;
	int		y;
	int		c_place;
}				t_compt;

typedef struct	s_tetri
{
	int			curr_block;
	int			c_blocks;
	int			size;
	int			curr_x;
	int			curr_y;
	t_coords	**coords;
	int			bloc_put;
}				t_tetri;

int				ft_check_patern(char **tab, int i);
int				ft_check_pa1(char **tab);
int				ft_check_2pa1(char **tab);
int				ft_check_pa2(char **tab);
int				ft_check_2pa2(char **tab);
int				ft_check_pa3(char **tab);
int				ft_check_2pa3(char **tab);
int				ft_check_pa4_5(char **tab);
int				ft_check_2pa4_5(char **tab);
int				ft_check_pa6_7(char **tab);
int				check_error(char **file);
int				check_line(char **line);
char			***parse_file(int fd, int *c_blocks);
void			ft_changetoletter(char **files);
int				ft_check_all(char **tab);
char			*call_all(int n);
int				check_space(char *shape, char **grid,
		t_tetri *tetri, t_compt *comp);
void			clear_piece(char **grid, char *shape,
		t_compt *comp, t_tetri *tetri);
int				ft_putable(char **grid, char ***file,
		t_compt *comp, t_tetri *tetri);
int				resolve_algo(char ***file, char **grid,
		t_tetri *tetri, int block);
void			init_coords(t_tetri *tetri);
void			reset_coords(t_tetri *tetri);
int				calc_size(int n);
int				res_algo(char ***file, int c_blocks);
char			**init_grid(int size);
void			print_grid(char **grid);
char			*get_piece(char ***file, int block);
int				ft_put(char **grid, char *shape,
		t_tetri *tetri, t_compt *comp);

# define BUFF_SIZE 21

# define P1 "###\n..#"
# define P2 ".#\n.#\n##"
# define P3 "#..\n###"
# define P4 "##\n#.\n#."
# define P5 "###\n.#."
# define P6  ".#\n##\n.#"
# define P7 ".#.\n###"
# define P8 "#.\n##\n#."
# define P9 "###\n#.."
# define P10 "##\n.#\n.#"
# define P11 "..#\n###"
# define P12 "#.\n#.\n##"
# define P13 ".##\n##."
# define P14 "#.\n##\n.#"
# define P15 "##.\n.##"
# define P16 ".#\n##\n#."
# define P17 "####"
# define P18 "#\n#\n#\n#"
# define P19 "##\n##"

#endif
