#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i;
	char *test_string = "%d %d\n";
	printf(test_string, 1);
	for(i = 0; test_string[i] != '\0'; i++)
		write(1, &test_string[i], 1);
	return(0);
}
