#ifndef _illegalParameterValue
#define _illegalParameterValue
#include <string>
#include <iostream>
class illegalParameterValue{
    public:
        illegalParameterValue(std::string msg) { this->msg = msg; }
        void outputMessage(){ std::cout << msg << std::endl; }
    private:
        std::string msg;
};
#endif

#ifndef _stackError
#define _stackError
class stackError{
    public:
        stackError(std::string msg) { this->msg = msg; }
        void outputMessage(){ std::cout << msg << std::endl; }
    private:
        std::string msg;
};
#endif