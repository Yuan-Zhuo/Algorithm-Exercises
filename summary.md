## vector 用法
1. 大小
```c++
// m*n 矩阵
// 1
vector<vector<int>> B(m, vector<int>(n,0));

// 2
B.resize(m);
for(auto b : B){
    b.resize(n, 0);
}
```

## 时间复杂度优化
1. O(n)->O(log(n))，二分法

