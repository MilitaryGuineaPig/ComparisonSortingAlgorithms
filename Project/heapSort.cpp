#include "heapSort.h"
void swapp(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void condition(vector<int>& vect, int i) {
    if (i > 0) {
        if (i % 2 != 0) {
            if (vect[i] > vect[(i - 1) / 2]) {
                swapp(&vect[i], &vect[(i - 1) / 2]);
                condition(vect, (i - 1) / 2);
            }
        }
        else {
            if (vect[i] > vect[(i - 2) / 2]) {
                swapp(&vect[i], &vect[(i - 2) / 2]);
                condition(vect, (i-2)/2);
            }
        }
    }
}

void HeapSort(vector<int>& vect) {
    for (int i = 1; i < vect.size(); i++) {
        condition(vect, i);
    }
    for (int i = vect.size() - 1; i >= 0; i--) {
        swapp(&vect[0], &vect[i]);
        for (int j = 1; j < i; j++) {
            condition(vect, j);
        }
    }
}