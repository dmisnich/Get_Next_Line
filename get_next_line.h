/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:12:11 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/03 11:12:13 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1000

typedef struct 	s_gnl
{
	int fd;
	//char *buf;
	char *str;
	struct s_gnl *next;
	//struct s_gnl *prev;
}				t_gnl;

# include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
