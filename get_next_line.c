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

int		get_next_line(const int fd, char **line)
{
	static	t_gnl *lst;
	int res;
	int len1;
	int len2;
	int buf_len;
	char *tmp;

	res = 0;
	len1 = 0;
	len2 = 0;
	buf_len = 0;
	if (!lst)
	{
		lst = (t_gnl *)malloc(sizeof(t_gnl));
		lst->fd = fd;
		lst->buf = ft_strdup("");
		lst->str = ft_strdup("");
	}
	if (fd < 0 || !lst || BUFF_SIZE == 0 || !line)
		return (-1);
	//printf("buf: |%s|\n", lst->buf);
	while (!(ft_memchr(lst->str, '\n', BUFF_SIZE)) && (res = read(lst->fd, lst->buf, BUFF_SIZE)))
	{
		if (res == -1)
			return (-1);
		lst->buf[res] = '\0';
		//printf("buf: |%s|\n", lst->buf);
		lst->str = ft_strjoin(lst->str, lst->buf);
		//printf("str: |%s|\n", lst->str);
	}
	buf_len = ft_strlen(lst->str);
	len1 = ft_len(lst->str);
	*line = ft_strsub(lst->str, 0, len1);
	//printf("bufLEN:%d\n", buf_len);
	len1 = ft_strlen(lst->str);
	len2 = ft_strlen(*line);
	//tmp = ft_strnew(len1 - len2);
	tmp = ft_strsub(lst->str, len2 + 1, len1 - len2);
	len1 = ft_strlen(tmp);
	//printf("tmp: %d\n", len1);
	lst->str = ft_strdup(tmp);
	//printf("str2: |%s|\n", lst->str);
	//printf("line: |%s|\n", *line);
	if (res == 0 && buf_len > 0)
	{
		return (1);
	}
	if (res == 0 && buf_len == 0)
		return (0);
	if (line)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int fd;

	fd = 0;
	fd = open(argv[1], O_RDONLY);
	char *line;
	int a = 0;

	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// get_next_line(fd, &line);



	a = get_next_line(fd, &line);
	printf("|%d|\n", a);
	a = get_next_line(fd, &line);
	printf("|%d|\n", a);
	a = get_next_line(fd, &line);
	printf("|%d|\n", a);
	a = get_next_line(fd, &line);
	printf("|%d|\n", a);
	a = get_next_line(fd, &line);
	printf("|%d|\n", a);
	a = get_next_line(fd, &line);
	printf("|%d|\n", a);
	a = get_next_line(fd, &line);
	printf("|%d|\n", a);



	close (fd);
	return (0);
}
