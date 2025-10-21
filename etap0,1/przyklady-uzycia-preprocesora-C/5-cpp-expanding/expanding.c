/*
 * Program zawiera przyklady definiowania makr, ktore pozwalaja
 * polaczyc napisy. Ta operacja pozwala na "skonstruowanie"
 * wywolania nastepnego makra.
 * W tym przykładzie pokazana jest przypadek zlego uzycia tego 
 * typu makra, ktora potencjalnie moglaby prowadzic do rekurencyjnego
 * rozwiniecia makra. 
 * Jednak mechanizmy wbudowane w cpp unimozliwiaja realizacje 
 * takiej operacji.
 *
 * Aby zobaczyc "surowy" efek dzialania preprocesora mozna wywolac
 * plecenie
 *          gcc -E conv2string.c
 */
#include <stdio.h>

enum MotorType { mt_Wheel, mt_Turret };

/*
 * Tu konstruowany jest nowy napis
 * Dla tego makra dopuszczalnymi wartosciami parametru Motor
 * jest  Wheel lub Turret
 */
#define MAKE_DV(Motor)  mt_##Motor

#define MAKE_Wheel(Speed, FinalPos)  SetWheel(Speed, FinalPos)
#define MAKE_Turret(Speed, FinalPos) SetTurret(FinalPos)

/*
 * W tym makrze konstruowane jest wywolanie makra INIT_...
 * Dla tego makra dopusczalnymi wartosciami parametru Motor
 * jest  Wheel lub Turret.
 *
 * Uzycie slowa CASE mogloby prowadzic do rekurencyjnego
 * rozwiniecia makra MAKE_CASE. Dlaczego tak nie jest?
 */
#define MAKE_CASE(Motor,FinalPos)  \
  case MAKE_DV(Motor):  MAKE_##Motor(30,FinalPos);  break


void SetWheel(double Speed, double FinalPos) {}
void SetTurret(double Pos) {}



void InitMotor( enum MotorType  Motor )
{
  switch(Motor) {
    MAKE_CASE(Wheel,0);
    MAKE_CASE(Turret,90);
    MAKE_CASE(CASE,0);   // Przyklad zlego uzycia makra MAKE_CASE
  }
}


int main()
{
  return 0;
}
