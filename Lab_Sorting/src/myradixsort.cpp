#include <mysortfunctions.h>

// radix sort using hexadecimal base
void myradixsort(std::vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 1;
    stats.depth_recursion_stack = 1;
    
    int value;
    int idx;  
    int base = 16;
    int max_num = v.size();
    int max_digits = std::ceil(log(max_num)/log(base));
    int mask = 0xF; // 4 bits
    std::queue<int> buckets[base];

    for (int digit = 0; digit < max_digits; digit++) { // for each digit
        for (int i = 0; i < max_num; i++) { // for each number
            value = v[i];
            buckets[(value & mask) >> (digit*4)].push(value); // digit in base 4 insertion
        }
        idx = 0;
        for (int i = 0; i < base; i++) { // for each bucket
            while (!buckets[i].empty()) {
                v[idx++] = buckets[i].front();
                buckets[i].pop();
            }
        }
    mask = mask << 4; // next digit
    }
}



