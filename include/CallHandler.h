#ifndef CALLHANDLER_H
#define CALLHANDLER_H
#include "Call.h"
#include "Employee.h"
#include "Constants.h"
#include <optional>
#include <vector>

class CallHandler
{
    public:
        CallHandler();
        std::optional<Employee> getHandlerForCall(std::optional<Call> call);
        void dispatchCall(std::shared_ptr<Caller> caller);
        void dispatchCall(std::optional<Call> call);
        bool assignCall(Employee* emp);

    protected:

    private:
        std::vector<std::vector<std::optional<Employee>>> m_employeeLvls;
        std::vector<std::vector<std::optional<Call>>> m_callQueue;
};

#endif // CALLHANDLER_H
