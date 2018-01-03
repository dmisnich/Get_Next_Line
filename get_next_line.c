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
	static	char *str;
	char buf[BUF_SIZE + 1];
	int res;
	int len;
	int flag;
	int i = 0;

	res = 0;
	len = 0;
	flag = 0;
	str = (char *)malloc(sizeof(char) * 1);
	if (fd < 0 || !str || BUF_SIZE == 0 || !line)
		return (-1);
	while ((res = read(fd, buf, BUF_SIZE)))
	{
		//printf("buf: %s\n", buf);
		printf("res: %d\n", res);
		if ((ft_memchr(buf, '\n', BUF_SIZE)))
		{
			flag = 1;
			break ;
		}
		if (res == -1)
			return (-1);
		buf[res] = '\0';
		str = ft_strjoin(str, buf);
		printf("str: %s\n", str);
	}
	if (flag == 1)
	{
		//len = ft_len(str);
		while (buf[i] != '\n')
		{
			str[i] = buf[i];
			i++;
		}

		//str = ft_strjoin(str, buf);
		printf("str2: %s\n", str);
	}
	// printf("str: %s\n", str);
	len = ft_strlen(str);
	*line = ft_strsub(str, 0, len);
	printf("line: | %s |\n", *line);
	return (0);
}

int main(int argc, char **argv)
{
	int fd;
	//int bytes;   b
	//char *buf;

	fd = 0;
	fd = open(argv[1], O_RDONLY);
	char *line;
	get_next_line(fd, &line);
	return (0);
}
