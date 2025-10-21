/*
 * Niniejszy przyklad demonstruje poprawna i niepoprawna 
 * konstrukcje makra. Aby sie o tym przekonac, mozna
 * porownac wyniki wyswietlanych operacji.
 *
 * Odpowiednie umieszczanie nawiasow gwarantuje zachowanie
 * zachowanie prawidlowej kolejnosci wykonywanych operacji.
 *
 * Aby zobaczyc "surowy" efek dzialania preprocesora mozna wywolac
 * plecenie
 *          gcc -E conv2string.c
 */
#include <stdio.h>


#define MAX_WRONG(x,y)  x > y ? x : y

#define MAX_GOOD(x,y)  (((x) > (y)) ? (x) : (y))


int main()
{
  double Result_Wrong;
  double Result_Good;

  Result_Wrong = 2 + MAX_WRONG(2,3) * 10;

  Result_Good  = 2 + MAX_GOOD(2,3) * 10;

  printf(" Wynik niepoprawny: 2 + max(2,3) * 10 = %g\n", Result_Wrong);
  printf("    Wynik poprawny: 2 + max(2,3) * 10 = %g\n", Result_Good);

  return 0;
}
