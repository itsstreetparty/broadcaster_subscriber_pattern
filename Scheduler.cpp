#include "Scheduler.hpp"


void warnNoSubscriber(Signal::Kind kind_)
{
    throw std::runtime_error("No registered subscriber for signal kind " +
                             std::to_string(static_cast<int>(kind_)));
}

void Scheduler::registerSubscriber (std::shared_ptr<Subscriber> subscriber_){
    SubscriberRegistry.insert({subscriber_->getSignalKind(), subscriber_});
}

void Scheduler::takeSignal (std::unique_ptr<Signal> signal_){
    _queue.push_back(std::move(signal_));    
}


void Scheduler::dispatchSignals ()
{
    while (!_queue.empty())
    {
        try
        {
            dispatchSingleSignal(); // here _queue has to decrease 
        }
        catch(const std::runtime_error& err)
        {
            std::cerr << err.what() << std::endl;
        }
    }
}

void Scheduler::dispatchSingleSignal(){
    std::shared_ptr<Signal> oSignal   =   std::move(    *_queue.begin()    ); // conversion oEvent unique_ptr -> shared_ptr via std::move

    if (oSignal.get()){
        _queue.pop_front();
    }

    if( SubscriberRegistry.count(    oSignal->getKind()  ) ){
        std::pair<cRegistryIterator, cRegistryIterator> result = SubscriberRegistry.equal_range( oSignal->getKind()   );
        for (cRegistryIterator it=result.first; it!=result.second;it++){
            if( auto spt=it->second.lock()   ){ // convert weak ptr to share ptr and check if there is 
                //it->second.consumeEvent( oEvent);
                spt->processSignal( oSignal);
            }else{
                warnNoSubscriber(oSignal->getKind());
            }
            //it->second->consumeEvent( oEvent);
        }
    }else{
        warnNoSubscriber(oSignal->getKind());
    }
        /*
        The std::weak_ptr class is used to store a non-owning ("weak") reference to an object that is managed by a std::shared_ptr. 
        The std::weak_ptr does not increment the reference count of the object, but it can be used to check whether the object is still alive and to obtain a std::shared_ptr to the object.
        To obtain a std::shared_ptr to the object from a std::weak_ptr, you can use the lock() function. 
        The lock() function returns a std::shared_ptr that points to the same object that the std::weak_ptr points to, or it returns an empty std::shared_ptr if the object has been destroyed.
        */



}

