#include "Signal.hpp"

namespace Record{
    long long unsigned int getNextId(){
    static size_t last_id = 0;
    return last_id++;
    } 
}//Record


Signal::Signal(Signal::Kind kind_, std::string message_): _id(Record::getNextId()),_kind(kind_),_message(message_)
{
    std::cout << "Signal "<<_id << " created!"<< std::endl;
}

Signal::~Signal(){
    std::cout << "Signal "<< _id << " destroyed!"<< std::endl;
}

std::ostream& operator << (std::ostream& os, const Signal& signal){
    os << "Signal(id=" << signal.getID()<< ", "
       << "kind=" << signal.getKind() << ", "
       << "message=" << signal.getMessage() << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const Signal::Kind& _kind)
{
   os << static_cast<int>(_kind)+1;
   return os;
}