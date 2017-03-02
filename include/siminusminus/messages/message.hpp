#ifndef SIMINUSMINUS_MESSAGES_MESSAGE_HPP
#define SIMINUSMINUS_MESSAGES_MESSAGE_HPP

#include <siminusminus/utils/debugutilities.hpp>

namespace cmm {
namespace messages {

/**
* \ingroup messages
* \brief Simple message class
*
* With this class you could send messages from one entity to another one.
*/
template <typename Transmitter, typename Receiver, typename Function, typename... Args>
class Message
{
public:

    /**
    * Default constructor that will create a empty message.
    */
    Message() : _transmitter(nullptr), _receiver(nullptr), _function(nullptr){}

    /**
    * Constructor that will create a message with a transmitter, a receiver and a function.
    * param transmitter: class that sends the message.
    * param receiver: class that receive the message.
    * param function: function to call on the receiver class.
    */
    Message(Transmitter& transmitter,Receiver& receiver, const Function& function): 
            _transmitter(transmitter),
            _receiver(receiver),
            _function(function) 
            {
                // utils::DebugUtilities::log("+ Created Message");
            }

    /**
    * We'll call to the function given from the receiver object.
    * param args: arguments that you'll pass to the function.
    */
    void send(Args... args)
    {
        (_receiver.*_function) (args...);
    }


private:
    Transmitter _transmitter;
    Receiver _receiver;
    const Function _function;

}; // class Message                                                                 

} // namespace messages
} // namespace cmm

#endif // SIMINUSMINUS_MESSAGES_MESSAGE_HPP