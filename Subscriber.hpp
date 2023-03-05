#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <vector>
#include "Signal.hpp"


class Subscriber{

public:
    Subscriber(Signal::Kind kind_); //important to know later which signal to accept
    ~Subscriber();
    inline Signal::Kind getSignalKind() const{ return _kind;}
    void processSignal(std::shared_ptr<Signal> signal_); //To be able to dispatch signals to multiple subscriber objects, shared ownership via std::shared_ptr is required other unique_ptr

private:
    const Signal::Kind _kind;
    std::vector<std::shared_ptr<Signal>> signalHistoryContainer; // 

};

#endif