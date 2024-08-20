#ifndef SWAPCOMMAND_H
#define SWAPCOMMAND_H

#include <string>
#include <vector>
#include "UndoCommand.h"

class SwapCommand : public UndoCommand {
private:
   // TODO: Type your member variable declarations here
    int pos1;
    int pos2;
    std::vector<std::string>* sourceVector;

public:
   // TODO: Type your constructor code here
    SwapCommand(int index1, int index2, std::vector<std::string>* vector) {
        sourceVector = vector;
        pos1 = index1;
        pos2 = index2;
    }
   
   void Execute() override {
      // TODO: Type your code here
       std::string temp = sourceVector->at(pos2);
       sourceVector->at(pos2) = sourceVector->at(pos1);
       sourceVector->at(pos1) = temp;
   }
};

#endif
