#ifndef MOBILEOBJ_HH
#define MOBILEOBJ_HH

#include "AbstractMobileObj.hh"
#include <mutex>

class MobileObj : public AbstractMobileObj {
private:
    std::string _Name;
    Vector3D    _Position_m; // Pozycja w układzie rodzica
    Vector3D    _Angles_deg; // Orientacja (Roll , Pitch, Yaw)
    // Mutex do ochrony tego konkretnego obiektu
    std::mutex _AccessCtrl;

public:
    MobileObj(const std::string& Name) : _Name(Name) {
        _Position_m[0] = _Position_m[1] = _Position_m[2] = 0;
        _Angles_deg[0] = _Angles_deg[1] = _Angles_deg[2] = 0;
    }

    // Implementacja metod z interfejsu
    const std::string& GetName() const override { return _Name; }
    void SetName(const char* sName) override { _Name = sName; }
    double GetAng_Roll_deg() const override { return _Angles_deg[2]; }
    double GetAng_Pitch_deg() const override { return _Angles_deg[1]; }
    double GetAng_Yaw_deg() const override { return _Angles_deg[0]; }
    void SetAng_Roll_deg(double a) override { _Angles_deg[2] = a; }
    void SetAng_Pitch_deg(double a) override { _Angles_deg[1] = a; }
    void SetAng_Yaw_deg(double a) override { _Angles_deg[0] = a; }
    const Vector3D& GetPositoin_m() const override { return _Position_m; }
    void SetPosition_m(const Vector3D &rPos) override { _Position_m = rPos; }

    // Metody do blokowania, wymagane przez diagram
    void Lock() { _AccessCtrl.lock(); }
    void Unlock() { _AccessCtrl.unlock(); }


};

#endif