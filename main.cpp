#include <iostream>
#include "Signal.hpp"
#include "Subscriber.hpp"
#include "Scheduler.hpp"

int main()
{
    //initialize scheduler
    Scheduler itsScheduler;

    //initialze and resigster subscribers
    auto s1 = std::make_shared<Subscriber>(Signal::Kind::KIND1);
    auto s3a = std::make_shared<Subscriber>(Signal::Kind::KIND2);
    auto s3b = std::make_shared<Subscriber>(Signal::Kind::KIND3);

    itsScheduler.registerSubscriber(s1);
    itsScheduler.registerSubscriber(s3a);
    itsScheduler.registerSubscriber(s3b);

    s3a.reset();

    // generate some signals
    std::vector<std::pair<Signal::Kind, std::string>> signalDataList = {
        {Signal::Kind::KIND1, "Signal0"},
        {Signal::Kind::KIND2, "Signal1"},
        {Signal::Kind::KIND3, "Signal2"},
        {Signal::Kind::KIND2, "Signal3"},
        {Signal::Kind::KIND3, "Signal4"},
        {Signal::Kind::KIND1, "Signal5"},
    }; 

    for (const auto& signalData : signalDataList){
        itsScheduler.takeSignal(std::make_unique<Signal>(signalData.first,signalData.second));
    }   

    itsScheduler.dispatchSignals();
    //Subscriber itsSubscriber(Signal::Kind::KIND1);
    //Signal itsSignal(Signal::Kind::KIND1," Signal kind 1");

    //std::cout<< itsSignal << std::endl;
    //std::cout<<" hello world "<< std::endl;

    return 0;  

}