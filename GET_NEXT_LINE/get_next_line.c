/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:39:56 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/23 11:16:13 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_trash(char *temp)
{
	char	*trash;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	trash = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!trash)
		return (NULL);
	i++;
	while (temp[i])
		trash[j++] = temp[i++];
	trash[j] = '\0';
	free(temp);
	return (trash);
}

char	*fill_use_buffer(int fd, char *temp)
{
	char		*buffer;
	int			i;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (i == 0)
			break ;
		buffer[i] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(temp))
			break ;
	}
	free(buffer);
	return (temp);
}

char	*get_newline(char *temp)
{
	char	*new_line;
	int		j;
	int		i;

	if (*temp == '\0')
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		new_line = (char *)malloc(sizeof(char) * (i + 2));
	else
		new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_line[j] = temp[j];
		j++;
	}
	if (temp[i] == '\n')
	{
		new_line[j] = '\n';
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = fill_use_buffer(fd, temp);
	if (!temp)
		return (NULL);
	new_line = get_newline(temp);
	temp = get_trash(temp);
	// if (!new_line)
	// {
	// 	free(temp);
	// 	return (NULL);
	// }
	return (new_line);
}
// #include <fcntl.h>
// int main()
// {
// 	FILE* fptr = fopen("test_files.txt", "w");
// 	fprintf(fptr, "Salut ma petite puce\nJe m'appelle Parissa\nJ'ai 24 ans\nJe suis à l'école 42 :)");
// 	fclose(fptr);
// 	fptr = fopen("test_files.txt", "r");
// 	int fd = fileno(fptr);
// 	char *line;
// 	 while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line); 
//         free(line);  
//     }
// 	fclose(fptr);
// 	return (0);
// }