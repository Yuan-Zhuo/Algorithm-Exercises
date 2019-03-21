class Solution {
    public String longestPalindrome(String str) {
        int len;
        if (str == null || ((len = str.length()) == 0))
            return "";

        int start = 0, end = 0, size = 1;
        for (int i = 0; i < len - 1; i++) {
            int singleSize = maxSize(str, i, i);
            int doubleSize = maxSize(str, i, i + 1);
            int iMax = Math.max(singleSize, doubleSize);

            if (size < iMax) {
                start = i - (iMax - 1) / 2;
                end = i + iMax / 2;
                size = iMax;
            }
        }

        return str.substring(start, end + 1);
    }
    
    private static int maxSize(String str, int i, int j) {
        if (str.charAt(i) != str.charAt(j))
            return 0;

        int lIdx = 0, rIdx = str.length() - 1;
        int size = ((i--) == (j++)) ? 1 : 2;
        while (i >= lIdx && j <= rIdx && (str.charAt(i) == str.charAt(j))) {
            i--;
            j++;
            size += 2;
        }

        return size;
    }
}