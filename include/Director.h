#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Employee.h"
#include "Rank.h"

class CallHandler;
class Director : public Employee
{
    public:
        Director(CallHandler* handler);
    protected:

    private:
};

#endif // DIRECTOR_H
