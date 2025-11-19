#include <stdio.h>
#include <cstdlib>
#include <unistd.h>

void test(char *s, int *i)
{
	*i = *i + 1;
	*(s + 1) = 'x';
}

int main(void)
{
	char s[1024];
	s[0] = 'a';
	*(s+1) = 'b';
	s[2] = 'c';
	s[3] = '\0';
	int i = 20;
	test(s, &i);
	write(1,s,3);
	printf("%s%d\n", s, i);
	return(0);
}
