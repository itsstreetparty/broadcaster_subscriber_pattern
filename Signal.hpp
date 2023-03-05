#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>
#include <string>


class Signal {
    public:

        enum class Kind{
            KIND1,
            KIND2,
            KIND3,
        };

        Signal(Signal const&) = delete;// avoid multiple owners of the resource
        Signal(Signal::Kind type_, std::string message_);
        ~Signal();
        Signal& operator = (Signal const&) = delete; //avoid multiple owners of the resource
        inline long long unsigned int getID() const{ return _id;} //could be use with a register or for a log file
        inline Signal::Kind getKind() const{ return _kind;} // useful for the subscriber
        inline std::string getMessage() const {return _message;} // this could be the data you want to transfer 

    private:
        const long long unsigned int _id;
        const Signal::Kind _kind;
        const std::string _message;       

};

std::ostream& operator << (std::ostream& os, const Signal& signal);
std::ostream& operator << (std::ostream& os, const Signal::Kind& _kind);

#endif