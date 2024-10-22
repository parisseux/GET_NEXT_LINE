# include "get_next_line.h"

int	check_temp(char *temp)
{
	int i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *ft_lastline(char *new_line, char *temp)
{
	int i;
	
	i = 0;
	while (temp[i])
	{
		new_line = (char *)malloc(sizeof(char) * (ft_strlen(temp) + 1));
		new_line[i] = temp[i];
		i++;
	}
	new_line[i] = '\0';
	free(temp);
	return (new_line);
}
// char	*fill_use_buffer(int fd, int i, char *new_line)
// {
// 	char		*buffer;
// 	static char		*temp;
// 	char	*trash;

// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	buffer[BUFFER_SIZE] = '\0';
// 	while (i > )
// 	{
// 		i = read(fd, buffer, BUFFER_SIZE);
// 		temp = ft_strjoin(temp, buffer);
// 		if (i == -1 || ( i == 0 && *temp == '\0'))
// 			return (NULL);
// 		free(buffer);
// 		if (!temp)
// 			return (NULL);
// 	}
// 	if (check_temp(temp) > 0)
// 	{
// 		new_line =  get_newline(temp, new_line, check_temp(temp));
// 		trash = get_trash(temp, trash, check_temp(temp));
// 		free(temp);
// 		i = -1;
// 	}
	
// 	if (i == -1 || ( i == 0 && *temp == '\0'))
// 		return (NULL);
// 	if (trash)
// 	{
// 		temp = ft_strdup(trash, 0, ft_strlen(trash));
// 		free(trash);
// 	}	
// 	return (new_line);
// }

char	*fill_use_buffer(int fd, int i, char *new_line)
{
	char		*buffer;
	static char		*temp;
	char	*trash;

	// if (trash)
	// {
	// 	temp = ft_strdup(trash, 0, ft_strlen(trash));
	// 	free(trash);
	// }	
	while (i == BUFFER_SIZE)
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
		if (check_temp(temp) >= 0)
		{
			new_line =  get_newline(temp, new_line, check_temp(temp));
			trash = get_trash(temp, trash, check_temp(temp));
			free(temp);
			i = -1;
		}
		if (i < BUFFER_SIZE && i > -1 && temp[0] != '\0')
		{
			new_line = ft_lastline(new_line, temp);
			free(temp);
		}
	}
	if (trash)
	{
		temp = ft_strdup(trash, 0, ft_strlen(trash));
		free(trash);
	}	
	return (new_line);
}
char	*get_next_line(int fd)
{
	char	*new_line;
	int i;

	i = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = fill_use_buffer(fd, i, new_line);
	if (!new_line)
		return (NULL);
	return (new_line);
}

int main()
{
	FILE* fptr = fopen("test_files.txt", "w");
	fprintf(fptr, "Salut ma petite puce\nJe m'appelle Parissa\nJ'ai 24 ans\nJe suis à l'école 42 :)");
	fclose(fptr);
	fptr = fopen("test_files.txt", "r");
	int fd = fileno(fptr);
	char *line;
	 while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); 
        free(line);  
    }
	fclose(fptr);
	return (0);
}