#ifndef INSERTATCOMMAND_H
#define INSERTATCOMMAND_H

#include <string>
#include <vector>
#include "UndoCommand.h"

class InsertAtCommand : public UndoCommand {
private:
   // TODO: Type your member variable declarations here
    std::vector<std::string>* sourceVector;
    int insertIndex;
    std::string listItem;

public:
   // TODO: Type your constructor code here
    InsertAtCommand(int index, std::string string, std::vector<std::string>* vector) {
        sourceVector = vector;
        insertIndex = index;
        listItem = string;
    }
    
   void Execute() override {
      // TODO: Type your code here
       sourceVector->insert(sourceVector->begin() + insertIndex, listItem);
   }
};

#endif
