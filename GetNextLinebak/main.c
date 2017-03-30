#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	int fd;
	int fd2;
	char *next;
	int i;
	int j;

	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	if (fd == -1)
	{
		printf("erreur a l'overture");
		return (1);
	}
	i = 1;
	j = 1;
	while (j < 20)
	{
		i = get_next_line(fd, &next);
		printf("i : %d, %de iteration : ", i, j);
		printf("?%s?\n", next);
		i = get_next_line(fd2, &next);
		printf("i : %d, %de iteration : ", i, j);
		printf("?%s?\n", next);
		j++;
	}
	i = get_next_line(50, &next);
	printf("i : %d, %de iteration : ", i, j);
	if (close(fd) == -1)
	{
		printf("erreur a la fermeture");
		return (2);
	}
	return (0);
}
