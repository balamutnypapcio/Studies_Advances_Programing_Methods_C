#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "AbstractInterp4Command.hh"

using namespace std;


int main()
{
  void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
  AbstractInterp4Command *(*pCreateCmd_Move)(void);
  void *pFunMove;

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
    return 1;
  }

  pFunMove = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFunMove) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Move = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFunMove);

  AbstractInterp4Command *pCmd_Move = pCreateCmd_Move();
  /////// Rotate ------------------

  void *pLibHnd_Rotate = dlopen("libInterp4Rotate.so",RTLD_LAZY);
  AbstractInterp4Command *(*pCreateCmd_Rotate)(void);
  void *pFunRotate;


  pFunRotate = dlsym(pLibHnd_Rotate,"CreateCmd");
  if (!pFunRotate) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Rotate = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFunRotate);

  AbstractInterp4Command *pCmd_Rotate = pCreateCmd_Rotate();

  cout << endl;
  cout << pCmd_Move->GetCmdName() << endl;
  cout << endl;
  pCmd_Move->PrintSyntax();
  cout << endl;
  pCmd_Move->PrintCmd();
  cout << endl;

  cout << endl;
  cout << pCmd_Rotate->GetCmdName() << endl;
  cout << endl;
  pCmd_Rotate->PrintSyntax();
  cout << endl;
  pCmd_Rotate->PrintCmd();
  cout << endl;
  
  delete pCmd_Move;
  delete pCmd_Rotate;

  dlclose(pLibHnd_Move);
  dlclose(pLibHnd_Rotate);
}
