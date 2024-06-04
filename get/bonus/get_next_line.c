/* #include <fcntl.h>
#include <stdio.h> */
#include "get_next_line.h"

/*  static char *trims(char *result)
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

char	*trims(char **temp)
{
	int		n_pos;
	char	*return_line;
	char	*str;

	if (!*temp)
		return (NULL);
	str = *temp;
	n_pos = 0;
	while (str[n_pos] && str[n_pos] != 10)
		n_pos++;
	if (str[n_pos] == 10)
		n_pos++;
	return_line = ft_substr(str, 0, n_pos);
	*temp = ft_substr(str + n_pos, 0, ft_strlen(str + n_pos));
	if (str)
		free(str);
	str = NULL;
	return (return_line);
}

static char *buffercollect(int fd, char *result, char *buffer)
{
	ssize_t		nb_count;

	nb_count = 1;
	while (nb_count && !ft_strchr(result, '\n'))
	{
		nb_count = read(fd, buffer, BUFFER_SIZE);
		if (nb_count == -1)
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		else if (nb_count == 0)
			break ;
		buffer[nb_count] = '\0';
		result = ft_strjoin(result, buffer);
		if (!result)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (result);
}

char *get_next_line(int fd)
{
	static char *result[1024];
	char *buffer;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!result[fd])
		result[fd] = ft_strdup("");
	if (!result[fd])
		return(NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(result[fd]);
		return (NULL);
	}
	result[fd] = buffercollect(fd, result[fd], buffer);
	if (!result[fd])
		return (NULL);
	if (!*result[fd])
	{
		free(result[fd]);
		result[fd] = NULL;
		return (NULL);
	}
	return (trims(&result[fd]));
}
/* char    *get_next_line(int fd)
{
	static char *result;
	char 		*buffer;
	char		*temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	temp = buffercollect(fd, result, buffer);
	if (result != buffer)
		free(buffer);
	result = trims(temp);
	//printf("result: %s", result);
	return (result);
} */



/* int	main(void)
{
	int fd;

	fd = open("alternate_line_nl_no_nl", O_RDONLY);
	get_next_line(fd);
	close(fd);
	return (0);
} */

/* int main(void)
{
	char	buf[BUFFER_SIZE];	// stores the characters read
	int		fd;					// file descriptor to read
	int		nb_read;			// stores read's return value
	int		count;				// counts the number of reads
	int		newlinebool;
	int		i = 0;

	newlinebool = 0;
	fd = open("41_no_nl", O_RDONLY);
	if (fd == -1)
		return (1);
	nb_read = read(fd, buf, BUFFER_SIZE);
	printf("1: %s\n", buf);
	nb_read = read(fd, buf, BUFFER_SIZE);
	printf("2: %s\n", buf);
	nb_read = read(fd, buf, BUFFER_SIZE);
	printf("3: %s\n", buf);
	close(fd);
	return (0);
} */