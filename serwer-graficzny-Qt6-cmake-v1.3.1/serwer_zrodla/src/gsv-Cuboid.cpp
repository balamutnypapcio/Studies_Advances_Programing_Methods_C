#include "gsv-Cuboid.hh"
#include "gtsDebug.hh"
#include <iostream>
#include <sstream>
#include <QGLViewer/qglviewer.h>
#include <cmath>
#include "gsv-Vector3f.hh"

using namespace std;


inline
unsigned short int MakeBrighter(unsigned short int Lum)
{
  #define SHIFT  20
  
  if (Lum > (255-SHIFT)) return 255;
  return Lum+SHIFT;
}





#define Vx(Sign) (Sign 0.5)
#define COORDS3(Vec)  Vec[0],Vec[1],Vec[2]
#define OPO_COORDS3(Vec)  -Vec[0],-Vec[1],-Vec[2]
#define REV_COORD(Val) (Val ? 1/Val:0)
#define REV_COORDS3(Vec)  REV_COORD(Vec[0]),REV_COORD(Vec[1]),REV_COORD(Vec[2])


void DrawCuboid()
{
  glBegin(GL_QUADS);
   glNormal3f(-1,0,0);
   glVertex3f( Vx(-), Vx(-),  Vx(-));  // Boczna x=-1
   glVertex3f( Vx(-), Vx(+),  Vx(-));
   glVertex3f( Vx(-), Vx(+),  Vx(+));
   glVertex3f( Vx(-), Vx(-),  Vx(+));

   
   glNormal3f(0,-1,0);
   glVertex3f( Vx(-), Vx(-),  Vx(-));  // Boczna y=-1
   glVertex3f( Vx(+), Vx(-),  Vx(-));
   glVertex3f( Vx(+), Vx(-),  Vx(+));
   glVertex3f( Vx(-), Vx(-),  Vx(+));

   glNormal3f(0,1,0);
   glVertex3f( Vx(-), Vx(+),  Vx(-));  // Boczna y=+1
   glVertex3f( Vx(+), Vx(+),  Vx(-));
   glVertex3f( Vx(+), Vx(+),  Vx(+));
   glVertex3f( Vx(-), Vx(+),  Vx(+));   


   glNormal3f(0,0,-1);
   glVertex3f( Vx(-), Vx(-),  Vx(-));  // Boczna z=-1
   glVertex3f( Vx(+), Vx(-),  Vx(-));
   glVertex3f( Vx(+), Vx(+),  Vx(-));
   glVertex3f( Vx(-), Vx(+),  Vx(-));

   glNormal3f(0,0,1);
   glVertex3f( Vx(-), Vx(-),  Vx(+));  // Boczna z=+1
   glVertex3f( Vx(+), Vx(-),  Vx(+));
   glVertex3f( Vx(+), Vx(+),  Vx(+));
   glVertex3f( Vx(-), Vx(+),  Vx(+));   
   /*
   glColor3ub(MakeBrighter(rColor.GetColor_Red()),
	      MakeBrighter(rColor.GetColor_Green()),
	      MakeBrighter(rColor.GetColor_Blue()));
   */
   glNormal3f(1,0,0);
   glVertex3f( Vx(+), Vx(-),  Vx(-));  // Boczna x=+1
   glVertex3f( Vx(+), Vx(+),  Vx(-));
   glVertex3f( Vx(+), Vx(+),  Vx(+));
   glVertex3f( Vx(+), Vx(-),  Vx(+));

  glEnd();
}




