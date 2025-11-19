#include <iostream>
#include "Interp4Move.hh"

#include <sstream>
#include <unistd.h> 
#include "ComChannel.hh"


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
Interp4Move::Interp4Move(): _Speed_mmS(0), _Distance_mm(100)
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
    
    double totalTime = _Distance_mm / std::abs(_Speed_mmS);
    const double timeStep = 0.1;
    int steps = static_cast<int>(totalTime / timeStep);
    double stepDistance = (_Speed_mmS > 0 ? _Distance_mm : -_Distance_mm) / steps;
    
    for (int i = 1; i <= steps; ++i) {
        std::stringstream cmd;
        cmd << "UpdateObj Name=" << sMobObjName
            << " Trans_m=(" << stepDistance * i << ",0,0)\n";
        
        rComChann.Send(cmd.str());
        usleep(static_cast<int>(timeStep * 1000000));
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
