#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>

#include "insertSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

void CreateFileOfTasks();
void PrintVector(std::vector<int> Vector);

void test();