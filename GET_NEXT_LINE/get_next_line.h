/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:37:29 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/23 14:21:25 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_trash(char *temp);
char	*fill_use_buffer(int fd, char *temp, int i, char *buffer);
char	*get_newline(char *temp);
char	*get_next_line(int fd);
int		ft_strchr(char *s);
char	*ft_strjoin(char *temp, char *buff);
int		ft_strlen(char *str);
char	*ft_strjoin2(char *s, char *temp, char *buff);

#endif