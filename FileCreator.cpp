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
    ofstream MyFile("Results.txt");
    using chrono::microseconds;
    for (static int AmountOfNumbers = 100; AmountOfNumbers <= 10000; AmountOfNumbers += 100){
        int InsertTimeTakenAVG = 0, HeapTimeTakenAVG = 0, MergeTimeTakenAVG = 0, QuickTimeTakenAVG = 0;
        for (int i = 0; i < 20; i++) {
            vector<int> Vector = CreateRandomVector(AmountOfNumbers);
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
        MyFile << AmountOfNumbers << " " << InsertTimeTakenAVG / 20
            << " " << HeapTimeTakenAVG / 20
            << " " << MergeTimeTakenAVG / 20
            << " " << QuickTimeTakenAVG / 20 << endl;
        progress(AmountOfNumbers);
    }
    MyFile.close();
}