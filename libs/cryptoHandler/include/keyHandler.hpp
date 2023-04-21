#ifndef KEYHANDLER_HPP
#define KEYHANDLER_HPP
extern "C" {

#include <sodium.h>

}
#include<iostream>

extern "C" int _crypto_aead_aegis256_pick_best_implementation();
extern "C" int _crypto_aead_aegis128l_pick_best_implementation();

typedef unsigned char PUBLICKEY;
typedef unsigned char SECRETKEY;
typedef unsigned char NONCE;
typedef unsigned char CIPHERTEXT;
// #define MESSAGE (const unsigned char *) "test"
// #define MESSAGE_LEN 4
// #define CIPHERTEXT_LEN (crypto_box_MACBYTES + MESSAGE_LEN)

class CryptoHandler {
    private:
      bool flag;
    public :
        CryptoHandler(){
            if(flag == false) {
            	if (sodium_init() < 0) {
                /* panic! the library couldn't be initialized; it is not safe to use */
            }
            flag=true;
        }
        }
        int get_keys_and_nonce(PUBLICKEY* publicKey,SECRETKEY* secretKey,NONCE* nonce);

        void encryptMessage(PUBLICKEY* publicKey,NONCE* nonce, SECRETKEY* secretKey,std::string message,CIPHERTEXT* cipherText);
        std::string decryptMessage(PUBLICKEY* publicKey,NONCE* nonce,SECRETKEY* secretKey,uint32_t messageLength,CIPHERTEXT* cipherText);

        static const uint32_t PUBLICKEYBYTES = crypto_box_PUBLICKEYBYTES;
        static const uint32_t SECRETKEYBYTES = crypto_box_SECRETKEYBYTES;
        static const uint32_t NONCEBYTES =  crypto_box_NONCEBYTES;
        static const uint32_t CIPHERTEXTBYTES =  crypto_box_MACBYTES;

};

#endif