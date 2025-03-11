//valgrind --tool=memcheck program_name
//Missing free
#include <stdlib.h>
int main()
{
    char *x = malloc(100);
    return 0;
}
