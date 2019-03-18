/*************************************************************************************************************
CIS 22C
Lab 5: This program provides the implementation of the base class Encrypted and derived classes CypherA and
       CypherB for the main function, which receives the a file name of the file containing the encrypted
       message as input and outputs the decrypted message for each method of decryption.
Author: Vincent Nguyen
Date: 3/8/19
*************************************************************************************************************/
#include "Encrypted.h"
#include <fstream>
#include <iostream>
#include <cstring>

/*************************************************************************************************************
The constructor receives the file name and maximum byte size and dynamically allocates space for the "message"
variable which will hold the message. Then it attempts to open the file and sets the variable "status" based
on the result. Then it lets "message" receive each character from the file.
*************************************************************************************************************/
Encrypted::Encrypted(string name, int size)
{
    message = new char [size + 1];

    ifstream inputFile;
    inputFile.open(name.c_str());
    if(!inputFile)
        status = true;
    else
        status = false;

    int n = 0;
    char temp;

    inputFile >> noskipws;
    while(inputFile >> temp)
    {
        message[n] = temp;
        n++;
    }
}

/*************************************************************************************************************
destructor of Encrypted
*************************************************************************************************************/
Encrypted::~Encrypted()
{
    delete []message;
}
/*************************************************************************************************************
the bool isEmpty returns the value of status.
*************************************************************************************************************/
bool Encrypted::isEmpty()
{
    return status;
}


/*************************************************************************************************************
the print function displays the encrypted message.
*************************************************************************************************************/
void Encrypted::print()
{
    for (int i = 0; i < strlen(message); i++)
        cout << message[i];
}

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
