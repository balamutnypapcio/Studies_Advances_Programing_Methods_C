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
    
    const double DURATION_S = _Distance_mm / std::abs(_Speed_mmS);
    const int NUM_FRAMES = 100;
    const unsigned int FRAME_DELAY_US = (DURATION_S / NUM_FRAMES) * 1000000;
    double step_dist = (static_cast<double>(_Distance_mm) / NUM_FRAMES) * (_Speed_mmS > 0 ? 1 : -1);
    double distance_covered = 0.0;

    for (int i = 0; i < NUM_FRAMES; ++i) {    
        pObj->Lock();
        distance_covered += step_dist;
        std::stringstream cmd;
        cmd << "UpdateObj Name=" << sMobObjName << " Trans_m=(" << distance_covered << ",0,0)\n";
        rComChann.Send(cmd.str());
        pObj->Unlock();
        std::cout<<"i"<<std::endl;
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
