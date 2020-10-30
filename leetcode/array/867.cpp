#include "../../ALL_H_FILES.hpp"
class Solution {
   public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.empty())
            return vector<vector<int>>();
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> B(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};
