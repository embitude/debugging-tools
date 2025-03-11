#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *banner;

char *create_banner ()
 {
   const char *user = getenv ("USER");
   size_t len = 1 + 2 * 4 + strlen (user) + 1;
   char *b = malloc (len);
   sprintf (b, "\t|** %s **|", user);
   return b;
 }

void output_report (int nr)
 {
   puts (banner);
   printf ("Number: %d\n", nr);
   printf ("\n");
 }

 int main ()
 {
   banner = create_banner ();

   for (int i = 1; i <= 3; i++)
     output_report (i);

   return 0;
 }
