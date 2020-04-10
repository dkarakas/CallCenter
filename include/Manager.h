#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
#include "CallHandler.h"
#include "Rank.h"

class Manager : public Employee
{
    public:
        Manager(CallHandler * handler);

    protected:

    private:
};

#endif // MANAGER_H
