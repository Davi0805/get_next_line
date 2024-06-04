#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* static char *trims(char *result)
{
	char *temp;
	ssize_t i;

	i = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
	if (result[i] == '\0' || result[1] == '\0')
		return (NULL);
	temp = ft_substr(result, i + 1, ft_strlen(result) - i);
	if (*temp == '\0')
	{
		free(temp);
		return (NULL);
	}
	result[i + 1] = '\0';
	return (temp);
}  */

/* static char	*trims(char **temp)
{
	char	*line;
	char	*ptr;
	unsigned int i;

	i = 0;
	ptr = *temp;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')

	line = ft_substr (*temp, 0, ft_strlen(*temp) - i);
	if (!line)
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr (ptr, i, ft_strlen (ptr));
	free (*temp);
	*temp = ptr;
	return (line);
} */

char	*mallockiller(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s2 = NULL;
	return (0);
}

char	*read_the_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr (str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_string(char *str)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (free(str), NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	new_str = ft_substr (str, i, ft_strlen(str) - i);
	free(str);
	if (!new_str[0])
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}

/* char	*trims(char *temp)
{
	int		n_pos;
	char	*return_line;
	
	n_pos = 0;
	if (!temp || temp[0] == '\0')
		return (NULL);
	while (temp[n_pos] && temp[n_pos] != 10)
		n_pos++;
	if (temp[n_pos] == 10)
		n_pos++;
	return_line = ft_substr(temp, 0, n_pos);
	if (!return_line)
		return (NULL);
	temp = ft_substr(temp, n_pos, ft_strlen(temp) - n_pos);
	if (!temp[0])
		return (free(temp), NULL);
	return (return_line);
} */

/* char *buffercollect(int fd, char *result, char *buffer)
{
	int	nb_count;

	nb_count = 1;
	while (nb_count != 0 && !(ft_strchr(result, '\n')))
	{
		nb_count = read(fd, buffer, BUFFER_SIZE);
		if (nb_count == -1)
		{
			free(result);
			free(buffer);
			result = NULL;
			return (0);
		}
		buffer[nb_count] = '\0';
		result = ft_strjoin(result, buffer);
	}
	return (result);
}  */

char *get_next_line(int fd)
{
	static char *result;
	char 		*buffer;
	int			nb_count;

	nb_count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
 	while(nb_count != 0 && !(ft_strchr(result, '\n')))
	{
		nb_count = read(fd, buffer, BUFFER_SIZE);
		if (nb_count == -1)
		{
			result = mallockiller(buffer, result);
			return (NULL);
		}
		buffer[nb_count] = '\0';
		result = ft_strjoin(result, buffer);
	}
	free(buffer);
	buffer = read_the_line(result);
	result = get_string(result);
	return (buffer);
} 

/* char	*free_and_null(char *buff1, char *buff2)
{
	free(buff1);
	free(buff2);
	buff2 = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*read_buffer;
	char		*read_content;
	int			read_bytes;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_content)
		return (NULL);
	while (!(ft_strchr(read_buffer, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, read_content, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			read_buffer = free_and_null(read_content, read_buffer);
			return (NULL);
		}
		read_content[read_bytes] = '\0';
		read_buffer = ft_strjoin(read_buffer, read_content);
	}
	free(read_content);
	read_content = read_the_line(read_buffer);
	read_buffer = get_string(read_buffer);
	return (read_content);
} */