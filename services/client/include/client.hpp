#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <iostream>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/secureMessageTransfer/ServerProxy.hpp>
#include <keyHandler.hpp>

class Client {
    public:
        Client();
        ~Client();

    void exchangeKey(std::shared_ptr<v1_0::secureMessageTransfer::ServerProxy<>> proxy, CommonAPI::CallStatus callStatus);
    void sendMessage(std::shared_ptr<v1_0::secureMessageTransfer::ServerProxy<>> proxy, CommonAPI::CallStatus callStatus,std::string message);
    
    private:
    PUBLICKEY publicKey[CryptoHandler::PUBLICKEYBYTES];
	SECRETKEY secretKey[CryptoHandler::SECRETKEYBYTES];
    NONCE nonce[CryptoHandler::NONCEBYTES];
    PUBLICKEY serverPublicKey[CryptoHandler::PUBLICKEYBYTES];
	CryptoHandler cryptoHandler;
};

#endif