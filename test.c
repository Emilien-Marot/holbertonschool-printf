#include <stdio.h>

int main(void)
{
	int i;
	char *test_string = "%d\n";
	printf(test_string, 1);
	for(i = 0; test_string[i] != '\0'; i++)
		putchar(test_string[i]);
	return(0);
}
