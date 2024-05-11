#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

/* char    *get_next_line(int fd)
{
    size_t count;
    char *buffer;

    read(fd, buffer, count);

} */

int main(void)
{
	char	buf[BUFFER_SIZE];	// stores the characters read
	int	fd;		// file descriptor to read
	int	nb_read;	// stores read's return value
	int	count;		// counts the number of reads
	int	newlinebool;
	int	i = 0;

	newlinebool = 0;
	fd = open("41_no_nl", O_RDONLY);
	if (fd == -1)
		return (1);
	nb_read = read(fd, buf, BUFFER_SIZE);
	while(buf[count] != '\n' && count < BUFFER_SIZE)
	{
		count++;
		if (buf[count + 1] == '\n')
			newlinebool = 1;
	}
	if(newlinebool == 1)
	{
		while(i < count)
		{
			printf("%c", buf[i]);
			i++;
		}
	}
	else
		printf("%s", buf);
//	Close the opened file descriptor
	close(fd);
	return (0);
}