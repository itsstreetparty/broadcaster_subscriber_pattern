#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Signal.hpp"
#include "Subscriber.hpp"
#include <deque>
#include <memory>
#include <map>

class Scheduler{
    public:
        void registerSubscriber (std::shared_ptr<Subscriber> subscriber_);
        void takeSignal (std::unique_ptr<Signal> signal_); // take ownership of the signal 
        void dispatchSignals ();
        void dispatchSingleSignal ();
        typedef std::multimap<Signal::Kind, std::weak_ptr<Subscriber>>::iterator cRegistryIterator;

    private:
        std::deque< std::unique_ptr<Signal>   > _queue; // accumulate signals
        //std::multimap<Event::Type, Consumer*> cRegistry;
        std::multimap<Signal::Kind, std::weak_ptr<Subscriber>> SubscriberRegistry;




};



#endif