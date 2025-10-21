/*
 * Przyklad demonstruje sposob definiowania dlugich symboli
 * lub makr.
 * Nalezy pamietac, ze polecenie #define musi byc w jednej linii.
 * Dlatego tez w przypadku dlugich symboli lub makr nalezy stosowac
 * znaki kontynuacji linii.
 *
 * Aby zobaczyc "surowy" efek dzialania preprocesora mozna wywolac
 * plecenie
 *          gcc -E conv2string.c
 */
#include <stdio.h>


#define LONG_SYM   "To jest przyklad dlugiego napisu,"       \
                   " ktory trudno zapisac w jednej linii.\n" \
                   "Dzieki znakom kontynuacji linii"         \
                   "Mozna ten problem sensownie rozwiazac\n"

#define LONG_MACRO(x)                                    \
  if (x > 4) {                                           \
     printf(" Liczba %i jest wieksza od 4.\n",x);  	 \
  } else {                                               \
     printf(" Liczba %i jest mniejsza lub rowna 4.\n",x);\
  }


int main()
{
  LONG_MACRO(2)
  printf( LONG_SYM);
  return 0;
}
