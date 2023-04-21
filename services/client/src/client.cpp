#include "client.hpp"
#include<iostream>
#include <string>
#include <unistd.h>

Client::Client(){
    cryptoHandler.get_keys_and_nonce(publicKey,secretKey,nonce);
}

Client::~Client(){}

void Client::exchangeKey(std::shared_ptr<v1_0::secureMessageTransfer::ServerProxy<>> proxy, CommonAPI::CallStatus callStatus){
    std::string serverKey;
    std::string str(publicKey, publicKey+sizeof publicKey/sizeof publicKey[0]);
    proxy->exchangeKey(str,callStatus,serverKey);

    std:copy(serverKey.begin(),serverKey.end(),serverPublicKey);

}

void Client::sendMessage(std::shared_ptr<v1_0::secureMessageTransfer::ServerProxy<>> proxy, CommonAPI::CallStatus callStatus,std::string message) {
    std::string serverNocne;
    std::string serverMessage;
    // std::string nonceString;
    // std::string cipherString;
    std::cout<<"client send message function"<<std::endl;

    CIPHERTEXT cipherText[CryptoHandler::CIPHERTEXTBYTES + message.length()];

    //encryptMessage
    cryptoHandler.encryptMessage(serverPublicKey,nonce,secretKey,message,cipherText);
    std::cout<<"encrytp message done"<<std::endl;
    // nonceString =  reinterpret_cast<char *>(nonce);
    // cipherString = reinterpret_cast<char *>(cipherText);

    std::string nonceString(nonce,nonce + sizeof nonce/sizeof nonce[0]);
    std::string cipherString(cipherText, cipherText + sizeof cipherText / sizeof cipherText[0]);
    
    for(int i=0;i<CryptoHandler::CIPHERTEXTBYTES+message.length();i++){
        std::cout<<cipherText[i];
}
    std::cout<<std::endl;
    std::cout<<cipherString<<std::endl;
    std::cout<<"message length "<<message.length()<<std::endl;
    proxy->sendMessage(nonceString,cipherString,message.length(),callStatus,serverNocne,serverMessage);

    std::cout<<serverNocne<<"   "<<serverMessage<<std::endl;
}