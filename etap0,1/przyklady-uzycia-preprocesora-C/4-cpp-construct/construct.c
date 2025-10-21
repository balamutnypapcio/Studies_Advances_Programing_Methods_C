/*
 * Program zawiera przyklady definiowania makr, ktore pozwalaja
 * polaczyc napisy (wykorzystanie sekwencji ##). 
 * Ta operacja pozwala na "skonstruowanie" wywolania nastepnego makra.
 *
 * Aby zobaczyc "surowy" efek dzialania preprocesora mozna wywolac
 * plecenie
 *          gcc -E conv2string.c
 */
#include <stdio.h>

enum MotorType { mt_Wheel, mt_Turret };

/*
 * Tu konstruowany jest nowy napis
 * Dla tego makra dopusczalnymi wartosciami parametru Motor
 * jest  Wheel lub Turret
 */
#define MAKE_DV(Motor)  mt_##Motor

#define INIT_Wheel  SetWheel(0)
#define INIT_Turret SetTurret(90)

/*
 * W tym makrze konstruowane jest wywolanie makra INIT_...
 * Dla tego makra dopuszczalnymi wartosciami parametru Motor
 * jest  Wheel lub Turret
 */
#define MAKE_CASE(Motor)  case MAKE_DV(Motor):  INIT_##Motor;  break


void SetWheel(double Speed) {}
void SetTurret(double Pos) {}



void InitMotor( enum MotorType  Motor )
{
  switch(Motor) {
    MAKE_CASE(Wheel);
    MAKE_CASE(Turret);
  }
}


int main()
{
  return 0;
}
