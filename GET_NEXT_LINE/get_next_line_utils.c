/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:41:49 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/21 17:33:29 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_strjoin(char  *temp, char  *buff)
{
	char	*s;
	size_t		i;
	size_t		j;
	
	if (!temp)
	{
		temp = (char *)malloc(1 *sizeof(char));
		temp[0] = '\0';
	}
	if (!temp || !buff)
		return (NULL);
	s = (char *)malloc((ft_strlen(temp) + ft_strlen(buff) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		s[i] = temp[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		s[i] = buff[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1, int debut, int fin)
{
	char	*ptr;
    int i;
    int len;

	len = fin - debut;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[debut];
		i++;
        debut++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char *get_newline(char *temp, char *new_line, int i)
{

	new_line = ft_strdup(temp, 0, i + 1);
	if (!new_line)
		return (NULL);
	return (new_line);
		
}
char	*get_trash(char *temp, char *trash, int i)
{
	trash = ft_strdup(temp, i + 1, ft_strlen(temp));
	if (!trash)
		return (NULL);
	return (trash);
}