/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:37:48 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/18 12:12:31 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char *write_newline(char *temp, char *new_line, char *trash)
{
	int i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			new_line = ft_strdup(temp, 0, i);
			trash = ft_strdup(temp, i+1, ft_strlen(temp) - 1);
		}
		i++;
	}
	if (!new_line)
		return (new_line);
	// else
	// 	return (ft_strdup("petit chat", 0, 10));
		
}

char	*fill_use_buffer(int fd)
{
	int i;
	char *buffer;
	char *temp;
	char *new_line;
	static char *trash;
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i == 0 || i == -1)
		return (NULL);
	temp = ft_strjoin(buffer, temp);
	if (!temp)
		return (NULL);
	new_line = write_newline(temp, new_line, trash);
	
}

char	*get_next_line(int fd)
{
	char	*new_line;
	size_t	n_byte;

	if (fd < 0)
		return (NULL);
	new_line = fill_use_buffer(fd);
	return (new_line);
}