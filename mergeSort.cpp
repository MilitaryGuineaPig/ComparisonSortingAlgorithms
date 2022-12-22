#include"mergeSort.h"

vector<int> sort(vector<int> first, vector<int> second) {
    int size = first.size() + second.size();
    vector<int> res(size);
    int counterF = 0, counterN = 0;
    for (int i = 0; i < size; i++) {
        if (counterF >= first.size()) {
            res[i] = (second[counterN++]);
        }
        else if (counterN == second.size() || first[counterF] < second[counterN]) {
            res[i] = (first[counterF++]);
        }
        else {
            res[i] = (second[counterN++]);
        }
    }
    return res;
}
void merge(vector<int>& vect, int left, int right, int mid) {
    vector<int> first(mid - left + 1);
    for (int i = left; i <= mid; i++){
        first[i - left] = (vect[i]);
    }
    vector<int> second(right - mid);
    for (int j = mid + 1; j <= right; j++) {
        second[j - mid - 1] = (vect[j]);
    }
    vector<int> res = sort(first, second);
    int index = left;
    for (int i = 0; i < res.size(); i++){
        vect[index++] = res[i];
    }
}
void MergeSort(vector<int>& vect, int left, int right) {
    if (left < right) {
        MergeSort(vect, left, (left + right) / 2);
        MergeSort(vect, (left + right) / 2 + 1, right);

        merge(vect, left, right, (left + right) / 2);
    }
}