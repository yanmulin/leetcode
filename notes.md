## General

1. 大数问题，声明long/减法判断范围
2. subsequence 子序列，不一定连续
   subarray 子数组，连续
3. istringstream/ostringstream
```
istringstream iss(s);
iss >> val;
iss.write(reinterpret_cast<const char*>(&val), sizeof(val));
```
```
ostringstream oss;
oss << val;
oss.read(reinterpret_cast<const char*>(&val), sizeof(val));
oss.str();
```

4. 字符串转整型
* int stoi(string, int, int)
* int atoi(const char*)
* long strtol(const char*, const char*, int)

5. s.data() vs. s.c_str()
* s.data() 无\0结尾
* s.data() 用于s存储二进制数据

6. 接口
```cpp
template< class RandomIt >
constexpr void nth_element( RandomIt first, RandomIt nth, RandomIt last );
template< class ForwardIt, class T >
void iota( ForwardIt first, ForwardIt last, T value );
```

## Divide&Conquer

1. Steps
   * Divide => Subproblems
   * Conquer 1) Base Case 2) Recursive Case
   * Combine
2. Advantages
   * easy case => difficult case
   * parallel computing
   * Efficient Memory Access
3. Examples
   * Hanoi Tower
   * Merge Sort(LC.912)
   * Bitonic Champion
   * Maximum Subarray(LC.57)
   * Selection
4. Complexity

|Recursive|Time Complexity| Example |
|:----:|:----:|:----:|
|T(n)=2T(n-1)+1|O(2^n)|Hanoi Tower|
| T(n)=2T(n/2)+O(n) | O(nlog n) | Merge Sort, Maximum Subarray |
| T(n)=2T(n/2)+O(1) | O(n) | Bitonic Champion |
| T(n)=T(n/2)+O(1) | O(log n) | Bitonic Champion |


## Binary Search

1. 5种二分搜索：https://www.cnblogs.com/grandyang/p/6854825.html
2. mid = low + (high - low) / 2，防止溢出;
3. 开区间/闭区间，初始条件，更新方式和终止条件有所不同，返回结果相同。
4. 在有序序列中找到第一个XXX，应用：重复元素，lower_bound/upper_bound
5. 另一个lower_bound/upper_bound实现，二叉搜索树(cpp map.upper_bound/lower_bound)
6. rotated array（重复/无重复), 分治寻找有序区间（LC33/81, 153/154)
7, 有序的搜索空间，子函数g(m)返回true时更新high，low最终停在第一个满足g(m)的解

## Two Pointers

1. 双指针贪心(LC455, 881)
2. 荷兰三色旗问题

## Linked List

1. 快慢指针，判断环(LC141 142)，分割链表

## Greedy

1. 证明贪心策略不会丢失最优解，贪心不一定使解更优，但一定不会使解更差

如 LC881 乘船问题
最优解(i, j) ...
Case 1. i自己坐，将j拉过来同坐，船数不会增加
Case 2. (i, k)，交换j与k，船数也不会增加

## Tree

1. 序列化/反序列化(遍历，ASCII/Binary)
2. 完全二叉树，一位数组，LEFT_CHILD(i) = i * 2, RIGHT_CHILD(i) = i * 2 + 1, PARENT(i) = i / 2;
3. BST，子树的range
4. 遍历BST，in-order产生一个有序序列，pre-order容易区分左右子树
5. 最长路径 LC124/543/687, update ans with both children，but return only one child
6. 树的顶点覆盖问题，Greedy

## DFS/BFS

1. 排列/组合/子集(LC77,78,90)，组合也可以用位操作求解
2. DFS，剪枝
3. BFS，单向双向广度搜索(LC127)
4. Matrix Path: vector<int> dirs = {0, -1, 0, 1, 0};

## Graph

1. dense graph: E=O(V^2), sparse graph: E=O(V)
1. Topological Sort(LC207, 210, 802), hasCycle: 多状态的visited
2. Connected Component: DFS, Union Find(树的数量/大小)
3. Bipartite(LC785, 886)/着色问题, 四色定理
4. 如何删除边，使图->树: 树的节点数与边数的关系(V=E+1)，可以怎么添加边使树->环（产生循环/多个父节点）LC: 685
5. 最短路径问题: Dijkstra, Bellman-Ford(DP), Floyd-Warshall(All pairs, DP)


## Advanced
1. Binary Indexed Tree(BIT)
* update(idx, delta)
* prefixSum(idx)
* rangeSum(from_idx, to_idx)

2. Prefix Sum + HashTable(LC525, 560, 1171)
* sum[i:j] = prefixSum(j) - prefixSum(i)
* if prefixSum(i) == prefixSum(j), then sum[i:j] = 0

3. RangeSum with update
* Operations
   + update(i, delta)
   + rangeSum(i, j)
* Prefix Sum
   + rangeSum(i, j)=prefixSum(j)-prefixSum(i-1)
   + problem: update -> O(n)
* Fenwick Tree
   + rangeSum(i, j)=query(j)-query(i-1)
   + update(i, delta): sums[i]+=delta, i+=lowbit(i), until i>=sums.size()
   + query(i): res+=sums[i], i-=lowbit(i), until i <= 0
   + lowbit(x)=x&(-x)
* Segment Tree
* Examples: LC307, LC315

4. TrieTree: startsWith(s), longestPrefixOf(s), shortestPrefixOf(s), match(s) (wildcard: `.`)

5. Monotonic Stack/Queue: 返回前面/后面连续递增/递减的数字个数
https://www.cnblogs.com/grandyang/p/8887985.html

6. Fuzzy Match: LC676

7. Union Find 按秩合并，路径压缩(在根，秩=深度)
* Union(int i, int j);
* Find(int i);
* vector<int> _parents, _ranks

## 动态规划

1. 状态机: LC198
2. 字符串分割: LC139
3. 分组: LC1105
4. reconstruct: LC1092
5. 性能优化: 1269
