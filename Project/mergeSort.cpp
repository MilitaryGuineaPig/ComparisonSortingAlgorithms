#include"mergeSort.h"

vector<int> sort(vector<int> first, vector<int> second) {
    vector<int> res;
    int size = first.size() + second.size();
    int counterF = 0, counterN = 0;
    for (int i = 0; i < size; i++) {
        if (counterF >= first.size()) {
            res.push_back(second[counterN++]);
        }
        else if (counterN == second.size() || first[counterF] < second[counterN]) {
            res.push_back(first[counterF++]);
        }
        else {
            res.push_back(second[counterN++]);
        }
    }
    return res;
}
void merge(vector<int>& vect, int left, int right, int mid) {
    vector<int> first;
    for (int i = left; i <= mid; i++){
        first.push_back(vect[i]);
    }
    vector<int> second;
    for (int j = mid + 1; j <= right; j++) {
        second.push_back(vect[j]);
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