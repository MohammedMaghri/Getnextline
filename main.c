#include "nextline.h"
#include <fcntl.h> 
#include <stdio.h>

int main()
{
	int fd = 0;
	char *string ;
	char *thestring;
	fd = open("test.txt", O_RDONLY);

	printf("%s" , merge(fd));
	printf("%s" , merge(fd));
	printf("%s" , merge(fd));
	
}
