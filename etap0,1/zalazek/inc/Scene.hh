// Plik: inc/Scene.hh

#ifndef SCENE_HH
#define SCENE_HH

#include "AbstractScene.hh"

/*!
 * \brief Atrapa klasy sceny.
 *
 * Implementuje interfejs AbstractScene, ale na tym etapie rozwoju
 * programu jej metody są puste. Jest to wystarczające, aby spełnić
 * wymagania sygnatury metody ExecCmd.
 * W przyszłych etapach klasa ta będzie rozbudowana o faktyczne
 * zarządzanie kolekcją obiektów mobilnych.
 */
class Scene : public AbstractScene {
public:
    /*!
     * \brief Konstruktor domyślny.
     */
    Scene() = default;

    /*!
     * \brief Wyszukuje obiekt o podanej nazwie.
     * \return Zawsze zwraca nullptr w tej implementacji.
     */
    AbstractMobileObj* FindMobileObj(const char *sName) override;

    /*!
     * \brief Dodaje nowy obiekt mobilny do sceny.
     *        W tej implementacji nic nie robi.
     */
    void AddMobileObj(AbstractMobileObj *pMobObj) override;
};

#endif