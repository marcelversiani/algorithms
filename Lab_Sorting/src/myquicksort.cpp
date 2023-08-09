#include <mysortfunctions.h>

// the most comon quicksort, with 2 recursive calls
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 1;
    stats.depth_recursion_stack = 1;
    float depth = 1;

    quicksort_2recursion_medianOf3(v, stats, depth, 0, v.size()-1);
}

// quicksort with one recursive call
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 1;
    stats.depth_recursion_stack = 1;
    float depth = 1;

    quicksort_1recursion(v, stats, depth, 0, v.size()-1);
} 

// quicksort with fixed pivot 
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 1;
    stats.depth_recursion_stack = 1;
    float depth = 1;

    quicksort_2recursion_fixed(v, stats, depth, 0, v.size()-1);
} 

// quicksort recursive function with 2 calls using fixed pivot
void quicksort_2recursion_fixed(std::vector<int> &v, SortStats &stats, float depth, int min, int max) {
    stats.recursive_calls++;
    stats.depth_recursion_stack = std::max(stats.depth_recursion_stack, depth);

    if (min < max) {
        int p = partition(v, min, max);
        quicksort_2recursion_fixed(v, stats, depth+1, min, p-1);
        quicksort_2recursion_fixed(v, stats, depth+1, p+1, max);
    }
}

// quicksort recursive function with 2 calls using medianOf3
void quicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats, float depth, int min, int max) {
    stats.recursive_calls++;
    stats.depth_recursion_stack = std::max(stats.depth_recursion_stack, depth);

    if (min < max) {
        medianOf3(v, min, max);
        int p = partition(v, min, max);
        quicksort_2recursion_medianOf3(v, stats, depth+1, min, p-1);
        quicksort_2recursion_medianOf3(v, stats, depth+1, p+1, max);
    }
}

// quicksort recursive function with 1 call and using medianOf3
void quicksort_1recursion(std::vector<int> &v, SortStats &stats, float depth, int min, int max) {
    int p;
    stats.recursive_calls++;
    stats.depth_recursion_stack = std::max(stats.depth_recursion_stack, depth);

    while (min < max) {
        medianOf3(v, min, max);
        p = partition(v, min, max);
        if (p - min < max - p) {
            quicksort_1recursion(v, stats, depth+1, min, p-1);
            min = p+1;
        }
        else {
            quicksort_1recursion(v, stats, depth+1, p+1, max);
            max = p-1;
        }
    }
}

// partition algorithm for quicksort 
int partition(std::vector<int> &v, int left, int right) {
    int pivot = v[left];
    int l = left+1;
    int r = right;
    while (true) {
        while (l <= r && v[l] < pivot) l++;
        while (l <= r && v[r] > pivot) r--;
        if (l < r) std::swap(v[l], v[r]);
        else break;
    }   
    std::swap(v[left], v[r]);
    return r;
}

// makes the 1st vector element the median of 3 pivots
void medianOf3(std::vector<int> &v, int left, int right) {
    int i0 = left;
    int mid = (left+right)/2;

    if (v[left] > v[mid]) std::swap(left, mid);
    if (v[left] > v[right]) std::swap(left, right);
    if (v[mid] > v[right]) std::swap(mid, right);
    troca(v, i0, mid);
}
