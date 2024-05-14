#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	char *temp;

	fd = open("empty", O_RDONLY);
	temp = get_next_line(fd);
 	printf("%s", temp);
	temp = get_next_line(fd);
 	printf("%s", temp);
	temp = get_next_line(fd);
 	printf("%s", temp);
/*	printf("%s", get_next_line(fd)); */
	close(fd);
	return (0);
}