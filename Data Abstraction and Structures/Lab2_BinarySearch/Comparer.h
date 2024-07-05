#ifndef SEARCHER_H
#define SEARCHER_H

#include "Comparer.h"

template <typename T>
class Searcher {
public:
   // Returns the index of the key in the sorted array, or -1 if the key is not
   // found
   static int BinarySearch(T* array, int arraySize, const T& key,
      Comparer<T>& comparer) {
      // TODO: Type your code here
      int low = 0;
      int high = arraySize - 1;

      while (low <= high){
        int mid = (high + low)/2;
        int comparison = comparer.Compare(array[mid], key);

        if (comparison < 0) {
            low = mid + 1;
        }
        else if (comparison > 0){
            high = mid - 1;
        }
        else if (comparison == 0){
            return mid;
        }
      }

      return -1;
   }
};

#endif