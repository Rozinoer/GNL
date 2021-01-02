#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main() {
    int		fd;
    char 	*line;
    int i=  0;
    int j = 0;

	fd = open("/Users/evgenii/Desktop/CLion/GNL/42TESTERS-GNL/files/empty_lines", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 9)
		printf("\nRight number of lines\n");
	else
		printf("\nNot Good - Wrong Number Of Lines-[%d]\n",j);
//	printf("[fd = %d][%d]:line = ^%s^\n",j,i, line);
//	printf("%d\n", i);
		return 0;
}
