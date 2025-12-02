#include "gsv-BackgroundUtils.hh"
#include <QGLViewer/qglviewer.h>
#include "gsv-BackgroundImage.h"
#include "gsv-WgViewer3D.hh"
#include <iostream>

using std::cout;
using std::endl;


#ifdef SOIL_AVAILABLE 

 #include <SOIL/SOIL.h>

 static GLuint Texture4Bg;

#endif





void InitTexture()
{
#ifdef SOIL_AVAILABLE   
   /*------------
    *  Tworzenie tekstury tła
    */

  Texture4Bg = SOIL_load_OGL_texture(
		gsv::WgViewer3D::Use_Viewer()->GetBgImageFileName().c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	       );
#endif
}




void CreateBackground()
{
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);


#ifdef SOIL_AVAILABLE
  if (gsv::WgViewer3D::Get_Viewer()->IsChanged_BgImageFileName()) {
    gsv::WgViewer3D::Use_Viewer()->ResetChange_BgImageFileName();
    InitTexture();
  }
  glBindTexture(GL_TEXTURE_2D, Texture4Bg);
#endif

#ifdef SOIL_AVAILABLE     
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  
  glLoadIdentity();
  glDepthMask(GL_FALSE);

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();

  glLoadIdentity();
  glOrtho(0,1,1,0,-1,1);


  glBegin(GL_QUADS);  // Tworzenie kwadratu, na którym będzie
    glTexCoord2f(0,0); // rozpięta tekstura tła.
    glVertex2f(0,0);

    glTexCoord2f(1,0);
    glVertex2f(1,0);

    glTexCoord2f(1,1);
    glVertex2f(1,1);

    glTexCoord2f(0,1);
    glVertex2f(0,1);
  glEnd();
  
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
#endif
  
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}






bool IsSOIL_Available()
{
#ifdef SOIL_AVAILABLE
  return true;
#else
  return false;
#endif
}


