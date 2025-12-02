#include <iostream>
#include "Interp4Rotate.hh"

#include <sstream>
#include <unistd.h> 
#include "ComChannel.hh"
#include "MobileObj.hh"


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
Interp4Rotate::Interp4Rotate(): _Axe(x), _Speed_ds(0.0), _Degree_d(0.0)
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
bool Interp4Rotate::ExecCmd(AbstractScene &rScn, const char *sMobObjName, AbstractComChannel &rComChann) {

    if (_Degree_d < 0) {
        std::cerr << "Blad: Kat obrotu musi byc nieujemny!" << std::endl;
        return false;
    }

    MobileObj* pObj = static_cast<MobileObj*>(rScn.FindMobileObj(sMobObjName));
    if (!pObj) {
        std::cerr << "Blad: Nie znaleziono obiektu '" << sMobObjName << "' na scenie." << std::endl;
        return false;
    }
    
    const double DURATION_S = std::abs(_Degree_d / _Speed_ds);
    const int NUM_FRAMES = 100;
    const unsigned int FRAME_DELAY_US = (DURATION_S / NUM_FRAMES) * 1000000;
    double step_degree = (static_cast<double> (_Degree_d) / NUM_FRAMES) * (_Speed_ds > 0 ? 1 : -1);
    double current_angle = 0.0;


    for (int i = 0; i < NUM_FRAMES; ++i) {
        current_angle += step_degree;
        pObj->Lock();
        std::stringstream cmd;

        cmd << "UpdateObj Name=" << sMobObjName << " RotXYZ_deg=";
        
        switch (_Axe) {
            case axes::x:
                cmd << "(" << current_angle << ",0,0)";
                break;
            case axes::y:
                cmd << "(0," << current_angle << ",0)";
                break;
            case axes::z:
                cmd << "(0,0," << current_angle << ")";
                break;
        }
        
        cmd << "\n";

        rComChann.Send(cmd.str());
        pObj->Unlock();

        usleep(FRAME_DELAY_US);
    }
    return true;
}


/*!
 *
 */
bool Interp4Rotate::ReadParams(std::istream& Strm) {
    std::string axisName;
    Strm >> axisName >> _Speed_ds >> _Degree_d;
    
    if (Strm.fail()) {
        return false;
    }
    
    // Konwersja stringa na enum
    if (axisName == "OX" || axisName == "Ox" || axisName == "ox") {
        _Axe = axes::x;
    } else if (axisName == "OY" || axisName == "Oy" || axisName == "oy") {
        _Axe = axes::y;
    } else if (axisName == "OZ" || axisName == "Oz" || axisName == "oz") {
        _Axe = axes::z;
    } else {
        std::cerr << "Blad: Nieznana os '" << axisName << "'" << std::endl;
        return false;
    }
    
    return true;
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
