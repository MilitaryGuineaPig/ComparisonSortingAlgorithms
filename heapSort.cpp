#include "heapSort.h"
void swapp(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void condition(vector<int>& vect, int n,int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < n && vect[left] > vect[largest])
        largest = left;
    if (right < n && vect[right] > vect[largest])
        largest = right;
    if (largest != i) {
        swapp(&vect[i], &vect[largest]);
        condition(vect, n, largest);
    }
}
void HeapSort(vector<int>& vect) {
    for (int i = vect.size() / 2 - 1; i >= 0; i--)
        condition(vect, vect.size(), i);
    for (int i = vect.size() - 1; i >= 0; i--) {
        swapp(&vect[0], &vect[i]);
        condition(vect, i, 0);
    }
}