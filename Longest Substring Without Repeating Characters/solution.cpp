class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int pre_max = 0, cur_size = 0;
        int lptr = 0;

        for (int rptr = 0; rptr < len; ++rptr) {
            char ch = s[rptr];
            int ptr = lptr;
            for (; ptr < rptr; ++ptr) {
                if (s[ptr] == ch)
                    break;
            }

            if (ptr == rptr) {
                cur_size++;
            } else {
                pre_max = pre_max > cur_size ? pre_max : cur_size;
                cur_size = rptr - ptr;
                lptr = ptr + 1;
            }
        }

        return pre_max > cur_size ? pre_max : cur_size;
    }
};