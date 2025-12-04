#include <iostream>
#include "Interp4Move.hh"

#include <sstream>
#include <unistd.h> 
#include "ComChannel.hh"
#include "MobileObj.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}




/*!
 * \brief
 *
 *
 */
AbstractInterp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


/*!
 *
 */
Interp4Move::Interp4Move(): _Speed_mmS(0.0), _Distance_mm(0.0)
{}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " " << _Speed_mmS << " "<< _Distance_mm << endl;
}


/*!
 *
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Move::ExecCmd(AbstractScene &rScn, const char *sMobObjName, AbstractComChannel &rComChann) {
  
    if (_Distance_mm < 0) {
        std::cerr << "Blad: Dlugosc drogi musi byc nieujemna!" << std::endl;
        return false;
    }
    MobileObj* pObj = static_cast<MobileObj*>(rScn.FindMobileObj(sMobObjName));
    if (!pObj) {
        std::cerr << "Blad: Nie znaleziono obiektu '" << sMobObjName << "' na scenie." << std::endl;
        return false;
    }
    
    // === POBIERZ POCZĄTKOWĄ POZYCJĘ ===
    pObj->Lock();
    Vector3D start_pos = pObj->GetPositoin_m();
    pObj->Unlock();


    // === OBLICZ PARAMETRY ANIMACJI ===
    const double DURATION_S = _Distance_mm / std::abs(_Speed_mmS);
    const double FPS = 60.0;
    const int NUM_FRAMES = static_cast<int>(DURATION_S * FPS);
    const unsigned int FRAME_DELAY_US = 16666;  // ~1/60s

    if (NUM_FRAMES == 0) {
      std::cerr << "Ruch zbyt krotki, pomijam." << std::endl;
      return true;
    }

    double step_dist = (_Distance_mm / NUM_FRAMES) * (_Speed_mmS > 0 ? 1.0 : -1.0);
  
    for (int i = 0; i < NUM_FRAMES; ++i) {    
        pObj->Lock();
        
        //OBLICZ BEZWGLEDNA POZYCJE WZGLEDEM AKTUALNEJ POZYCJI OBIEKTU
        Vector3D new_pos = start_pos;
        new_pos[0] += step_dist * i; 
        pObj->SetPosition_m(new_pos);
        
        std::stringstream cmd;
        cmd << "UpdateObj Name=" << sMobObjName 
            << " Trans_m=(" << new_pos[0] << "," << new_pos[1] << "," << new_pos[2] << ")\n";
        
        rComChann.Send(cmd.str());
        pObj->Unlock();
        
        usleep(FRAME_DELAY_US);
    }
    return true;
}


/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
    Strm_CmdsList >> _Speed_mmS >> _Distance_mm;
    return !Strm_CmdsList.fail();
}


/*!
 *
 */
AbstractInterp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}
