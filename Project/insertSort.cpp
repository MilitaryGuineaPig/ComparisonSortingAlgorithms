#include "insertSort.h"
vector<int> InsertSort(vector<int> Vector) {
    for (int i = 1; i < Vector.size(); i++) {
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

