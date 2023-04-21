#include "keyHandler.hpp"


int main(void)
{
    //initializing sodium library
    if (sodium_init() < 0) {
        /* panic! the library couldn't be initialized; it is not safe to use */
    }

//     PUBLICKEY a_publicKey[PUBLICKEYBYTES];
//     SECRETKEY a_secretKey[SECRETKEYBYTES];
//     NONCE nonce[crypto_box_NONCEBYTES];

//     PUBLICKEY b_publicKey[PUBLICKEYBYTES];
//     SECRETKEY b_secretKey[SECRETKEYBYTES];

//     KeyHandler keyHandler;
//     keyHandler.get_keys(a_publicKey,a_secretKey);
//     keyHandler.get_keys(b_publicKey,b_secretKey);

//     std::cout<<"generatedKeys"<<std::endl;

//     for(int i=0;i<crypto_box_PUBLICKEYBYTES;i++)
//     {
//         //std::cout<<publicKey[i];
//         printf("%2.2x",a_publicKey[i]);
//     }
//     std::cout<<std::endl;

//     for(int i=0;i<crypto_box_SECRETKEYBYTES;i++){
//         //std::cout<<secretKey[i];
//         printf("%2.2x",a_secretKey[i]);
//     }
//     std::cout<<std::endl;

//     for(int i=0;i<crypto_box_PUBLICKEYBYTES;i++)
//     {
//         //std::cout<<publicKey[i];
//         printf("%2.2x",b_publicKey[i]);
//     }
//     std::cout<<std::endl;

//     for(int i=0;i<crypto_box_SECRETKEYBYTES;i++){
//         //std::cout<<secretKey[i];
//         printf("%2.2x",b_secretKey[i]);
//     }
//     std::cout<<std::endl;

//     //generating nonce value
//     randombytes_buf(nonce,sizeof(nonce));
//     unsigned char ciphertext[CIPHERTEXT_LEN];

//     std::cout<<"Message before encrypting"<<MESSAGE<<std::endl;

//     if(crypto_box_easy(ciphertext, MESSAGE, MESSAGE_LEN,nonce,b_publicKey,a_secretKey)!=0){
//         std::cout<<"error<<"<<std::endl;
//     }

//     std::cout<<ciphertext<<std::endl;


//     unsigned char decrypted[MESSAGE_LEN];
//     if(crypto_box_open_easy(decrypted, ciphertext, CIPHERTEXT_LEN,nonce,a_publicKey,b_secretKey)!=0){
//         std::cout<<"error while decrypting the message"<<std::endl;
//     }
//     std::cout<<"decrypted message after bob recieved the message"<<std::endl;

//     for(int i=0;i<MESSAGE_LEN;i++){
//         std::cout<<decrypted[i];
// }
//     std::cout<<std::endl;
//     return 0;
}