#include "Respondent.h"

Respondent::Respondent(CallHandler*  handler) : Employee(handler)
{
    Employee::m_rank = Rank::Respondent;
}
