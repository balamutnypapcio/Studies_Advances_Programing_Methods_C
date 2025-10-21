/*
 * Program zawiera przyklady definiowania makr, ktore pozwalaja
 * zamienic dany argument na napis.
 *
 * Aby zobaczyc "surowy" efek dzialania preprocesora mozna wywolac
 * plecenie
 *          gcc -E conv2string.c
 */
#include <stdio.h>

/*
 * Makro to pozwala zamienic dowolny ciag znakow na napis.
 * Warunkiem poprawnego rozwiniecia makra jest to, aby
 * po jego rozwinieciu znak '#' nie byl pierwszym znakiem 
 * w danej linii.
 */
#define STR(x)  #x


int main()
{
  printf(STR( Dowolny napis ));
}
