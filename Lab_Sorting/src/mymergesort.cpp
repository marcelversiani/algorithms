#include <mysortfunctions.h>

// mergesort with recursion
void mymergesort_recursive(std::vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 1;
    stats.depth_recursion_stack = 1;
    float depth = 1;
    
    mergesort_recursive(v, stats, depth, 0, v.size()-1);
}

// mergesort using the iterative algorithm
void mymergesort_iterative(std::vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 1;
    stats.depth_recursion_stack = 1;
    int n = v.size();
    int current, left;

    for (current = 1; current <= n-1; current = 2*current) {
        for (left = 0; left < n-1; left += 2*current) {
            int right = std::min(left + 2*current - 1, n-1);
            int mid = std::min(left + current - 1, n-1);
            merge(v, left, mid, right);
        }
    }
}

// mergesort recursive function
void mergesort_recursive(std::vector<int> &v, SortStats &stats, float depth, int left, int right) {
    stats.recursive_calls++;
    stats.depth_recursion_stack = std::max(stats.depth_recursion_stack, depth);

    if (left < right) {
        int mid = (left+right)/2;
        mergesort_recursive(v, stats, depth+1, left, mid);
        mergesort_recursive(v, stats, depth+1, mid+1, right);
        merge(v, left, mid, right);
    }
}

// merge algorithm
void merge(std::vector<int> &v, int left, int mid, int right) {
    int i, j, k;
    int x1 = mid-left+1;
    int x2 = right-mid;
    int vsize = v.size();
    static std::vector<int> L, R;
    L.resize(vsize);
    R.resize(vsize);

    for (i = 0; i < x1; i++)
        L[i] = v[left + i];
    for (j = 0; j < x2; j++)
        R[j] = v[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < x1 && j < x2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < x1) {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < x2) {
        v[k] = R[j];
        j++;
        k++;
    }
}
