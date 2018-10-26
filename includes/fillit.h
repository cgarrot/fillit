/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:59:30 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 22:02:38 by thbrouss    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct	s_tetri
{
	int	c_blocks;
	int size;
	int curr_x;
	int curr_y;
}	t_tetri;

typedef struct	s_compt
{
	int		i;
	int		j;
	int		k;
	int		i_b;
	int		j_b;
}				t_compt;

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
void			ft_putstr2d(char **tab);
char			**ft_memalloc2d(int size, int len);
int				**ft_index(char *tab);
char			*ft_search_and_replace(char *src, char c);
char			*ft_search_string(int i);
char			**ft_input_letter(int bloc, int **index);
int				ft_strncmp2(const char *s1, const char *s2, size_t n);
char			**ft_changetoletter(char **files);
char			**ft_setgrid(int blocks);
int				ft_sqrt(int nb);
char			**ft_reduct(char **files);
int				ft_check_all(char **tab);
int				res_algo(char ***file, int c_blocks);
char			**tab2d(char **files, int blocks);
int				ft_new_line(char **s, char **line, int fd, int ret);
int				get_next_line(const int fd, char **line);
char			*call_all(int n);

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

# define CLEAR 1
# define PUT 2
# define CHECK 3

#endif
