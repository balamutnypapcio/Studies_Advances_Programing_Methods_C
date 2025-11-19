#include <iostream>
#include "Interp4Rotate.hh"

#include <sstream>
#include <unistd.h> 
#include "ComChannel.hh"


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
bool Interp4Rotate::ExecCmd(AbstractScene &rScn, const char *sMobObjName, AbstractComChannel &rComChann) {
    if (_Degree_d < 0) {
        std::cerr << "Blad: Kat obrotu musi byc nieujemny!" << std::endl;
        return false;
    }
    
    double totalTime = _Degree_d / std::abs(_Speed_ds);
    const double timeStep = 0.1;
    int steps = static_cast<int>(totalTime / timeStep);
    double stepAngle = (_Speed_ds > 0 ? _Degree_d : -_Degree_d) / steps;
    
    for (int i = 1; i <= steps; ++i) {
        std::stringstream cmd;
        cmd << "UpdateObj Name=" << sMobObjName << " RotXYZ_deg=";
        
        double currentAngle = stepAngle * i;
        
        switch (_Axe) {
            case axes::x:
                cmd << "(" << currentAngle << ",0,0)";
                break;
            case axes::y:
                cmd << "(0," << currentAngle << ",0)";
                break;
            case axes::z:
                cmd << "(0,0," << currentAngle << ")";
                break;
        }
        
        cmd << "\n";
        rComChann.Send(cmd.str());
        usleep(static_cast<int>(timeStep * 1000000));
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
