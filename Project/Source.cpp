////-------------- Notes --------------
//#include "heapSort.h"
//
//
//// nado napisat if funcktion i potom eshe if
//void iff(vector<int>& vect, int i) {
//    if (i>0){
//        if (i % 2 != 0) {
//            if (vect[i] > vect[(i - 1) / 2]) {
//                swapp(&vect[i], &vect[(i - 1) / 2]);
//            }
//        }
//        else {
//            if (vect[i] > vect[(i - 2) / 2]) {
//                swapp(&vect[i], &vect[(i - 2) / 2]);
//            }
//        }
//        iff(vect, --i);
//    }
//}
//void build(vector<int>& vect) {
//    for (int i = 1; i < vect.size(); i++) {
//        iff(vect,i);
//    }
//}
//void HeapSort(vector<int>& vect) {
//    vector<int> SortedVector = vect;
//    for (int i = 0; i < vect.size(); i++) {
//        build(vect);
//        SortedVector[vect.size() - 1 - i] = vect[0];
//        vect.pop_back();
//
//    }
//    vect = SortedVector;
//}




