#include <iostream>
#include "Interp4Set.hh"

#include <sstream>
#include <unistd.h> 
#include "ComChannel.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Set"; }
}




/*!
 * \brief
 *
 *
 */
AbstractInterp4Command* CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}


/*!
 *
 */
Interp4Set::Interp4Set() {}


/*!
 *
 */
void Interp4Set::PrintCmd() const {
    std::cout << _Position[0] << " " << _Position[1] << " " << _Position[2] << " "
              << _Orientation[0] << " " << _Orientation[1] << " " << _Orientation[2];
}


/*!
 *
 */
const char* Interp4Set::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Set::ExecCmd(AbstractScene &rScn, const char *sMobObjName, AbstractComChannel &rComChann) {
    std::stringstream cmd;
    cmd << "UpdateObj Name=" << sMobObjName 
        << " Trans_m=(" << _Position[0] << "," << _Position[1] << "," << _Position[2] << ")"
        << " RotXYZ_deg=(" << _Orientation[0] << "," << _Orientation[1] << "," << _Orientation[2] << ")\n";
    
    rComChann.Send(cmd.str());
    return true;
}

/*!
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm) {
    Strm >> _Position[0] >> _Position[1] >> _Position[2]
         >> _Orientation[0] >> _Orientation[1] >> _Orientation[2];
    return !Strm.fail();
}


/*!
 *
 */
AbstractInterp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}


/*!
 *
 */
void Interp4Set::PrintSyntax() const {
    cout << "   Set  NazwaObiektu  X Y Z  Yaw Pitch Roll" << endl;
}
