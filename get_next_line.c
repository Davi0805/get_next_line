#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 5

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

//	Open the cat.txt file in read only mode
	fd = open("41_no_nl", O_RDONLY);
	if (fd == -1)
		return (1);
//	Initialize the count variables
	nb_read = -1;
	count = 0;
//	Loop as long as read does not return 0 (which would mean that
//	there is nothing more to read in the file)
	while (nb_read != 0)
	{
		// Read 100 characters with read from the
		// opened file descriptor
		nb_read = read(fd, buf, BUFFER_SIZE);
		// Stop everything if read encounters an error
		if (nb_read == -1)
		{
			printf("Read error!\n");
			return (1);
		}
		// Read does not add the terminating \0
		// We can use the number of read characters as the index
		// of the last character in the string
		buf[nb_read] = '\0';
		// Print the buffer contents after read
		printf("%s", buf);
		count++;
	}
//	Close the opened file descriptor
	close(fd);
	return (0);
}