// Plik: src/Scene.cpp

#include "Scene.hh"

/*!
 * \brief Implementacja metody wyszukującej obiekt.
 *
 * Na tym etapie rozwoju projektu, scena nie przechowuje jeszcze
 * żadnych obiektów, więc ta metoda zawsze zwraca pusty wskaźnik.
 */
AbstractMobileObj* Scene::FindMobileObj(const char *sName) {
    // W przyszłości tutaj będzie logika przeszukiwania kontenera z obiektami.
    return nullptr;
}

/*!
 * \brief Implementacja metody dodającej obiekt.
 *
 * Na tym etapie rozwoju projektu, scena nie przechowuje jeszcze
 * żadnych obiektów, więc ta metoda po prostu ignoruje przekazany wskaźnik.
 */
void Scene::AddMobileObj(AbstractMobileObj *pMobObj) {
    // W przyszłości tutaj będzie logika dodawania obiektu do kontenera.
    // Należy pamiętać o zarządzaniu pamięcią (np. używając std::unique_ptr).
}