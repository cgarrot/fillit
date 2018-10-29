/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 13:00:29 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 15:59:59 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct		s_tetri
{
	int		c_blocks;
	int		size;
	int		curr_x;
	int		curr_y;
	int		tmp_x;
	char	c;
	int		tmp_y;
	int		i_pos;
	int		type;
	int		c_place;
	int		curr_block;
}					t_tetri;

typedef struct		s_shape
{
	int		pos_x[4];
	int		pos_y[4];
	char	*pattern;
}					t_shape;

typedef struct		s_compt
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
}					t_compt;

int					check_error(char **file);
int					check_line(char **line);
char				***parse_file(int fd, int *c_blocks, char ***files);
void				ft_changetoletter(char **files);
int					ft_check_all(char **tab);
char				*call_all(int n);
int					check_space(char *shape, char **grid,
		t_tetri *tetri);
void				clear_piece(char **grid, char *shape, t_tetri *tetri);
int					is_putable(char **grid,
		t_tetri *tetri, t_shape **shape);
int					search_algo(char **grid,
		t_tetri *tetri, int block, t_shape **shape);
int					res_algo(int block, t_shape **shape);
char				**init_grid(int size);
void				print_grid(char **grid);
void				set_info(t_tetri *tetri, int i, int j, int block);
t_shape				**store_pattern(char ***files);
char				*get_piece(char ***file, int block);
void				set_pos(t_tetri *tetri, char **grid,
		t_shape **shape, char c);
void				to_letter(char **grid, t_tetri *tetri, t_shape **shape);
int					ft_put(char **grid, char *shape, t_tetri *tetri);
int					get_checker(char **tab);

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

enum	e_type{CLEAR = 1, PUT = 2, CHECK = 3};

#endif
