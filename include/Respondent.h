#ifndef RESPONDENT_H
#define RESPONDENT_H
#include "Employee.h"
#include "Rank.h"

class CallHandler;
class Respondent : public Employee
{
    public:
        Respondent(CallHandler *  handler);

    protected:

    private:
};

#endif // RESPONDENT_H
