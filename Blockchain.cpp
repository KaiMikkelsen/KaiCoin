#include "Blockchain.h"



Blockchain::Blockchain()
{
    chain.emplace_back(Block(0, "Genesis Block"));
    difficulty = 2;


}

void Blockchain::addBlock(Block newBlock)
{
    
    newBlock.previousHash = getLastBlock().getHash();
    
    newBlock.mineBlock(difficulty);

    chain.push_back(newBlock);

    if(chain.size() == chainDivide)
    {
        chainDivide = chainDivide * 2;

        amountgivenout = totalCoins / chainDivide;
    }

}

Block Blockchain::getLastBlock() const{
    return chain.back();
}