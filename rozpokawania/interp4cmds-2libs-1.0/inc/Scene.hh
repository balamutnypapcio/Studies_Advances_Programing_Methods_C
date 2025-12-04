// Plik: inc/Scene.hh

#ifndef SCENE_HH
#define SCENE_HH

#include "AbstractScene.hh"
#include "MobileObj.hh"
#include <map>
#include <string>
#include <memory> 

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
private:
    std::map<std::string, std::shared_ptr<MobileObj>> _ObjectMap;
    std::mutex _ScnMutex;

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
     * \brief Dodaje nowy obiekt mobilny do sceny za pomocą shared_ptr.
     *
     */
    void AddMobileObj(std::shared_ptr<AbstractMobileObj> pMobObj) override;
};

#endif