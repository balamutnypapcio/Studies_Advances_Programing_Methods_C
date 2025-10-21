/*
 * Dolecenie #define mozna wykorzystac do definiowania symboli.
 * Takie symbole nie zawsze musza miec tresc. Mozna je wykorzystac
 * do kompilacji warunkowej.
 *
 * Aby zobaczyc "surowy" efek dzialania preprocesora mozna wywolac
 * plecenie
 *          gcc -E conv2string.c
 */
#include <stdio.h>

/*
 * Aby zobaczyc mozliwosc tworzenia roznych wariantow kompilacji
 * zalecane jest skompilowanie programu i zobaczenie efektu 
 * jego dzialania. Nastepnie nalezy zakomentowac ponizsza definicje,
 * powtorzyc kompilacje i zobaczyc efekt dzialania.
 */
#define  HELLO  "Hello"


#ifdef HELLO
/*
 * Usuwamy dotychczasowa definicje symbolu HELLO
 */
# undef  HELLO
/*
 * Definiujemy na nowo symbol HELLO. Wczesniejsze
 * uniewaznienie definicji poleceniem #undef zapobiega
 * wyswietlaniu przez cpp ostrzezen o redefiniowaniu 
 * symbolu.
 */
# define HELLO "Hello World"
#else
# define WITAJ "Witaj Swiecie"
#endif



int main()
{

#ifdef HELLO
  printf(HELLO"\n");
#else
  printf(WITAJ"\n");
#endif

  return 0;
}
