#include <fcntl.h>
#include "get_next_line.h"

static char *fillline(int fd, char *result, char *buffer)
{
	int		nb_read;
	char 		*temp;

	nb_read = 1;
	temp = NULL;
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			//free(result);
			return (NULL);
		}
		else if (nb_read == 0)
			break ;
		buffer[nb_read] = '\0';
		temp = result;
		result = ft_strjoin(temp, buffer);
		if (temp != buffer)
			free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (result);
}
char *trims(char *result)
{
	char *temp;
	int i;

	if (!result)
		return (NULL);
	temp = NULL;
	i = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
/* 	if (result[i] == '\0')
        return (NULL); */
	if (result[i] == '\n')
	{
		result[i + 1] = '\0';
		temp = ft_strdup(result);
		result[i + 1] = '\n';
		free(result);
	}
	else
	{
		return result;
	}
	return (temp);
}
char *get_next_line(int fd)
{
	static char *result = NULL;
	char *buffer;
	char *temp;
	char *newline_pos;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	if (!result)
		result = ft_strdup("");
	temp = fillline(fd, result, buffer);
	if (result != buffer)
		free(buffer);
	newline_pos = ft_strchr(temp, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		result = ft_strdup(newline_pos + 1);
	}
	else
	{
		result = NULL;
	}
	return (temp);
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
	temp = fillline(fd, result, buffer);
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