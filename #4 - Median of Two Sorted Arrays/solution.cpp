class Solution {
   public
    static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        boolean odd = (m + n) % 2 != 0;
        if (m > n) {
            int[] tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
            int swp = m;
            m = n;
            n = swp;
        }

        int iMin = 0, iMax = m, lsize = (m + n + 1) / 2;
        int i = 0, j = 0;
        while (true) {
            i = (iMin + iMax) / 2;
            j = lsize - i;
            if (i != 0 && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            } else if (j != 0 && i < m && nums1[i] < nums2[j - 1]) {
                iMin = i + 1;
            } else {
                int lmax1 = (i == 0) ? Integer.MIN_VALUE : nums1[i - 1];
                int lmax2 = (j == 0) ? Integer.MIN_VALUE : nums2[j - 1];
                int lmax = Math.max(lmax1, lmax2);
                if (odd)
                    return lmax;
                int rmin1 = (i == m) ? Integer.MAX_VALUE : nums1[i];
                int rmin2 = (j == n) ? Integer.MAX_VALUE : nums2[j];
                int rmin = Math.min(rmin1, rmin2);
                return (lmax + rmin) / 2.0;
            }
        }
    }
}