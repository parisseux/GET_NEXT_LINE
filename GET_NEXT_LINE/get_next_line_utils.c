/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:41:49 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/23 14:10:22 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *temp, char *buff)
{
	char	*s;

	if (!temp)
	{
		temp = (char *)malloc(1);
		if (!temp)
			return (NULL);
		temp[0] = '\0';
	}
	if (!buff)
		return (NULL);
	s = (char *)malloc((ft_strlen(temp) + ft_strlen(buff) + 1) * sizeof(char));
	if (!s)
	{
		free(temp);
		return (NULL);
	}
	s = ft_strjoin2(s, temp, buff);
	return (s);
}

char	*ft_strjoin2(char *s, char *temp, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i])
	{
		s[i] = temp[i];
		i++;
	}
	while (buff[j])
		s[i++] = buff[j++];
	s[i] = '\0';
	free(temp);
	return (s);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
