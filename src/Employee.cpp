#include "Employee.h"
#include "CallHandler.h"

Employee::Employee(CallHandler * callHandler){
    m_callHandler = callHandler;
}

Employee::Employee(Employee&& emp){
        m_curCall = std::move(emp.m_curCall);
        m_callHandler = emp.m_callHandler;
        //emp.m_curCall.reset();
}


Employee& Employee::operator=(Employee&& emp){
        m_curCall = std::move(emp.m_curCall);
        m_callHandler = emp.m_callHandler;
        return *this;
}

void Employee::receiveCall(std::optional<Call> call){
    m_curCall.reset();
    m_curCall = std::move(call);
}

void Employee::callCompleted(){
    if(m_curCall.has_value()){
        m_curCall->disconnect();
        m_curCall.reset();
    }
    assignNewCall();
}

void Employee::escalateAndAssign(){
    if(m_curCall.has_value()){
        m_curCall->incrRank();
        m_callHandler->dispatchCall(std::move(m_curCall));
        m_curCall.reset();
    }

    assignNewCall();
}

bool Employee::assignNewCall(){
    if(!isFree()){
        return false;
    }
    return m_callHandler->assignCall(this);
}

bool Employee::isFree(){
    return m_curCall.has_value();
}

Rank Employee::getRank(){
    return m_rank;
}
