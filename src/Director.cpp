#include "Director.h"

Director::Director(CallHandler * handler) : Employee(handler)
{
    Employee::m_rank = Rank::Director;
}
