#include "Caller.h"

Caller::Caller(int id, std::string name) : m_userId(id), m_name(name)
{
}


Caller::Caller(const Caller& caller){
    m_userId = caller.m_userId;
    m_name = caller.m_name;
}

void Caller::print(){
    std::cout << "Caller(" << m_userId << "): " << m_name << std::endl;
}
