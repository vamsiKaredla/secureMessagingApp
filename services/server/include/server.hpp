#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <CommonAPI/CommonAPI.hpp>
#include <v1/secureMessageTransfer/ServerStubDefault.hpp>
#include <iostream>
#include <log4cplus/log4cplus.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include "keyHandler.hpp"

class Server: public v1_0::secureMessageTransfer::ServerStubDefault {

public:
    Server();
    ~Server();
    virtual void exchangeKey(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _clientKey, exchangeKeyReply_t _reply);
	virtual void sendMessage(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _nonce, std::string _cipherText, uint32_t messagelength, sendMessageReply_t _reply);
private:
	PUBLICKEY publicKey[CryptoHandler::PUBLICKEYBYTES];
	SECRETKEY secretKey[CryptoHandler::SECRETKEYBYTES];
	NONCE nonce[CryptoHandler::NONCEBYTES];
	PUBLICKEY clientPublicKey[CryptoHandler::PUBLICKEYBYTES];
	CryptoHandler cryptoHandler;

};

#endif