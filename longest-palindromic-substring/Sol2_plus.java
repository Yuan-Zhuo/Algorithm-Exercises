class Solution {
    public String longestPalindrome(String str) {
        int len;
        if (str == null || ((len = str.length()) == 0))
            return "";
        else if (len <= 2) {
            if (len == 1)
                return str;
            else
                return (str.charAt(0) == str.charAt(1)) ? str : str.substring(1);
        }

        int start = 0, end = 0, size = 1;
        int half = (len - 1) / 2;
        for (int i = 0; i <= half; i++) {
            int singleSize = maxSize(str, i, i);
            int doubleSize = maxSize(str, i, i + 1);
            int iMax = Math.max(singleSize, doubleSize);

            if (size < iMax) {
                start = i - (iMax - 1) / 2;
                end = i + iMax / 2;
                size = iMax;
            }
        }


        for (int i = half + 1; i < len; i++) {
            int leftMax = (len - i) * 2 - 1;
            if (size >= leftMax)
                break;
            
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