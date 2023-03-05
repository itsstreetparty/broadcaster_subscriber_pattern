#include <iostream>
#include "Subscriber.hpp"


Subscriber::Subscriber(Signal::Kind kind_): _kind(kind_){

    std::cout << " Subscriber of kind "
                << static_cast<int>(_kind) +1
                << " created "
                << std::endl;
}

Subscriber::~Subscriber(){
    std::cout << " Subscriber of kind"
                << static_cast<int>(_kind) +1 
                << " destroyed "
                << std::endl;
}

void Subscriber::processSignal(std::shared_ptr<Signal> signal_){
    if (signal_){
            std::cout << " Subscriber for signal kind "
            << static_cast<int>(_kind)
            << " processing signal "
            << *signal_
            << std::endl;
            signalHistoryContainer.emplace_back(signal_);
    }else{
        std::cout << " subscriber receive a null pointer "<< std::endl;
    }

}
