#include "client.hpp"
#include <unistd.h>

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    std::shared_ptr<v1_0::secureMessageTransfer::ServerProxy<>> proxy = runtime->buildProxy<v1_0::secureMessageTransfer::ServerProxy>("local","test");

    std::cout<<"checking availability"<<std::endl;

    while(!proxy->isAvailable())
    {
        usleep(10);
    }

    std::cout<<"server available"<<std::endl;

    CommonAPI::CallStatus callStatus;
    // std::string serverKey;

    // proxy->exchangeKey("clientKey",callStatus,serverKey);

    Client client;
    client.exchangeKey(proxy,callStatus);
    std::string message{"hello world"};
    client.sendMessage(proxy,callStatus,message);

   // std::cout<<"server key = "<<serverKey<<std::endl;
    
}