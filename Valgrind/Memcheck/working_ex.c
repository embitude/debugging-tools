//valgrind --tool=memcheck program_name
#include <stdlib.h>
int main()
{
    char *x = malloc(100);
	free(x);
    return 0;
}
