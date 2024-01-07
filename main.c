#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd = open("./bla.txt", O_RDONLY);

	char *str = get_next_line(fd);
	printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	free(str);
	close(fd);
}
