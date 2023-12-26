#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd = open("./bla.txt", O_RDONLY);
	int a = open("./yu.txt", O_RDONLY);

	char *str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(a);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(a);
	close(fd);
}
