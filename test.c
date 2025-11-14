#include <stdio.h>

int main(void)
{
	int a = 5;
	int *p = &a;
	printf("%d-%lx-%p\n%d-%lx-%p\n", a, &a, &a, *p, p, p);
	return(0);
}
