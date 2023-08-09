#ifndef YOURSORTFUNCTIONS_H
#define YOURSORTFUNCTIONS_H


#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cmath>        // std::ceil
#include <queue>        // std::queue
#include <sortauxfuncs.h>

// Sorting functions
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats);

void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats);

void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats);

void myradixsort(std::vector<int> &v, SortStats &stats);

void mymergesort_recursive(std::vector<int> &v, SortStats &stats);

void mymergesort_iterative(std::vector<int> &v, SortStats &stats);

void quicksort_2recursion_fixed(std::vector<int> &v, SortStats &stats, float depth, int min, int max);

void quicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats, float depth, int min, int max);

void quicksort_1recursion(std::vector<int> &v, SortStats &stats, float depth, int min, int max);

void mergesort_recursive(std::vector<int> &v, SortStats &stats, float depth, int left, int right);

// Auxiliary functions
int partition(std::vector<int> &v, int left, int right);

void medianOf3(std::vector<int> &v, int left, int right);

void merge(std::vector<int> &v, int left, int mid, int right);

#endif
