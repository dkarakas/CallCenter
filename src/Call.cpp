#include "Call.h"

Call::Call(std::shared_ptr<Caller> caller) : m_rank(Rank::Respondent), m_caller(caller)
{

}


Call::Call(Call&& call) : m_rank(call.m_rank), m_caller(call.m_caller)
{
    call.m_caller = nullptr;
}

Call& Call::operator=(Call&& call){
    m_rank = call.m_rank;
    m_caller = call.m_caller;
    call.m_caller = nullptr;
    return *this;
}

void Call::setRank(Rank rank){
    m_rank = rank;
}

Rank Call::getRank(){
    return m_rank;
}

Rank Call::incrRank(){
    if(m_rank == Rank::Respondent){
        m_rank = Rank::Manager;
    }else{
        m_rank = Rank::Director;
    }
    return m_rank;
}

void Call::printCaller(){
    m_caller->print();
}

void Call::reply(std::string str){
    std::cout << "Reply: " << str << std::endl;
}

void Call::disconnect(){
    std::cout << "Thank you for calling" << std::endl;
}
