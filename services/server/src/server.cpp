#include "server.hpp"

Server::Server(){
    int res = cryptoHandler.get_keys_and_nonce(publicKey,secretKey,nonce);
	if(res == 0){
		std::cout<<"Service side public key recieved"<<std::endl;
	}
	else
		std::cout<<"Service side public key error"<<std::endl;
};
Server::~Server(){};
void Server::exchangeKey(const std::shared_ptr<CommonAPI::ClientId> _client,
                         std::string _clientKey, exchangeKeyReply_t _reply) {

 std::copy(_clientKey.begin(),_clientKey.end(),clientPublicKey);
	std::cout<<"printing client key"<<std::endl;
	for(int i=0;i<crypto_box_PUBLICKEYBYTES;i++)
    {
        //std::cout<<publicKey[i];
        printf("%2.2x",clientPublicKey[i]);
    }
	std::string str(publicKey, publicKey+sizeof publicKey/sizeof publicKey[0]);
	_reply(str);
}

void Server::sendMessage(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _nonce, std::string _cipherText,uint32_t messageLength, sendMessageReply_t _reply){
	std::cout<<"message recieved"<<std::endl;
	NONCE nonce[CryptoHandler::NONCEBYTES];
	CIPHERTEXT cipherText[CryptoHandler::CIPHERTEXTBYTES+messageLength];
	//std::string message;
	std::cout<<_cipherText<<std::endl;
	std::copy(_cipherText.begin(),_cipherText.end(),cipherText);

	for(int i=0; i <= CryptoHandler::CIPHERTEXTBYTES+messageLength ; i++)
	{
		std::cout<<cipherText[i];
	}
	std::cout<<std::endl;
	std::copy(_nonce.begin(),_nonce.end(),nonce);
	std::cout<<"decrypting client message"<<std::endl;
	std::string messagedecrypted = cryptoHandler.decryptMessage(clientPublicKey,nonce,secretKey,messageLength,cipherText);

	std::cout<<"message from client "<<messagedecrypted<<std::endl;

	_reply("message from server","hahahah");
}