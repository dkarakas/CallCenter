#include "Question.h"

Question::Question()
{
    //ctor
}

Question::~Question()
{
    //dtor
}

int main(){
    std::shared_ptr<Caller> caller1 = std::make_shared<Caller>(0,"Caller1");
    std::shared_ptr<Caller> caller2 = std::make_shared<Caller>(1,"Caller2");
    std::optional<Call> call1(caller1);
    call1->printCaller();
    CallHandler ch;
    //ch.dispatchCall(std::move(call1));

    return 0;
}
