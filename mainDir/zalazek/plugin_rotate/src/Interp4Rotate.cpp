#include <iostream>
#include "Interp4Rotate.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Rotate"; }
}




/*!
 * \brief
 *
 *
 */
AbstractInterp4Command* CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}


/*!
 *
 */
Interp4Rotate::Interp4Rotate(): _Axe(x), _Speed_ds(10), _Degree_d(30)
{}


/*!
 *
 */
void Interp4Rotate::PrintCmd() const
{
    // Pomocnicza funkcja do konwersji enum na string, żeby ładnie wyświetlić
    auto AxeToString = [](axes axe) -> std::string {
        switch (axe) {
            case x: return "OX";
            case y: return "OY";
            case z: return "OZ";
            default: return "??";
        }
    };

    cout << GetCmdName() << " Axe: " << AxeToString(_Axe) 
         << " Speed: " << _Speed_ds << " deg/s"
         << " Angle: " << _Degree_d << " deg";
}


/*!
 *
 */
const char* Interp4Rotate::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Rotate::ExecCmd( AbstractScene      &rScn, 
                           const char         *sMobObjName,
			   AbstractComChannel &rComChann
			 )
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
    std::string ObjName; // Zmienna na nazwę obiektu, na razie nieużywana
    std::string AxeName; // Pomocnicza zmienna do wczytania nazwy osi

    Strm_CmdsList >> ObjName >> AxeName >> _Speed_ds >> _Degree_d;
    
    // Sprawdź, czy wczytywanie się powiodło
    if (Strm_CmdsList.fail()) {
        return false;
    }

    // --- Konwersja nazwy osi na enum ---
    if (AxeName == "OX") {
        _Axe = x;
    } else if (AxeName == "OY") {
        _Axe = y;
    } else if (AxeName == "OZ") {
        _Axe = z;
    } else {
        // Jeśli nazwa osi jest nieprawidłowa, uznaj to za błąd parametrów
        std::cerr << "!!! Błąd: Nieznana nazwa osi: " << AxeName << std::endl;
        return false; 
    }
    
    return true; // Wszystko wczytane poprawnie
}


/*!
 *
 */
AbstractInterp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}


/*!
 *
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  NazwaObiektu  Os[x/y/z] SzybkoscKatowa [d/s] KatObtotu[d]" << endl;
}
