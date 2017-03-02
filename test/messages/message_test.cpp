#include <gmock/gmock.h>
#include <siminusminus/messages/message.hpp>
#include <iostream>

namespace testing
{
    class MessageTestingA{
    public:

        void whoAmI(){std::cout << "I'm A" << std::endl;}
        void showInteger(int number){std::cout << number << std::endl;}
    };

    class MessageTestingB{
    public:
        void whoAmI(){std::cout << "I'm B" << std::endl;}
    };
}
using namespace ::testing;

TEST(Message, voidMessage)
{
    MessageTestingA a;
    MessageTestingB b;

    void (MessageTestingB::* function)();
    function = &MessageTestingB::whoAmI;

    cmm::messages::Message<MessageTestingA, MessageTestingB, void (MessageTestingB::*) ()> message(a, b, function);
    message.send();
}

TEST(Message, messageWithArguments)
{
    MessageTestingA a;
    MessageTestingB b;

    void (MessageTestingA::* function)(int);
    function = &MessageTestingA::showInteger;

    cmm::messages::Message<MessageTestingB, MessageTestingA, void (MessageTestingA::*) (int), int> message(b, a, function);
    message.send(58);
}