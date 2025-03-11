#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct foo {
    unsigned char flag1;
    unsigned char flag2;
} foo;

typedef struct bar {
   int foo;
   long bar;
} bar;

void setup_foo(struct foo *s)
{
    s->flag2 = 1;
}

int main(void)
{
   foo s;
   bar b1, b2;
   FILE *file;
   int file2;
   setup_foo(&s);                                                             /* Line 34 */
   if (s.flag1 || s.flag2)                                                     /* Line 35 */   
        printf("hey\n");

   file = fopen("temporary_file", "w");
   fprintf(file, "Printing to the  file!\n");
   fprintf(file, "flag1 value: ");
   putw(s.flag1, file);
   fclose(file);

   b1.foo = 1;
   b1.bar = 2;

   /* This is fine. */
   b2 = b1;
   file2 = open("temp2", O_CREAT | O_RDWR);
   write (file2, &b2, sizeof(b2));
   return 0;
}
