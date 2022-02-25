#include "Block.h"
#include "sha256.h"
#include <sstream>


Block::Block(uint32_t nIndexIn, const string &sDataIn)
{
    _nNonce = -1;
    _tTime = time(nullptr);
    

}

string Block::GetHash()
{
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty)
{
    

    char* cstr = new char[nDifficulty + 1];
    for(uint32_t i = 0; i < nDifficulty; i++)
    {
        cstr[i] = '0';
    }

    

    cstr[nDifficulty] = '\0';

    string str(cstr);
    

    do
    {

        _nNonce++;
        _sHash = _CalculateHash();




    } while (_sHash.substr(0, nDifficulty) != str);

    delete cstr;

    cout << "block mined:" << _sHash << endl;

    

}

inline string Block::_CalculateHash() const {
    stringstream sst;
    sst << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(sst.str());
}