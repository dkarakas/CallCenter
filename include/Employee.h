#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Rank.h"
#include "Call.h"
#include <optional>

class CallHandler;
class Employee
{
    public:
        Employee(CallHandler * callHandler);
        Employee(Employee&& emp);
        Employee& operator=(Employee&& emp);
        void receiveCall(std::optional<Call> call);
        void callCompleted();
        void escalateAndAssign();
        bool assignNewCall();
        bool isFree();
        Rank getRank();
    protected:
        Rank m_rank;
    private:
        std::optional<Call> m_curCall;
        CallHandler* m_callHandler;
};

#endif // EMPLOYEE_H
