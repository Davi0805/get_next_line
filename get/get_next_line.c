#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

 static char *trims(char *result)
{
	char *temp;
	ssize_t i;

/* 	if (!result)
		return (NULL); */
	i = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
	if (result[i] == '\0' || result[1] == '\0')
		return (NULL);
	temp = ft_substr(result, i + 1, ft_strlen(result) - i);
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
	}
	result[i + 1] = '\0';
	//temp[i + 1] = '\0';
	/* if (result[i] == '\n')
		result[i + 1] = '\0'; */
	//printf("Trims - temp= %s\n", temp);
	return (temp);
} 

static char *buffercollect(int fd, char *result, char *buffer)
{
	ssize_t		nb_read;
	char 		*temp;

	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		else if (nb_read == 0)
		{
			break ;
		}
		buffer[nb_read] = '\0';
		if (!result)
			result = ft_strdup("");
		temp = result;
		result = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
		{
			break ;
		}
	}
	free(buffer);
	//printf("Buffercollect - Result = %s\n", result);
	//printf("Buffercollect - Temp = %s\n", temp);
	return (result);
}

char *get_next_line(int fd)
{
	static char *result;
	char *buffer;
	char *temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(result);
		result = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	temp = buffercollect(fd, result, buffer);
	if (!temp)
	{
		return (NULL);
	}
	result = trims(temp);
	if (!result)
		free(result);
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