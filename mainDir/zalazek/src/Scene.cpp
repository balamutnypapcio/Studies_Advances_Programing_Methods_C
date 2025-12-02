// Plik: src/Scene.cpp

#include "Scene.hh"

/*!
 * \brief Implementacja metody wyszukującej obiekt.
 *
 * Na tym etapie rozwoju projektu, scena nie przechowuje jeszcze
 * żadnych obiektów, więc ta metoda zawsze zwraca pusty wskaźnik.
 */
AbstractMobileObj* Scene::FindMobileObj(const char *sName) {
    std::lock_guard<std::mutex> lock(_ScnMutex);
    auto it = _ObjectMap.find(sName);
    if (it == _ObjectMap.end()) {
        return nullptr;
    }
    return it->second.get();
}

/*!
 * \brief Implementacja metody dodającej obiekt.
 *
 * Na tym etapie rozwoju projektu, scena nie przechowuje jeszcze
 * żadnych obiektów, więc ta metoda po prostu ignoruje przekazany wskaźnik.
 */
void Scene::AddMobileObj(std::shared_ptr<AbstractMobileObj> pMobObj) {
    std::shared_ptr<MobileObj> pCastedObj = std::dynamic_pointer_cast<MobileObj>(pMobObj);
    if (pCastedObj) {
        std::lock_guard<std::mutex> lock(_ScnMutex);
        _ObjectMap[pCastedObj->GetName()] = pCastedObj;
    }
}

