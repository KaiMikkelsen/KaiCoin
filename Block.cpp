#include "Block.h"
#include "sha256.h"
#include <sstream>


Block::Block(uint32_t indexIn, const string &dataIn)
{
    nonce = -1;
    timeStarted = time(nullptr);
    

}

string Block::getHash()
{
    return hash;
}

void Block::mineBlock(uint32_t difficulty)
{
    

    char* codeToCrack = new char[difficulty + 1];

    for(uint32_t i = 0; i < difficulty; i++)
    {
        codeToCrack[i] = '0';
    }

    

    codeToCrack[difficulty] = '\0';

    string str(codeToCrack);
    

    do
    {
        nonce++;
        hash = calculateHash();
    } while (hash.substr(0, difficulty) != str);

    delete codeToCrack;

    cout << "block mined:" << hash << endl;

    

}

inline string Block::calculateHash() const {
    stringstream sst;
    sst << index << time << data << nonce << previousHash;

    return sha256(sst.str());
}