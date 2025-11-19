#ifndef COMCHANNEL_HH
#define COMCHANNEL_HH

#include "AbstractComChannel.hh"
#include <string>

class ComChannel : public AbstractComChannel {
    int _socket = -1;
    std::mutex _access_mutex;

public:
    ComChannel() = default;
    ~ComChannel();

    bool Connect(const std::string& host, int port);
    void Disconnect();
    bool Send(const std::string& msg) const override;

    // Implementacja metod z klasy abstrakcyjnej
    void Init(int Socket) override { _socket = Socket; }
    int GetSocket() const override { return _socket; }
    void LockAccess() override { _access_mutex.lock(); }
    void UnlockAccess() override { _access_mutex.unlock(); }
    std::mutex& UseGuard() override { return _access_mutex; }
};

#endif