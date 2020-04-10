#include "Manager.h"

Manager::Manager(CallHandler* handler) : Employee(handler)
{
    Employee::m_rank = Rank::Manager;
}

