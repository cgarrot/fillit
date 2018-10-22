/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 19:42:18 by thbrouss     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/10/22 17:34:59 by thbrouss    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/10/22 16:41:06 by cgarrot     ###    #+. /#+    ###.fr     */
>>>>>>> c74152cbf40847200fc6dbaf98347e2c6fecd39c
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>


// store les coordonnees du tetri [4 extremitees].... map[t_extre + new_cords] et check sur quel extrimites on peut poser le tris.

typedef struct s_tetri
{
	int curr_pos[4];
}	t_tetri;

int		ft_check_patern(char **tab, int i);
int		ft_check_pa1(char **tab);
int		ft_check_pa2(char **tab);
int		ft_check_pa3(char **tab);
int		ft_check_pa4_5(char **tab);
int		ft_check_pa6_7(char **tab);
int		check_len(char *file);
int		check_next_to(char *file);
int		check_error(char *file, char n_line);
char	***parse_file(int fd, int *c_blocks);
void	ft_putstr2d(char **tab);
char	**ft_memalloc2d(int size, int len);
int		**ft_index(char *tab);
char	*ft_search_and_replace(char *src, char c);
char	*ft_search_string(int i);
char	**ft_input_letter(int bloc, int **index);
int		ft_strncmp2(const char *s1, const char *s2, size_t n);
char	**ft_changetoletter(char **files);
char	**ft_setgrid(int blocks);
int		ft_sqrt(int nb);
char	**ft_reduct(char **files);
int		ft_check_all(char **tab);
int		res_algo(char **file, int c_blocks);
char	**tab2d(char **files, int blocks);
int		ft_new_line(char **s, char **line, int fd, int ret);
int		get_next_line(const int fd, char **line);


# define LINE_L 0
# define HASH_N 1
# define BUFF_SIZE 26

# define P1 1
# define P1_DISP "###\n..#"
# define P2 2
# define P2_DISP ".#\n.#\n##"
# define P3 3
# define P3_DISP "#..\n###"
# define P4 4
# define P4_DISP "##\n#.\n#."
# define P5 5
# define P5_DISP "###\n.#."
# define P6 6
# define P6_DISP ".#\n##\n.#"
# define P7 7
# define P7_DISP ".#.\n###"
# define P8 8
# define P8_DISP "#.\n##\n#."
# define P9 9
# define P9_DISP "###\n#.."
# define P10 10
# define P10_DISP "##\n.#\n.#"
# define P11 11
# define P11_DISP "..#\n###"
# define P12 12
# define P12_DISP "#.\n#.\n##"
# define P13 13
# define P13_DISP ".##\n##."
# define P14 14
# define P14_DISP "#.\n##\n.#"
# define P15 15
# define P15_DISP "##.\n.##"
# define P16 16
# define P16_DISP ".#\n##\n#."
# define P17 17
# define P17_DISP "####"
# define P18 18
# define P18_DISP "#\n#\n#\n#"
# define P19 19
# define P19_DISP "##\n##"

#endif
