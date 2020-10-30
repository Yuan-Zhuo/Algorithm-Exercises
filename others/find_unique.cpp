// 有序数组中除一个数外，每个数都可以找到相同的数两两配对，找到这个数
// 二分法

#include "../ALL_H_FILES.hpp"

int find_unique(vector<int> vec, int low, int high) {
    if (low > high)
        return -1;
    else if (low == high)
        return vec[low];

    int idx = 2 * ((high - low + 1) / 4);
    if (vec[idx] != vec[idx + 1]) {
        return find_unique(vec, low, idx);
    } else {
        return find_unique(vec, idx + 2, high);
    }
}

int find_unique(vector<int> vec) {
    int size = vec.size();
    return find_unique(vec, 0, size - 1);
}

int main() {
    vector<int> vec = {0};
    cout << find_unique(vec) << endl;
}
