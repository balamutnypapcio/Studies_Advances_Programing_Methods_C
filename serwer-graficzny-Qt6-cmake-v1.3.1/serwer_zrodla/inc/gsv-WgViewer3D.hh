#ifndef SGV_WGVIEWER3D_HH
#define SGV_WGVIEWER3D_HH

#include <QGLViewer/qglviewer.h>
#include <QTimer>
#include <string>
#include "gsv-BufferedScene.hh"
#include "gsv-AppParams.hh"
#include "gsv-Vector3f.hh"
#include <cassert>

/*!
 * \file
 * \brief Widget wizualizujący obiekty 3D
 *
 * Zawiera definicję klasy wizualizującej obiekty 
 */


namespace gsv {
/*!
 * \brief Widget wizualizujący obiekty 3D
 */
 class WgViewer3D : public QGLViewer
 {
    Q_OBJECT



   static WgViewer3D  *_pViewer;

   
   /*!
    * \brief Aktuwuje okresowe sprawdzanie zawartości sceny
    *
    * Aktuwuje okresowe sprawdzanie zawartości sceny.
    * W przypadku jej zmiany, wymusza jej odrysowanie.
    */
   QTimer   _Timer;

   /*!
    * \brief Wskaźnik na scenę, której obiekty mają być wizualizowane.
    */
   gsv::BufferedScene  *_pBuffScn = nullptr;

   /*!
    * \brief Draw mode: FILL or LINES
    */
   gsv::DrawMode  _DrawMode = DM_Fill;
   /*!
    * \brief
    */
   bool           _ShowLocalCrds = false;
   /*!
    * \brief
    */
   gsv::Vector3f         _BgColor;
   /*!
    * \brief  Nazwa pliku graficznego wykorzystywanego jako tekstura tła.
    */
   WatchedValue<std::string>    _BgImageFileName;
   
  protected:
   virtual void draw() override;
   virtual void init() override;
   virtual QString helpString() const override;
   virtual void keyPressEvent(QKeyEvent *pEvent) override;
   
  public:
   WgViewer3D(QWidget *pParent, gsv::BufferedScene  *_pBScn);

   /*!
    * \brief
    */
   void SetDrawMode(gsv::DrawMode Mode) { _DrawMode = Mode;  SetSceneChanged(); }
   /*!
    *
    */
   gsv::DrawMode GetDrawMode() const { return _DrawMode; }
   /*!
    * \brief
    */
   void SetShowLocalCrds(bool Mode) {  _ShowLocalCrds = Mode;  SetSceneChanged(); }
   /*!
    *
    */
   bool GetShowLocalCrds() const { return _ShowLocalCrds; }
   /*!
    * \brief Access to an active viewer (modification permission)
    */
   static WgViewer3D *Use_Viewer() { return _pViewer; }
   /*!
    * \brief Access to an active viewer (read only)
    */
   static const WgViewer3D *Get_Viewer() { return _pViewer; }
   /*!
    * \brief Udostępnia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
    */
   const std::string & GetBgImageFileName() const { return _BgImageFileName.Get(); }
   /*!
    *
    */
   void SetSceneChanged() { _pBuffScn->MarkTrace0Change(); }
   /*!
    * \brief Zmienia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
    */
   void SetBgImageFileName(const std::string & rName);
   /*!
    * \brief Zmienia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
    */
   void SetBgImageFileName(const std::string && rName);

   /*!
    * \brief Zmienia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
    */
   void ResetChange_BgImageFileName() { _BgImageFileName.Reset(); }
   /*!
    * \brief Zmienia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
    */
   bool IsChanged_BgImageFileName() const { return _BgImageFileName.IsChanged(); }

   /*!
    * \brief Zmienia nazwa pliku graficznego wykorzystywanego jako tekstura tła.
    */
   bool Check_SetBgImageFileName(const char *sName);

   
   /*!
    * \brief Access to a viewer background color (read only)
    */
   const Vector3f & GetBgColor() const { return _BgColor; }
   /*!
    * \brief Access to a viewer background color (modification permission)
    */
   Vector3f & UseBgColor() { return _BgColor; }
   /*!
    *  \brief Access to a RGB coordinated of a viewer background color (read only)
    */
   float GetBgColorRGB(unsigned int Idx) const { assert(Idx < 3);  return _BgColor[Idx]; }

 public slots:
  /*!
   * \brief Okresowa aktualizacja sceny
   */
   void PeriodicSceneUpdate();
 };

 inline
 WgViewer3D *Use_Viewer() { return gsv::WgViewer3D::Use_Viewer(); }

 inline
 const WgViewer3D *Get_Viewer() { return gsv::WgViewer3D::Use_Viewer(); }
}

#endif
