#include <algorithm>
#include <vector>

class Solution {
    static int compar(const void* p1, const void* p2) {
        return *(int*)p1 - *(int*)p2;
    }

   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int len = nums.size();
        vector<int> nums_sorted(nums);
        qsort(&nums_sorted[0], len, sizeof(int), compar);

        int front = 0, end = len - 1;
        while (front < end) {
            int cand = nums_sorted[front] + nums_sorted[end];
            if (cand < target)
                front++;
            else if (cand > target)
                end--;
            else
                break;
        }

        int ltar = nums_sorted[front], rtar = nums_sorted[end];
        int i = 0;
        while (i < len) {
            if (nums[i++] != ltar)
                continue;
            front = i - 1;
            break;
        }
        int j = 0;
        while (j < len) {
            if (nums[j++] != rtar || j - 1 == front)
                continue;
            end = j - 1;
            break;
        }

        return vector<int>{front, end};
    }
};