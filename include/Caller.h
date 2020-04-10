#ifndef CALLER_H
#define CALLER_H
#include "string"
#include <iostream>

class Caller
{
    public:
        Caller(int id, std::string name);
        Caller(const Caller& caller1);
        void print();
    protected:

    private:
        std::string m_name;
        int m_userId;
};

#endif // CALLER_H
