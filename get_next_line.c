#include "./includes/libft.h"
#include "./includes/fillit.h"

int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}

char	**parse_v2(int fd, char *files)
{
	char	**test;
	int		i;

	i = 0;
	if (!(test = (char**)malloc(sizeof(char*) * 26)))
		return (0);
	while ()
	{
		if (i % 5 == 0)
		{
			if (!(test[i] = (char*)malloc(sizeof(char) * 2)))
				return (0);
			i++;
		}
		if (!(test[i] = (char*)malloc(sizeof(char) * 5)))
			return (0);
		i++;
	}
	while (get_next_line(fd, &files) > 0)
	{

		free(files);
	}

}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*files;
	int		blocks;

	i = 0;
	blocks = 0;
	files = NULL;
	if (ac != 2)
		return (0);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (!(files = parse_v2(fd, files)))
			return (0);
		/*while (files[i])
		{
			ft_putstr(files[i]);
			ft_putchar('\n')
			i++;
		}*/
	}
	return (0);
}
