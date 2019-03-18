/*************************************************************************************************************
CIS 22C
Lab 5: This program provides the implementation of the base class Encrypted and derived classes CypherA and
       CypherB for the main function, which receives the a file name of the file containing the encrypted
       message as input and outputs the decrypted message for each method of decryption.
Author: Vincent Nguyen
Date: 3/8/19
*************************************************************************************************************/
#ifndef CypherA_h
#define CypherA_h

#include "Encrypted.h"
#include <cstring>

using namespace std;

/*************************************************************************************************************
class CypherA, derived from Encrypted:
- "CypherA" is a constructor that calls Encrypted and passes its file name and max byte size parameters
- "~CypherA" is a destructor
- "decode" decrypts the message by the same method as Lab 4
*************************************************************************************************************/
class CypherA : public Encrypted {
    public:
        CypherA(string name, int size) : Encrypted(name, size) {};
        ~CypherA(){};
        void decode() {
            char key[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                  'i', 'z', 't', 'o', 'h', 'n', 'd', 'b', 'e', 'q', 'r', 'k', 'g',
                  'l', 'm', 'a', 'c', 's', 'v', 'w', 'f', 'u', 'y', 'p', 'j', 'x'};

            for (int i = 0; i < strlen(message); i++)
                if (isalpha(message[i]))
                    message[i] = key[int(message[i]) - 97 + 26];
                else
                    continue;
        };
};

#endif //

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
