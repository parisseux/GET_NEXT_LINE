/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:37:29 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/21 18:28:47 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

# include <stdio.h>
# include <stdlib.h>

char *get_next_line(int fd);
char	*ft_strjoin(char  *temp, char *buff);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1, int debut, int fin);
char	*fill_use_buffer(int fd, int i, char *new_line);
char	*get_trash(char *temp, char *trash, int i);
char *get_newline(char *temp, char *new_line, int i);

#endif
#endif