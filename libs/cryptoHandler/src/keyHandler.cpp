#include "keyHandler.hpp"
#include "string.h"

int CryptoHandler::get_keys_and_nonce(PUBLICKEY *publicKey, SECRETKEY *secretKey,NONCE* nonce) {
  int res = crypto_box_keypair(publicKey, secretKey);
  if (res == 0) {
    std::cout << "public and secret key generated" << std::endl;
  } else
    std::cout << "error while generating key pair" << std::endl;
 
  randombytes_buf(nonce, sizeof nonce);
  return res;
}

void CryptoHandler::encryptMessage(PUBLICKEY *publicKey, NONCE* nonce,SECRETKEY* secretKey,std::string message,CIPHERTEXT* cipherText){
  unsigned char messageText[message.length()];
  std::copy(message.begin(),message.end(),messageText);
  crypto_box_easy(cipherText,messageText,message.length(),nonce,publicKey,secretKey);
}

std::string CryptoHandler::decryptMessage(PUBLICKEY* publicKey,NONCE* nonce,SECRETKEY* secretKey,uint32_t messageLength,CIPHERTEXT* cipherText) {
  unsigned char messageText[messageLength];
  crypto_box_open_easy(messageText,cipherText,crypto_box_MACBYTES+messageLength,nonce,publicKey,secretKey);
  std::cout<<"decrypted message in library"<<std::endl;

  for(int i=0;i<=sizeof messageLength;i++){
        std::cout<<messageText[i];
}
    std::cout<<std::endl;
  //message = reinterpret_cast<char*>(messageText);

  std::string message(messageText,messageText + sizeof messageText / sizeof messageText[0] );

  return message;
}

int _crypto_aead_aegis256_pick_best_implementation() { return 1; }

int _crypto_aead_aegis128l_pick_best_implementation() { return 0; }