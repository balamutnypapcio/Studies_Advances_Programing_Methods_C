#ifndef MOBILEOBJ_HH
#define MOBILEOBJ_HH

#include "AbstractMobileObj.hh"
#include <mutex>

class MobileObj : public AbstractMobileObj {
private:
    std::string _Name;
    
    // Mutex do ochrony tego konkretnego obiektu
    std::mutex _AccessCtrl;

public:
    MobileObj(const std::string& Name) : _Name(Name) {}

    // Implementacja metod z interfejsu
    const std::string& GetName() const override { return _Name; }
    void SetName(const char* sName) override { _Name = sName; }

    // Metody do blokowania, wymagane przez diagram
    void Lock() { _AccessCtrl.lock(); }
    void Unlock() { _AccessCtrl.unlock(); }

    // Puste implementacje reszty metod z interfejsu
    double GetAng_Roll_deg() const override { return 0; }
    double GetAng_Pitch_deg() const override { return 0; }
    double GetAng_Yaw_deg() const override { return 0; }
    void SetAng_Roll_deg(double a) override {}
    void SetAng_Pitch_deg(double a) override {}
    void SetAng_Yaw_deg(double a) override {}
    const Vector3D& GetPositoin_m() const override { static Vector3D v; return v; }
    void SetPosition_m(const Vector3D &rPos) override {}
};

#endif