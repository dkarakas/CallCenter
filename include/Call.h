#ifndef CALL_H
#define CALL_H
#include "Rank.h"
#include "Caller.h"
#include <string>
#include <iostream>
#include <memory>

class Call
{
    public:
        Call(std::shared_ptr<Caller>  caller);
        Call(Call&& call);
        Call& operator=(Call&& call);
        void setRank(Rank rank);
        Rank getRank();
        Rank incrRank();
        void reply(std::string str);
        void printCaller();
        void disconnect();
    protected:

    private:
        Rank m_rank;
        std::shared_ptr<Caller> m_caller;
};

#endif // CALL_H
