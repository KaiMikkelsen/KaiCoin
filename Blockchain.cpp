#include "Blockchain.h"



Blockchain::Blockchain()
{
    chain.emplace_back(Block(0, "Genesis Block"));
    difficulty = 1;


}

void Blockchain::addBlock(Block newBlock)
{
    
    newBlock.previousHash = getLastBlock().getHash();
    
    newBlock.mineBlock(difficulty);

    chain.push_back(newBlock);




}

Block Blockchain::getLastBlock() const{
    return chain.back();
}