void DrawPrism()
{
  constexpr int VtxNo = 6;
  constexpr float Radius = 0.5;
  constexpr float AngStep_rad = 2*M_PI/VtxNo;
  constexpr float AngHalf_rad = AngStep_rad/2;
  float  TabX[VtxNo], TabY[VtxNo];
  float  Ang_deg = 0;
  
  glBegin(GL_POLYGON);
   glNormal3f(0.0f,0.0f,1.0f);
   for (int Idx = 0; Idx < VtxNo; ++Idx) {
     glVertex3f(TabX[Idx]=Radius*cos(Ang_deg), TabY[Idx]=Radius*sin(Ang_deg),  0.5f);
     Ang_deg += AngStep_rad;
   }
  glEnd();  

  glBegin(GL_POLYGON);
   glNormal3f(0.0f,0.0f,-1.0f);
   for (int Idx = 0; Idx < VtxNo; ++Idx) {
     glVertex3f(TabX[Idx], TabY[Idx],  -0.5f);
   }
  glEnd();  



  Ang_deg = AngHalf_rad;
  glBegin(GL_QUAD_STRIP);
  
   for (int Idx = 0; Idx < VtxNo; ++Idx) {
     glNormal3f(cos(Ang_deg), sin(Ang_deg), 0.0f);    
     glVertex3f(TabX[Idx], TabY[Idx],  -0.5f);
     glVertex3f(TabX[Idx], TabY[Idx],   0.5f);
     Ang_deg += AngStep_rad;
   }
   glNormal3f(cos(Ang_deg),sin(Ang_deg),0.0f);    
   glVertex3f(TabX[0], TabY[0],  -0.5f);
   glVertex3f(TabX[0], TabY[0],   0.5f);
    
  glEnd();
}






void DrawPyramid()
{
  constexpr int VtxNo = 6;
  constexpr float Radius = 0.5f;
  constexpr float AngStep_rad = 2*M_PI/VtxNo;
  constexpr float AngHalf_rad = AngStep_rad/2;
  float  TabX[VtxNo], TabY[VtxNo];
  float  Ang_deg = 0;
  
  glBegin(GL_POLYGON);
   glNormal3f(0.0f,0.0f,-1.0f);
   for (int Idx = 0; Idx < VtxNo; ++Idx) {
     glVertex3f(TabX[Idx]=Radius*cos(Ang_deg), TabY[Idx]=Radius*sin(Ang_deg),  -0.5f);
     Ang_deg += AngStep_rad;
   }
  glEnd();  

  constexpr float  sin_z = 0.5;
  constexpr float  cos_z = sqrt(3)/2;
  Ang_deg = AngHalf_rad;
  glBegin(GL_TRIANGLE_FAN);
     glVertex3f(0.0f, 0.0f, 0.5f);
     for (int Idx = 0; Idx < VtxNo; ++Idx) {
       glNormal3f(cos(Ang_deg)*cos_z,sin(Ang_deg)*cos_z,sin_z);    
       glVertex3f(TabX[Idx], TabY[Idx],  -0.5f);
       Ang_deg += AngStep_rad;
     }
   glNormal3f(cos(Ang_deg)*cos_z,sin(Ang_deg)*cos_z,sin_z);    
   glVertex3f(TabX[0], TabY[0],  -0.5f);
   glVertex3f(TabX[0], TabY[0],  -0.5f);

 glEnd();
}








