#include "gtsDebug.hh"
#include <iostream>
#include <iomanip>

using namespace std;


void Funkcja1()
{
  DOut1( "Wydruk kontrolny A" );
  cout << "Normalny komunikat" << endl;
}


void Funkcja2()
{
  DOut1( "Wydruk kontrolny B" );

  double Zm = 0.2*0.2;

  DOut2( "Wydruk kontrolny C: " << Zm );
  Funkcja1();
  cout <<  "Operacja zakonczona" << endl;
  DOut4( "Wydruk kontrolny D" );
 
  if (Zm != 0.04) CErr_1( "Cos poszlo nie tak" << endl <<
                         "    Oczekiwany wynik: " << fixed << setprecision(20) 
                                                  << 0.04 << endl <<
                         "     Faktyczny wynik: " << Zm
                       );
}

int main()
{
  cout << "Hello" << endl;
  Funkcja1();
  Funkcja2();
  cout << "Bye, bye" << endl;
}
