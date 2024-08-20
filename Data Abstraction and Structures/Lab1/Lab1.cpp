#include <iostream>
#include <string>
#include "LabPrinter.h"
using namespace std;

void CallFunctionNamed(LabPrinter& printer, string functionName) 
{
// TODO: Implement this function after completing step 1
    if (functionName == "Print2Plus2"){
        printer.Print2Plus2();
    }
    else if (functionName == "PrintSecret"){
        printer.PrintSecret();
    }
    else{
        cout << "Unknown function: " << functionName << endl;
    }
    
}

int main() {
   LabPrinter printer("abc");

   // TODO: After completing step 1:
   // Remove lines of code from step 1 and implement the CallFunctionNamed()
   // function above main().
   CallFunctionNamed(printer, "Print2Plus2");
   CallFunctionNamed(printer, "PrintPlus2");
   CallFunctionNamed(printer, "PrintSecret");
    
   return 0;
}