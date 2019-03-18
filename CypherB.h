/*************************************************************************************************************
CIS 22C
Lab 5: This program provides the implementation of the base class Encrypted and derived classes CypherA and
       CypherB for the main function, which receives the a file name of the file containing the encrypted
       message as input and outputs the decrypted message for each method of decryption.
Author: Vincent Nguyen
Date: 3/8/19
*************************************************************************************************************/
#ifndef CypherB_h
#define CypherB_h

#include "Encrypted.h"
#include <string>

/*************************************************************************************************************
class CypherB, derived from Encrypted:
- "CypherB" is a constructor that calls Encrypted and passes its file name and max byte size parameters
- "~CypherB" is a destructor
- "decode" decrypts the message by rotational cypher with shift of 4 backwards
- the variable "ascii" is used to check for values where simply subtracting by 4 will not correctly decrypt a
  character
*************************************************************************************************************/
class CypherB : public Encrypted {
    private:
        const int shift = 4;
    public:
        CypherB(string name, int size) : Encrypted(name, size) {};
        ~CypherB(){};
        void decode() {
            int ascii;
            for (int i = 0; i <strlen(message); i++)
                if (isalpha(message[i]))
                {
                    ascii = message[i];
                    switch(ascii)
                    {
                        case 96:
                            message[i] = 'v';
                            continue;
                        case 97:
                            message[i] = 'w';
                            continue;
                        case 98:
                            message[i] = 'x';
                            continue;
                        case 99:
                            message[i] = 'y';
                            continue;
                        case 100:
                            message[i] = 'z';
                            continue;
                        default:
                            message[i] -= shift;
                    }
                }
                else
                    continue;
        }
};

#endif

/**
Sample output:
Enter file name to be decoded with algorithm A: Encrypted.txt
Decoded message:
encryption is the name given to the process of applying an algorithm to a message, which scrambles the data in it-making it very difficult and time consuming, if not practically impossible, to deduce the original given only the encoded data. inputs to the algorithm typically involve additional secret data called keys, which prevents the message from being decoded-even if the algorithm is publicly known.


Enter file name to be decoded with algorithm B: EncB.txt
Decoded message:
in a symmetric encryption algorithm, both the sender and the recipient use the same key (known as the secret key) to encrypt and decrypt the message. one `ery basic symmetric encryption algorithm is known as the rotational cipher. in this algorithm, the sender simply "adds" the key to each character of the cleartext message to form the ciphertext. for example, if the key is 2, "a" would become "c", "b" would become "d, and so on. the recipient would then decrypt the message by "subtracting" the key from each character of the ciphertext to obtain the original message.

Process returned 0 (0x0)   execution time : 10.339 s
Press any key to continue.
*/
