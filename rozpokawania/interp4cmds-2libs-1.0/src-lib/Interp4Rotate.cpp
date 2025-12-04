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

    if (std::abs(_Speed_ds) < 0.001) {
        std::cerr << "Blad: Predkosc katowa nie moze byc zerowa!" << std::endl;
        return false;
    }

    MobileObj* pObj = static_cast<MobileObj*>(rScn.FindMobileObj(sMobObjName));
    if (!pObj) {
        std::cerr << "Blad: Nie znaleziono obiektu '" << sMobObjName << "' na scenie." << std::endl;
        return false;
    }
    
    // === POBIERZ POCZĄTKOWĄ ORIENTACJĘ ===
    pObj->Lock();
    double start_yaw = pObj->GetAng_Yaw_deg();
    double start_pitch = pObj->GetAng_Pitch_deg();
    double start_roll = pObj->GetAng_Roll_deg();
    pObj->Unlock();


    // === OBLICZ PARAMETRY ANIMACJI ===
    const double DURATION_S = static_cast<double>(_Degree_d) / std::abs(_Speed_ds);
    const double FPS = 60.0;
    const int NUM_FRAMES = static_cast<int>(DURATION_S * FPS);
    const unsigned int FRAME_DELAY_US = 16666; // ~1/60s

    if (NUM_FRAMES == 0) {
        std::cerr << "Obrot zbyt krotki, pomijam." << std::endl;
        return true;
    }
    
    double step_angle = (static_cast<double>(_Degree_d) / NUM_FRAMES) * (_Speed_ds > 0 ? 1.0 : -1.0);

    for (int i = 0; i < NUM_FRAMES; ++i) {
        pObj->Lock();
        
        // Oblicz NOWĄ BEZWZGLĘDNĄ orientację
        double new_yaw = start_yaw;
        double new_pitch = start_pitch;
        double new_roll = start_roll;
        
        switch (_Axe) {
            case axes::x:  // OX = Pitch
                new_pitch = start_pitch + (step_angle * i);
                break;
            case axes::y:  // OY = Yaw
                new_yaw = start_yaw + (step_angle * i);
                break;
            case axes::z:  // OZ = Roll
                new_roll = start_roll + (step_angle * i);
                break;
        }
        
        // Zaktualizuj lokalny obiekt
        pObj->SetAng_Yaw_deg(new_yaw);
        pObj->SetAng_Pitch_deg(new_pitch);
        pObj->SetAng_Roll_deg(new_roll);
        
        // Wyślij BEZWZGLĘDNĄ orientację do serwera
        std::stringstream cmd;
        cmd << "UpdateObj Name=" << sMobObjName 
            << " RotXYZ_deg=(" << new_yaw << "," << new_pitch << "," << new_roll << ")\n";
        
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
