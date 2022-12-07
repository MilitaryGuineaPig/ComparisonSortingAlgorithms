#include "quickSort.h"
void swapppp(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Print(vector<int> Vector) {
    for (int val : Vector)
        cout << val << " ";
    cout << endl;
}

int pivotII(vector<int>& vect, int left, int right) {
    int pivot = vect[right];
        vector<int> greater, lower;
        for (int i = right - 1; i >= left; i--) {
            if (vect[i] >= pivot) greater.push_back(vect[i]);
            else lower.push_back(vect[i]);
        }
        int counter = greater.size()-1, bol = 0;
        int lowerSize = lower.size()-1;
        int sizee = lower.size() + greater.size();
        
        for (int i = left; i <= left+sizee; i++) {
            if (i < (left + lower.size())) {
                vect[i] = lower[bol++];
            }
            else if (i > left + lower.size()) {
                vect[i] = greater[counter--];
            }
            else if  (i == left + lower.size() ) {
                vect[left + lower.size()] = pivot; 
            }
            else {
                cout << "Error!" << endl;
            }
        }
        return left + lower.size();
}

int pivotI(vector<int>& vect, int left, int right) {
    int pivot = vect[right];
    int pivotId = right;
    int counter = left;
    for (int i = right - 1; i >= left; i--) {
        if (vect[i] < vect[pivotId]) {
            swapppp(&vect[i], &vect[counter++]);
            i++;
            left++;
        }
        else if (vect[i] >= vect[pivotId]) {
            swapppp(&vect[i], &vect[pivotId]);
            pivotId = i;
        }
    }
    return pivotId;
}

void QuickSort(vector<int>& vect, int left, int right) {
    if (left < right) {
        int pivot = pivotI(vect, left, right);
        QuickSort(vect, left, pivot - 1);
        QuickSort(vect, pivot + 1, right);
    }
}

int Partition(vector<int>& Vector, int low, int high) {
    int pivot = Vector[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (Vector[j] <= pivot) {
            i++;
            swapppp(&Vector[i], &Vector[j]);
        }
    }
    swapppp(&Vector[i + 1], &Vector[high]);
    return (i + 1);
}
int partition(int array[], int low, int high) {
  // select the rightmost element as pivot
    int pivot = array[high];
    // pointer for greater element
    int i = (low - 1);
   // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;
            // swap element at i with element at j
            swapppp(&array[i], &array[j]);
        }
    }
    // swap pivot with the greater element at i
    swapppp(&array[i + 1], &array[high]);
    // return the partition point
    return (i + 1);
}
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);
        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);
        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}
