#include "quickSort.h"
void swapppp(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
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