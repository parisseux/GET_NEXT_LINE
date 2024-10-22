/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:32:30 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/22 10:54:39 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;
	int		len;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = j + i;
	s3 = (char *)malloc((i + j + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	k = 0;
	while (k < i)
	{
		s3[k] = s1[k];
		k++;
	}
	j = 0;
	while (k < len)
		s3[k++] = s2[j++];
	s3[k] = '\0';
	return (s3);
}

int main()
{
    char *s = ft_strjoin("salut", "Ca va");
	printf("%s", s);
	free(s);
    return (0);
}


char	*fill_use_buffer(int fd, int i, char *new_line)
{
	char		*buffer;
	char		*temp;
	static char	*trash;

	if (trash)
	{
		temp = ft_strdup(trash, 0, ft_strlen(trash));
		free(trash);
	}	
	while (i > 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (!temp)
			return (NULL);
		if (check_temp(temp) > 0)
		{
			new_line =  get_newline(temp, new_line, check_temp(temp));
			trash = get_trash(temp, trash, check_temp(temp));
			free(temp);
			return (new_line);
		}
		if (i == 0)
			new_line = ft_lastline(new_line, temp);
	}
	
	return (new_line);
}