void DrawHemisphere()
{
  constexpr  int    StripNum = 26; // Musi być podwójnie parzysta (dzielenie przez 4)
  constexpr  int    Quart_StripNum = StripNum/4; // Aby zachować te same kąty w poziomie i pionie
  constexpr  float  Ang_Step_rad = 2*M_PI/StripNum;
  constexpr  float  Ang_HalfStep_rad = Ang_Step_rad/2;
    
  //  float   z_prev = 0, z_new;
  //  float   radius_prev = 1, radius_new;
  float   sn_p, cs_p; // Dla punktu
  float   sn_n, cs_n; // Dla wektora normalnego (musi być przesunięty o pół kroku)

  float  Elev_rad = M_PI/2-Ang_Step_rad;
  float  sin_z = sinf(Elev_rad);
  float  cos_z = cosf(Elev_rad);
  
  float  sin_StepAng[StripNum+1];
  float  cos_StepAng[StripNum+1];

  float  sin_StepAng_n[StripNum+1];
  float  cos_StepAng_n[StripNum+1];


  gsv::Vector3f  PrevPnt[StripNum+1];
  gsv::Vector3f  CurrPnt[StripNum+1];
  gsv::Vector3f *pPrevPnt = PrevPnt;
  gsv::Vector3f *pCurrPnt = CurrPnt;


  int Idx_Azim = 0;
  float  Azim_Norm_rad = Ang_HalfStep_rad;
  //-----------------------------------------------------------------
  //  Rysowanie bieguna północnego sfery
  //
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 1.0f);
    // Idx_Azim = 0;    
    for (float Azim_rad = 0; Idx_Azim < StripNum;
	 ++Idx_Azim, Azim_rad += Ang_Step_rad, Azim_Norm_rad += Ang_Step_rad) {
      
       sin_StepAng_n[Idx_Azim] = sn_n = sinf(Azim_Norm_rad);
       cos_StepAng_n[Idx_Azim] = cs_n = cosf(Azim_Norm_rad);
       sin_StepAng[Idx_Azim] = sn_p = sinf(Azim_rad);
       cos_StepAng[Idx_Azim] = cs_p = cosf(Azim_rad);
       
       glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);
       
       glVertex3f(CurrPnt[Idx_Azim][0] = cs_p*cos_z,
		  CurrPnt[Idx_Azim][1] = sn_p*cos_z,
		  CurrPnt[Idx_Azim][2] = sin_z);
       
       // Azim_rad += Ang_Step_rad;
     }
     sin_StepAng_n[Idx_Azim] = sn_n = sinf(Azim_Norm_rad);
     cos_StepAng_n[Idx_Azim] = cs_n = cosf(Azim_Norm_rad);
     glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);    
     glVertex3f(CurrPnt[0][0], CurrPnt[0][1], CurrPnt[0][2]); // Zamknięcie wahlarza
  glEnd();

  //-----------------------------------------------------------------
  //  Rysowanie pasa wokół sfery
  //
   Elev_rad -= Ang_Step_rad;

   for (int Idx_Elev = 1; Idx_Elev < Quart_StripNum; ++Idx_Elev, Elev_rad -= Ang_Step_rad) {
    std::swap(pCurrPnt,pPrevPnt);
    sin_z = sinf(Elev_rad);
    cos_z = cosf(Elev_rad);

    Idx_Azim = 0;
    glBegin(GL_QUAD_STRIP);    
     for (float Azim_rad = 0; Idx_Azim < StripNum; ++Idx_Azim, Azim_rad += Ang_Step_rad) {
       sn_p = sin_StepAng[Idx_Azim];
       cs_p = cos_StepAng[Idx_Azim];
       sn_n = sin_StepAng_n[Idx_Azim];
       cs_n = cos_StepAng_n[Idx_Azim];       
       glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);
       
       glVertex3f(pPrevPnt[Idx_Azim][0],pPrevPnt[Idx_Azim][1],pPrevPnt[Idx_Azim][2]);
       glVertex3f(pCurrPnt[Idx_Azim][0] = cs_p*cos_z,
		  pCurrPnt[Idx_Azim][1] = sn_p*cos_z,
		  pCurrPnt[Idx_Azim][2] = sin_z);      
     }
     sn_n = sin_StepAng_n[Idx_Azim];
     cs_n = cos_StepAng_n[Idx_Azim];       
     glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);
     
     glVertex3f(pPrevPnt[0][0],pPrevPnt[0][1],pPrevPnt[0][2]);
     glVertex3f(pCurrPnt[0][0],pCurrPnt[0][1],pCurrPnt[0][2]);      
     
    glEnd();
   }
}





