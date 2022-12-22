#include "FileCreator.h"
#include <random>
#include <iostream>
#include <algorithm>

vector<int> Insert(vector<int>& Vector, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int val = Vector[i];
        int cur = i;
        while ((cur > 0) && Vector[cur - 1] > val) {
            Vector[cur] = Vector[cur - 1];
            cur--;
        }
        Vector[cur] = val;
    }
    return Vector;
}
int Pivot(vector<int>& vect, int left, int right) {
    int pivot = vect[right];
    int pivotId = right;
    int counter = left;
    for (int i = right - 1; i >= left; i--) {
        if (vect[i] < vect[pivotId]) {
            swap(vect[i], vect[counter++]);
            i++;
            left++;
        }
        else if (vect[i] >= vect[pivotId]) {
            swap(vect[i], vect[pivotId]);
            pivotId = i;
        }
    }
    return pivotId;
}
void HybridSort(vector<int>& vect, int left, int right) {
    if (vect.size() < 100) {
        InsertSort(vect);
    }
    else {
        if (left < right) {
            if (right-left < 100) {
                Insert(vect, left, right);
            }
            else {
                int pivot = Pivot(vect, left, right);
                HybridSort(vect, left, pivot - 1);
                HybridSort(vect, pivot + 1, right);
            }
        }
    }
}

vector<int> CreateRandomVector(int AmountOfNumbers) {
    vector<int> vec;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, AmountOfNumbers + 2);
    for (int i = 0; i < AmountOfNumbers; ++i) vec.push_back(dist(gen));
    return vec;
}
void progress(int AmountOfNumbers) {
    float res = AmountOfNumbers;
    cout << "\t--- " << (res - 1) / 100 << "% ---" << endl;
}
void CreateFileOfTasks() {
    ofstream MyFile("Results.txt");
    using chrono::nanoseconds;
    for (static int AmountOfNumbers = 1; AmountOfNumbers <= 10001;){
        double InsertTimeTakenAVG = 0, HeapTimeTakenAVG = 0, MergeTimeTakenAVG = 0, QuickTimeTakenAVG = 0, HybridTimeTakenAVG = 0;
        for (int i = 0; i < 200; i++) {
            vector<int> Vector = CreateRandomVector(AmountOfNumbers);
            vector<int> VectorInsert = Vector, VectorHeap = Vector, VectorMerge = Vector, VectorHybrid= Vector;
            //insert DONE!
            auto StartInsert = chrono::steady_clock::now();
            InsertSort(VectorInsert);
            auto EndInsert = chrono::steady_clock::now();
            nanoseconds InsertTimeTaken = chrono::duration_cast<nanoseconds>(EndInsert - StartInsert);
            InsertTimeTakenAVG += InsertTimeTaken.count();
            //heap DONE!
            auto StartHeap = chrono::steady_clock::now();
            HeapSort(VectorHeap);
            auto EndHeap = chrono::steady_clock::now();
            nanoseconds HeapTimeTaken = chrono::duration_cast<nanoseconds>(EndHeap - StartHeap);
            HeapTimeTakenAVG += HeapTimeTaken.count();
            //merge DONE!
            auto StartMerge = chrono::steady_clock::now();
            MergeSort(VectorMerge, 0, VectorMerge.size() - 1);
            auto EndMerge = chrono::steady_clock::now();
            nanoseconds MergeTimeTaken = chrono::duration_cast<nanoseconds>(EndMerge - StartMerge);
            MergeTimeTakenAVG += MergeTimeTaken.count();
            //quick DONE!
            auto StartQuick = chrono::steady_clock::now();
            QuickSort(Vector, 0, Vector.size() - 1);
            auto EndQuick = chrono::steady_clock::now();
            nanoseconds QuickTimeTaken = chrono::duration_cast<nanoseconds>(EndQuick - StartQuick);
            QuickTimeTakenAVG += QuickTimeTaken.count();
            //Hybrid DONE!
            auto StartHybrid = chrono::steady_clock::now();
            HybridSort(VectorHybrid,0,VectorHybrid.size()-1);
            auto EndHybrid = chrono::steady_clock::now();
            nanoseconds HybridTimeTaken = chrono::duration_cast<nanoseconds>(EndHybrid - StartHybrid);
            HybridTimeTakenAVG += HybridTimeTaken.count();
        }
        MyFile << AmountOfNumbers 
            << " " << InsertTimeTakenAVG / 200
            << " " << HeapTimeTakenAVG   / 200
            << " " << MergeTimeTakenAVG  / 200
            << " " << QuickTimeTakenAVG  / 200
            << " " << HybridTimeTakenAVG / 200 
            << endl;

        progress(AmountOfNumbers);

        if (AmountOfNumbers > 100) AmountOfNumbers += 100;
        else AmountOfNumbers += 5;
    }
    MyFile.close();
}