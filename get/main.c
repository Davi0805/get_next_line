#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	char *temp;

	fd = open("41_with_nl", O_RDONLY);
	temp = get_next_line(fd);
 	printf("Resposta [1] = %s\n", temp);
	temp = get_next_line(fd);
 	printf("Resposta [2] = %s\n", temp);
/*	printf("%s", get_next_line(fd)); */
	close(fd);
	return (0);
}