#include "CallHandler.h"
#include "Respondent.h"
#include "Director.h"
#include "Manager.h"
#include <iostream>

CallHandler::CallHandler()
{
    //m_employeeLvls.push_back(std::vector<std::optional<Employee>>());
    //m_employeeLvls.push_back(std::vector<std::optional<Employee>>());
    //m_employeeLvls.push_back(std::vector<std::optional<Employee>>());

    //for(int i = 0; i < NUM_RESPONDENTS; i++){
    //    m_employeeLvls[(int) Rank::Respondent].push_back( std::move(Respondent(this)));
    //}

    //for(int i = 0; i < NUM_MANAGERS; i++){
    //    m_employeeLvls[(int) Rank::Manager].push_back( std::move(Manager(std::shared_ptr<CallHandler>(this))));
    //}

    //for(int i = 0; i < NUM_DIRECTORS; i++){
    //    m_employeeLvls[(int) Rank::Director].push_back( std::move(Director(std::shared_ptr<CallHandler>(this))));
    //}
}

std::optional<Employee> CallHandler::getHandlerForCall(std::optional<Call> call){
    return std::move(m_employeeLvls[0][0]);
    for(int lvl = (int) call->getRank(); lvl < MAX_LVL; lvl++){
        for(int i = 0; i < (int) m_employeeLvls[lvl].size(); i++){
            if(m_employeeLvls[lvl][i]->isFree()){
                return std::move(m_employeeLvls[lvl][i]);
            }
        }
    }
    std::optional<Employee> emp;
    return emp;
}

void CallHandler::dispatchCall(std::shared_ptr<Caller> caller){
    Call call(caller);
    dispatchCall(std::move(call));
}

void CallHandler::dispatchCall(std::optional<Call> call){
    std::optional<Employee> emp = getHandlerForCall(std::move(call));
    std::cout << "test" << std::endl;
    //if(emp.has_value()){
    //    emp->receiveCall(std::move(call));
    //}else{
    //    call->reply("Wait for somebody to became available");
    //    m_callQueue[(int) call->getRank()].push_back(std::move(call));
    //}
}

bool CallHandler::assignCall(Employee * emp){
    for(int r = (int) emp->getRank(); r >= 0; r--){
        if(m_callQueue[r].size() > 0){
            emp->receiveCall(std::move(m_callQueue[r][0]));
            m_callQueue.erase(m_callQueue.begin());
            return true;
        }
    }
    return false;
}
