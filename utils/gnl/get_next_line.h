/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:24:08 by ioztimur          #+#    #+#             */
/*   Updated: 2023/03/20 15:22:24 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_get_line(char *left_str);
char	*ft_next_line(char	*left_str);
char	*ft_read_left(int fd, char *left_str);
char	*ft_error_check(char *left_str, char *buffer);

#endif
