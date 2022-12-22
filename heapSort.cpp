#include "heapSort.h"
void condition(vector<int>& vect, int n,int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < n && vect[left] > vect[largest])
        largest = left;
    if (right < n && vect[right] > vect[largest])
        largest = right;
    if (largest != i) {
        swap(vect[i], vect[largest]);
        condition(vect, n, largest);
    }
}
void HeapSort(vector<int>& vect) {
    for (int i = vect.size() / 2 - 1; i >= 0; i--)
        condition(vect, vect.size(), i);
    for (int i = vect.size() - 1; i >= 0; i--) {
        swap( vect[0], vect[i]);
        condition(vect, i, 0);
    }
}