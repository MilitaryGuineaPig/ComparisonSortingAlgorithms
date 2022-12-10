#include <iostream>
#include "FileCreator.h"
using namespace std;

int main() {
    cout << "[1] InsertSort \t [2] HeapSort \t [3] MergeSort \t [4] QuickSort" << endl;
    CreateFileOfTasks();
    cout << "\n\tDone!";
    return 0;
}
