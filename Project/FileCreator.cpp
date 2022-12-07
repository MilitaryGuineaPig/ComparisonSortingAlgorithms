#include "FileCreator.h"
#include <algorithm>

void PrintVector(vector<int> Vector) {
    for (int val : Vector)
        cout << val << " ";
    cout << endl;
}
vector<int> CreateRandomVector(int AmountOfNumbers) {
    vector<int> Vector(AmountOfNumbers);
    static int number = AmountOfNumbers;
    generate(Vector.begin(), Vector.end(), []() {
        return rand() % number;
        });
    return Vector;
}
void progress(int AmountOfNumbers) {
    cout << "\t--- "<< AmountOfNumbers /100<<"% ---" << endl;
}
void CreateFileOfTasks() {
    ofstream MyFile("TimeOfProcessingMicroseconds.txt");
    using chrono::microseconds;
    for (static int AmountOfNumbers = 100; AmountOfNumbers <= 10000; AmountOfNumbers += 100){
        int InsertTimeTakenAVG = 0, HeapTimeTakenAVG = 0, MergeTimeTakenAVG = 0, QuickTimeTakenAVG = 0;
        for (int i = 0; i < 1; i++) {
            vector<int> Vector;
            Vector = CreateRandomVector(AmountOfNumbers);

            //for (int i = 0; i < AmountOfNumbers; i++){Vector.push_back(i);}
            vector<int> VectorInsert = Vector, VectorHeap = Vector, VectorMerge = Vector;
            //insert DONE!
            auto StartInsert = chrono::steady_clock::now();
            InsertSort(VectorInsert);
            auto EndInsert = chrono::steady_clock::now();
            microseconds InsertTimeTaken = chrono::duration_cast<microseconds>(EndInsert - StartInsert);
            InsertTimeTakenAVG += InsertTimeTaken.count();
            //heap DONE!
            auto StartHeap = chrono::steady_clock::now();
            HeapSort(VectorHeap);
            auto EndHeap = chrono::steady_clock::now();
            microseconds HeapTimeTaken = chrono::duration_cast<microseconds>(EndHeap - StartHeap);
            HeapTimeTakenAVG += HeapTimeTaken.count();
            //merge DONE!
            auto StartMerge = chrono::steady_clock::now();
            MergeSort(VectorMerge, 0, VectorMerge.size() - 1);
            auto EndMerge = chrono::steady_clock::now();
            microseconds MergeTimeTaken = chrono::duration_cast<microseconds>(EndMerge - StartMerge);
            MergeTimeTakenAVG += MergeTimeTaken.count();
            //quick DONE!
            auto StartQuick = chrono::steady_clock::now();
            QuickSort(Vector, 0, Vector.size() - 1);
            auto EndQuick = chrono::steady_clock::now();
            microseconds QuickTimeTaken = chrono::duration_cast<microseconds>(EndQuick - StartQuick);
            QuickTimeTakenAVG += QuickTimeTaken.count();
        }
        MyFile << AmountOfNumbers << " " << InsertTimeTakenAVG / 1
            << " " << HeapTimeTakenAVG / 1
            << " " << MergeTimeTakenAVG / 1
            << " " << QuickTimeTakenAVG / 1 << endl;
        progress(AmountOfNumbers);
    }
    MyFile.close();
}

void test() {
    vector<int> Vector = CreateRandomVector(1000);
    //vector<int> Vector = {11,1,9,3,5,2,8,7};
    cout << "\tNot sorted array\n\t";
    PrintVector(Vector);
    HeapSort(Vector);
    cout << "\tSorted array\n\t";
    PrintVector(Vector);
    if (is_sorted(Vector.begin(),Vector.end())) cout<<"\tIS SORTED<<<<<<";
}