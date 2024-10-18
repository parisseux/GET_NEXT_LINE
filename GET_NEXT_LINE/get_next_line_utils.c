/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:41:49 by pchatagn          #+#    #+#             */
/*   Updated: 2024/10/18 12:01:08 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

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
