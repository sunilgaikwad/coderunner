#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// your code goes here
	int *p = (int *)malloc(sizeof(int));
	*p = 0x8F7E1A2B;
	printf("%X\n", *p);

	unsigned char *q = p;
	printf("%X\n", *q++); // 2B !!
	printf("%X\n", *q++); // 1A !!

	return 0;
}
