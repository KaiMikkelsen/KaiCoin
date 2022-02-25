#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;



class Blockchain {
public:
    Blockchain();
    void addBlock(Block newBlock);
    float totalCoins = 100;
    float amountgivenout;

private:
    uint32_t difficulty;
    vector<Block> chain;
    int chainDivide = 2;

    Block getLastBlock() const;
};