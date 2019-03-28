class Solution {
    public String longestPalindrome(String str) {
        if (str.equals(""))
            return "";

        int len = str.length();
        Boolean arr[][] = new Boolean[len][len];

        for (int i = 0; i < len; i++)
            arr[i][i] = Boolean.TRUE;

        for (int i = 0; i < len - 1; i++)
            arr[i][i + 1] = (str.charAt(i) == str.charAt(i + 1));

        for (int j = 2; j < len; j++) {
            int cnt = len - j;
            for (int row = 0; row < cnt; row++) {
                int col = j + row;
                arr[row][col] = arr[row + 1][col - 1] && (str.charAt(row) == str.charAt(col));
            }
        }

        for (int idx = len - 1; idx >= 0; idx--) {
            int cnt = len - idx;
            for (int row = 0; row < cnt; row++) {
                int col = idx + row;
                if (arr[row][col]) {
                    return str.substring(row, col + 1);
                }
            }
        }

        return "";
    }
}