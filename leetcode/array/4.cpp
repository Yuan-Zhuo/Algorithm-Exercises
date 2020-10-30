#include "../../ALL_H_FILES.hpp"

// Sol-1 merge two array
class Solution_1 {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> vec(size1 + size2, 0);
        int idx1 = 0, idx2 = 0;
        int idx = 0;
        while ((idx1 < size1) && (idx2 < size2)) {
            if (nums1[idx1] < nums2[idx2]) {
                vec[idx++] = nums1[idx1++];
            } else {
                vec[idx++] = nums2[idx2++];
            }
        }
        while (idx1 < size1) {
            vec[idx++] = nums1[idx1++];
        }
        while (idx2 < size2) {
            vec[idx++] = nums2[idx2++];
        }
        if (idx % 2 == 0) {
            return (vec[idx / 2] + vec[idx / 2 - 1]) / 2.0;
        } else {
            return vec[idx / 2];
        }
    }
};

// Sol-2 merge in imagine
class Solution_2 {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int idx1 = 0, idx2 = 0;
        int mid = -1, pre = -1;
        int cnt = (size1 + size2) / 2;
        for (int i = 0; i <= cnt; i++) {
            pre = mid;
            if (idx1 >= size1)
                mid = nums2[idx2++];
            else if (idx2 >= size2)
                mid = nums1[idx1++];
            else
                mid =
                    (nums1[idx1] < nums2[idx2]) ? nums1[idx1++] : nums2[idx2++];
        }

        if ((size1 + size2) % 2 == 0)
            return (mid + pre) / 2.0;
        else
            return mid;
    }
};

// Sol-3 dichotomy
class Solution_3 {
   private:
    int getKth(vector<int>& nums1,
               int low1,
               vector<int>& nums2,
               int low2,
               int k) {
        if (low1 >= nums1.size())
            return nums2[low2 + k - 1];
        else if (low2 >= nums2.size())
            return nums1[low1 + k - 1];

        if (k == 1)
            return (nums1[low1] < nums2[low2]) ? nums1[low1] : nums2[low2];

        int idx1 = low1 + k / 2 - 1;
        int idx2 = low2 + k / 2 - 1;
        if (idx1 >= nums1.size())
            idx1 = nums1.size() - 1;
        else if (idx2 >= nums2.size())
            idx2 = nums2.size() - 1;

        if (nums1[idx1] > nums2[idx2]) {
            k -= (idx2 - low2 + 1);
            low2 = idx2 + 1;
        } else {
            k -= (idx1 - low1 + 1);
            low1 = idx1 + 1;
        }

        return getKth(nums1, low1, nums2, low2, k);
    }

   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int x1 = getKth(nums1, 0, nums2, 0, (size1 + size2) / 2 + 1);
        int x2 = getKth(nums1, 0, nums2, 0, (size1 + size2 - 1) / 2 + 1);
        cout << x1 << endl;
        cout << x2 << endl;
        return (x1 + x2) / 2.0;
    }
};

int main() {
    Solution_3 sol_3;
    vector<int> nums1 = {4};
    vector<int> nums2 = {1, 2, 3};
    cout << sol_3.findMedianSortedArrays(nums1, nums2);
}