void DrawSphere()
{
  constexpr  int    StripNum = 26; // Musi być podwójnie parzysta (dzielenie przez 4)
  constexpr  int    Half_StripNum = StripNum/2;
  constexpr  float  Ang_Step_rad = 2*M_PI/StripNum;
  constexpr  float  Ang_HalfStep_rad = Ang_Step_rad/2;
    
  float   sn_p, cs_p; // Dla punktu
  float   sn_n, cs_n; // Dla wektora normalnego (musi być przesunięty o pół kroku)

  float  Elev_rad = M_PI/2-Ang_Step_rad; 
  float  sin_z = sinf(Elev_rad);
  float  cos_z = cosf(Elev_rad);
  
  float  sin_StepAng[StripNum+1];
  float  cos_StepAng[StripNum+1];

  float  sin_StepAng_n[StripNum+1];
  float  cos_StepAng_n[StripNum+1];


  gsv::Vector3f  PrevPnt[StripNum+1];
  gsv::Vector3f  CurrPnt[StripNum+1];
  gsv::Vector3f *pPrevPnt = PrevPnt;
  gsv::Vector3f *pCurrPnt = CurrPnt;


  int Idx_Azim = 0;
  float  Azim_Norm_rad = Ang_HalfStep_rad;
  //-----------------------------------------------------------------
  //  Rysowanie bieguna północnego sfery
  //
  glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);

    for (float Azim_rad = 0; Idx_Azim < StripNum;
	 ++Idx_Azim, Azim_rad += Ang_Step_rad, Azim_Norm_rad += Ang_Step_rad) {
      
       sin_StepAng_n[Idx_Azim] = sn_n = sinf(Azim_Norm_rad);
       cos_StepAng_n[Idx_Azim] = cs_n = cosf(Azim_Norm_rad);
       sin_StepAng[Idx_Azim] = sn_p = sinf(Azim_rad);
       cos_StepAng[Idx_Azim] = cs_p = cosf(Azim_rad);
       
       glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);
       
       glVertex3f(CurrPnt[Idx_Azim][0] = cs_p*cos_z,
		  CurrPnt[Idx_Azim][1] = sn_p*cos_z,
		  CurrPnt[Idx_Azim][2] = sin_z);
     }
     sin_StepAng_n[Idx_Azim] = sn_n = sinf(Azim_Norm_rad);
     cos_StepAng_n[Idx_Azim] = cs_n = cosf(Azim_Norm_rad);
     glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);    
     glVertex3f(CurrPnt[0][0], CurrPnt[0][1], CurrPnt[0][2]); // Zamknięcie wahlarza
  glEnd();

  //-----------------------------------------------------------------
  //  Rysowanie pasa wokół sfery
  //
  //  Elev_rad -= Ang_Step_rad;

  float sin_Elev_prev = sin_z;
  float cos_Elev_prev = cos_z;
  Elev_rad -= Ang_Step_rad;
  
   for (int Idx_Elev = 1; Idx_Elev < Half_StripNum-1; ++Idx_Elev, Elev_rad -= Ang_Step_rad) {
    std::swap(pCurrPnt,pPrevPnt);
    sin_Elev_prev = sin_z;
    cos_Elev_prev = cos_z;    
    sin_z = sinf(Elev_rad);
    cos_z = cosf(Elev_rad);

    Idx_Azim = 0;
    glBegin(GL_QUAD_STRIP);    
     for (float Azim_rad = 0; Idx_Azim < StripNum; ++Idx_Azim, Azim_rad += Ang_Step_rad) {
       sn_p = sin_StepAng[Idx_Azim];
       cs_p = cos_StepAng[Idx_Azim];
       sn_n = sin_StepAng_n[Idx_Azim];
       cs_n = cos_StepAng_n[Idx_Azim];       

       glNormal3f(cs_n*cos_Elev_prev,sn_n*cos_Elev_prev,sin_Elev_prev);
       glVertex3f(pPrevPnt[Idx_Azim][0],pPrevPnt[Idx_Azim][1],pPrevPnt[Idx_Azim][2]);
       
       glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);    
       glVertex3f(pCurrPnt[Idx_Azim][0] = cs_p*cos_z,
		  pCurrPnt[Idx_Azim][1] = sn_p*cos_z,
		  pCurrPnt[Idx_Azim][2] = sin_z);      
     }
     
     sn_n = sin_StepAng_n[Idx_Azim];
     cs_n = cos_StepAng_n[Idx_Azim];       
     glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);
     
     glVertex3f(pPrevPnt[0][0],pPrevPnt[0][1],pPrevPnt[0][2]);
     glVertex3f(pCurrPnt[0][0],pCurrPnt[0][1],pCurrPnt[0][2]);      
     
    glEnd();
   }


  //-----------------------------------------------------------------
  //  Rysowanie bieguna południowego sfery
  //
  // float  x_o, y_o, z_o;

   glBegin(GL_TRIANGLE_FAN);
    Elev_rad += 0.5*Ang_Step_rad; // TMP
    sin_z = sinf(Elev_rad);
    cos_z = cosf(Elev_rad); // Wykorzystanie dalej przy wahlarzu
    
    glNormal3f(0.0f,0.0f,-1.0f);
    glVertex3f(0.0f, 0.0f,-1.0f);
    Idx_Azim = 0;
    
    for (; Idx_Azim < StripNum;	 ++Idx_Azim) {
      
       sn_n = sin_StepAng_n[Idx_Azim];
       cs_n = cos_StepAng_n[Idx_Azim];
       
       glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);
       glVertex3f(pCurrPnt[Idx_Azim][0],pCurrPnt[Idx_Azim][1],pCurrPnt[Idx_Azim][2]);
     }
     sn_n = sin_StepAng_n[Idx_Azim];
     cs_n = cos_StepAng_n[Idx_Azim];
     glNormal3f(cs_n*cos_z,sn_n*cos_z,sin_z);
     glVertex3f(pCurrPnt[0][0],pCurrPnt[0][1],pCurrPnt[0][2]);  
  glEnd();


}








