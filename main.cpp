#include "Blockchain.h"

int main() {


    cout << "Creating block" << endl;
    Blockchain bChain = Blockchain();

    cout << "Mining block 1..." << endl;
    bChain.addBlock(Block(1, "Block 1 Data"));
    cout << "Done Mining Block" << endl;

    cout << bChain.amountgivenout << endl;


    cout << "Mining block 2..." << endl;
    bChain.addBlock(Block(2, "Block 2 Data"));

    cout << bChain.amountgivenout << endl;

    cout << "Mining block 3..." << endl;
    bChain.addBlock(Block(3, "Block 3 Data"));

    for(int i = 4; i < 25; i++)
    {

        bChain.addBlock(Block(i, "block data" + to_string(i)));

        cout << bChain.amountgivenout << endl;

    }


   

    return 0;

}