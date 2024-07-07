#ifndef NATURALMERGESORTER_H
#define NATURALMERGESORTER_H

class NaturalMergeSorter {
public:
   virtual int GetSortedRunLength(int* array, int arrayLength, int startIndex) {
    if (startIndex >= arrayLength) return 0;

    int count = 1;

    while (startIndex + 1 < arrayLength && array[startIndex] <= array[startIndex+1]) {
        count++;
        startIndex++;
    }
    return count;
   }
   
   virtual void NaturalMergeSort(int* array, int arrayLength) {
    int startIndex = 0;
    int firstRun = 0;

    while (firstRun != arrayLength){
        firstRun = GetSortedRunLength(array, arrayLength, startIndex);
        int secondRunStart = startIndex + firstRun;

        if(secondRunStart == arrayLength) startIndex = 0;
        else{
            int secondRun = GetSortedRunLength(array,arrayLength, secondRunStart);
            int secondRunLast = (secondRunStart + secondRun);
            Merge(array, startIndex, secondRunStart - 1,  secondRunLast - 1);
            startIndex = secondRunLast;
        }
    }
    return;
    }
    
   
   virtual void Merge(int* numbers, int leftFirst, int leftLast,
      int rightLast) {
      int mergedSize = rightLast - leftFirst + 1;
      int* mergedNumbers = new int[mergedSize];
      int mergePos = 0;
      int leftPos = leftFirst;
      int rightPos = leftLast + 1;
         
      // Add smallest element from left or right partition to merged numbers
      while (leftPos <= leftLast && rightPos <= rightLast) {
         if (numbers[leftPos] <= numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            leftPos++;
         }
         else {
            mergedNumbers[mergePos] = numbers[rightPos];
            rightPos++;
         }
         mergePos++;
      }
         
      // If left partition isn't empty, add remaining elements to mergedNumbers
      while (leftPos <= leftLast) {
         mergedNumbers[mergePos] = numbers[leftPos];
         leftPos++;
         mergePos++;
      }
      
      // If right partition isn't empty, add remaining elements to mergedNumbers
      while (rightPos <= rightLast) {
         mergedNumbers[mergePos] = numbers[rightPos];
         rightPos++;
         mergePos++;
      }
      
      // Copy merged numbers back to numbers
      for (mergePos = 0; mergePos < mergedSize; mergePos++) {
         numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
      }
      
      // Free temporary array
      delete[] mergedNumbers;
   }
};

#endif