void gsv::Cuboid::DrawGL() const
{
  const Vector3d   &rPos_m = GetPosition_m();
  const RGB        &rColor = GetRGB();
  const gsv::Vector3d  &rScale=GetScale();
  const gsv::Vector3d  &rShift=GetShift_bsc();
  
  glTranslatef(COORDS3(rPos_m));  
  glRotatef(GetAng_Yaw_deg(), 0.0f, 0.0f, 1.0f);
  glRotatef(GetAng_Pitch_deg(), 0.0f, 1.0f, 0.0f);
  glRotatef(GetAng_Roll_deg(), 1.0f, 0.0f, 0.0f);
  glScalef(COORDS3(rScale));  
  glTranslatef(COORDS3(rShift));

  glColor3ub(rColor.GetColor_Red(),rColor.GetColor_Green(),rColor.GetColor_Blue());  

  switch (GetObjType()) {
    case gsv::CuboidType:  DrawCuboid(); break;
    case gsv::PrismType:   DrawPrism(); break;
    case gsv::PyramidType: DrawPyramid(); break;
    case gsv::SphereType:    DrawSphere(); break;
    case gsv::HemisphereType:  DrawHemisphere(); break;
  }

  glTranslatef(OPO_COORDS3(rShift));   
  glScalef(REV_COORDS3(rScale));
}





#define DISP_COOR( vec, index ) setw(4) << vec[index] << " "
#define DISP_VECT( vec ) DISP_COOR(vec,0) <<  DISP_COOR(vec,1) <<  DISP_COOR(vec,2)

std::string gsv::Cuboid::BuildCmd() const
{
  ostringstream  OStrm;

  OStrm << "UpdateObj "// <<  DISP_VECT(GetSize_m()) << "  "
	<< DISP_VECT(GetPosition_m()) << "  "
	<< GetAng_Roll_deg() << " "
	<< GetAng_Pitch_deg() << " "
	<< GetAng_Yaw_deg() << "  "
	<< GetColorRGB();
  return OStrm.str();
}
