#include <iostream>
#include "gsv-WgViewer3D.hh"
#include "gsv-Vector3-Utils.hh"
#include "gsv-BackgroundUtils.hh"
#include "gtsDebug.hh"
#include <fstream>
#include "gsv-BackgroundImage.h"
#include <QKeyEvent>

using namespace std;





gsv::WgViewer3D* gsv::WgViewer3D::_pViewer = nullptr;



//====================================================================
//===                  WgViewier3D
//===


/*!
 *
 */
gsv::WgViewer3D::WgViewer3D(QWidget *pParent, gsv::BufferedScene  *pBScn):
  QGLViewer(pParent),  _pBuffScn(pBScn)
{
  _pViewer = this;
  Set(_BgColor,0.5f,0.5f,0.5f);
  setAttribute(Qt::WA_DeleteOnClose);
  Check_SetBgImageFileName(FILE_BACKGROUND_IMAGE);
  _Timer.setInterval(50);
  connect(&_Timer,SIGNAL(timeout()),this,SLOT(PeriodicSceneUpdate()));
  _Timer.start();
}



/*!
 *
 */
void gsv::WgViewer3D::keyPressEvent(QKeyEvent *pEvent)
{
  switch (pEvent->key()) {
    case 'R':
      switch (GetDrawMode()) {
       case DM_Line: SetDrawMode(DM_Fill); break;
       case DM_Fill: SetDrawMode(DM_Line); break;
      }
      break;
      
    case 'L':
      SetShowLocalCrds(!GetShowLocalCrds());
      break;
      
    default: break;
  }
  QGLViewer::keyPressEvent(pEvent);
}



/*!
 * \brief Zmienia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
 */
void gsv::WgViewer3D::SetBgImageFileName(const std::string & rName)
{
  if (_BgImageFileName.Get() == rName) return;
  _BgImageFileName.Use() = rName;
}



/*!
 * \brief Zmienia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
 */
void gsv::WgViewer3D::SetBgImageFileName(const std::string && rrName)
{
  if (_BgImageFileName.Get() == rrName) return;
  _BgImageFileName.Use() = rrName;
}




/*!
 * Zmienia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
 */
bool gsv::WgViewer3D::Check_SetBgImageFileName(const char *sName)
{
  std::ifstream IStrm(sName);

  if (!IStrm.is_open()) {
    CErr_1(" Brak dostepu do pliku \"" << sName << "\"");
    return false;
  }
  SetBgImageFileName(sName);
  SetSceneChanged();
  return true;
}





void gsv::WgViewer3D::PeriodicSceneUpdate()
{
  if (_pBuffScn->IsChanged()) update();
}








void gsv::WgViewer3D::init()
{
  // Restore previous viewer state.
  restoreStateFromFile();
  glEnable(GL_DEPTH_TEST);
  InitTexture();
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
}




void gsv::WgViewer3D::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_TEXTURE_2D);
   /*-----------------------------------------------------
    *  Tworzenie tła wypełnionego wygenerowaną teksturą
    */
  glClearColor(GetBgColorRGB(0),GetBgColorRGB(1),GetBgColorRGB(2),1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  if (GetDrawMode() == gsv::DM_Fill) glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
                                else glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); 
  
  CreateBackground();
  // glClearColor(GetBgColorRGB(0),GetBgColorRGB(1),GetBgColorRGB(2),1.0f);
  // glClear(GL_COLOR_BUFFER_BIT);
  
  glDisable(GL_TEXTURE_2D);
  
  glDepthMask(GL_TRUE);

  
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);

  
  glScalef( 0.2, 0.2, 0.2 );

  _pBuffScn->LockAccessToCurrScn();
  /* 
  cout << "----- Nodes Tree ___ Start --------------" << endl;
  _pBuffScn->GetCurrScn().PrintNodeTree();
  cout << "----- Nodes Tree ___ End ----------------" << endl;
  */

  _pBuffScn->GetCurrScn().DrawSceneGL(this);
  _pBuffScn->CancelTrace0Change();
  _pBuffScn->UnlockAccessToCurrScn();
 glFlush();
 glDisable(GL_TEXTURE_2D);  
}



QString gsv::WgViewer3D::helpString() const
{
  QString text("<h2>Serwer Graficzny</h2>");
  text += "Dodatkowe skróty klawiszowe:";
  text += " <ul><li>   L - przełączenie między trybem rysowania lokalnych współrzędnych i ich pomijaniem.</li>";
  text += "     <li>   R - przełączenie między trybem rysowania liniami i z wypełnieniem.</li></ul>";
  text += "<h2>V i e w e r 3 D</h2>";
  text += "Use the mouse to move the camera around the object. ";
  text += "You can respectively revolve around, zoom and translate with the three mouse buttons. ";
  text += "Left and middle buttons pressed together rotate around the camera view direction axis<br><br>";
  text += "Pressing <b>Alt</b> and one of the function keys (<b>F1</b>..<b>F12</b>) defines a camera keyFrame. ";
  text += "Simply press the function key again to restore it. Several keyFrames define a ";
  text += "camera path. Paths are saved when you quit the application and restored at next start.<br><br>";
  text += "Press <b>F</b> to display the frame rate, <b>A</b> for the world axis, ";
  text += "<b>Alt+Return</b> for full screen mode and <b>Control+S</b> to save a snapshot. ";
  text += "See the <b>Keyboard</b> tab in this window for a complete shortcut list.<br><br>";
  text += "Double clicks automates single click actions: A left button double click aligns the closer axis with the camera (if close enough). ";
  text += "A middle button double click fits the zoom of the camera and the right button re-centers the scene.<br><br>";
  text += "A left button double click while holding right button pressed defines the camera <i>Revolve Around Point</i>. ";
  text += "See the <b>Mouse</b> tab and the documentation web pages for details.<br><br>";
  text += "Press <b>Escape</b> to exit the viewer.";
  return text;
}



//===
//===                  WgViewier3D
//====================================================================
