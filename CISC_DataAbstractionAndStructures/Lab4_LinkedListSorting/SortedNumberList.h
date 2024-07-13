#ifndef SORTEDNUMBERLIST_H
#define SORTEDNUMBERLIST_H
#include "NumberList.h"

class SortedNumberList : public NumberList {
private:
   // Optional: Add any desired private functions here
    NumberListNode* nextNode;
    NumberListNode* currentNode;
    NumberListNode* previousNode;
public:
   SortedNumberList() {
      head = nullptr;
      tail = nullptr;
   }

   // Inserts the number into the list in the correct position such that the
   // list remains sorted in ascending order.
   void Insert(double number) {
      // TODO: Type your code here
        NumberListNode* nodeToInsert = new NumberListNode(number);

        if (!head){
            head = nodeToInsert;
            tail = nodeToInsert;
        }
        else{
            currentNode = head;

            while (currentNode && nodeToInsert->GetData() > currentNode->GetData()){
                previousNode = currentNode;
                currentNode = currentNode->GetNext(); 
            }
            if(currentNode == head){
                nodeToInsert->SetNext(head);
                head->SetPrevious(nodeToInsert);
                head = nodeToInsert;
            }
            else if (currentNode == nullptr){
                tail->SetNext(nodeToInsert);
                nodeToInsert->SetPrevious(tail);
                tail = nodeToInsert;
            }
            else {
                previousNode->SetNext(nodeToInsert);
                currentNode->SetPrevious(nodeToInsert);
                nodeToInsert->SetPrevious(previousNode);
                nodeToInsert->SetNext(currentNode);
            }
        }
   }
   
   // Removes the node with the specified number value from the list. Returns
   // true if the node is found and removed, false otherwise.
   bool Remove(double number) {
    if(head){
      currentNode = head;
      previousNode = nullptr;

      while(currentNode && number != currentNode->GetData()){
        previousNode = currentNode;
        currentNode = currentNode->GetNext();
      }

      if (currentNode){
        if (currentNode == head){
            if(currentNode->GetNext()){
                head = currentNode->GetNext();
                head->SetPrevious(nullptr);
            }
            else {
                head = nullptr;
                tail = nullptr;
            }
        }
        else if (currentNode == tail){
            tail = previousNode;
            previousNode->SetNext(nullptr);
        }
        else{
            previousNode->SetNext(currentNode->GetNext());
            currentNode->GetNext()->SetPrevious(previousNode);
            
        }
        delete currentNode;
        return true;
      }
    }
      return false;
   }
};

#endif