#ifndef _illegalParameterValue
#define _illegalParameterValue
#include <string>
class illegalParameterValue{
    public:
        illegalParameterValue(string msg) { this->msg = msg; }
        illegalParameterValue(const char * msg) { this->msg = msg; }
    private:
        string msg;
};
#endif