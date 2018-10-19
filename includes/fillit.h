/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thbrouss <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 13:11:53 by thbrouss     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 18:29:56 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int		ft_check_patern(char *tab, int i);
int		ft_check_pa1(char **tab);
int		ft_check_pa2(char **tab);
int		ft_check_pa3(char **tab);
int		ft_check_pa4_5(char **tab);
int		ft_check_pa6_7(char **tab);
int		check_len(char *file);
int		check_next_to(char *file);
int		check_error(char *file, char n_line);
int		parse_file(int fd, char **files, int *c_blocks);

# define LINE_L 0
# define HASH_N 1
# define BUFF_SIZE 21

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
