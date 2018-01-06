/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:11:35 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/03 11:11:37 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		search_and_read(t_gnl *lst, char **line)
{
	char	*buf;
	ssize_t	ret;
	char	*tmp;

	buf = (char *)malloc(BUFF_SIZE + 1);
	while ((ret = read(lst->fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = lst->str;
		lst->str = ft_strjoin(lst->str, buf);
		if (tmp)
			free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (!ret && !ft_strlen(lst->str))
		return (0);
	tmp = *line;
	*line = ft_strsub(lst->str, 0, ft_len(lst->str));
	if (tmp)
		free(tmp);
	tmp = lst->str;
	lst->str = ft_strsub(lst->str, ft_len(lst->str) + 1,
		ft_strlen(lst->str) - ft_strlen(*line));
	if (tmp)
		free(tmp);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!lst)
	{
		lst = (t_gnl *)malloc(sizeof(t_gnl));
		lst->fd = fd;
		lst->str = ft_memalloc(1);
	}
	return (search_and_read(lst, line));
}


// int main(int argc, char **argv)
// {
// 	int fd;

// 	fd = 50;
// 	//fd = open(argv[1], O_RDONLY);
// 	char *line;
// 	int a = 0;

// 	// while (get_next_line(fd, &line) == 1)
// 	// {
// 	// 	printf("|%d|\n", a++);
// 	// }
// 	a = get_next_line(fd, &line);
// 	// printf("sdcsd %d\n", strcmp(line, "aaa"));
// 	printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);

// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);
// 	// a = get_next_line(fd, &line);
// 	// printf("|%d|\n", a);



// 	close (fd);
// 	return (0);
// }
