# leetcode notes

repo for my leetcode

## Notes:

* think before writing the code!!!
  
* 1.find the common way 2.find the break point 3.rebuild the code
  
* 循环遍历耗时太长，可用空间换时间，使用hash来进行直接寻找，不需要循环访问。(Two_Sum)
  
* 对null或者0的情况可以预处理排除，再对有内容的情况进行分类分析
  
* **最长回文串**：Manacher算法本质是中心扩展，分析了中心扩展时可以简化的计算部分（先字符串预处理，消除奇偶性）
  
* 单链，两点因子，一般不需要双重循环来遍历所有情况，试着分析问题特征，跳过不必要的计算
  
* **单链表常用技巧：**两个指针，增加头节点便于统一操作
  
* **按层遍历树：**
  
  ``` 
  1. add NULL to the queue, and iterate to the NULL, level up, add another NULL, be careful with the end case
  2. recursive with depth paremeter 
  3. record the num of node in the queue, then iterate num times as a round/level
  ```

* 联系图形，考虑问题

* 图形题目，分别考虑x,y， 分解，而不是当作整体考虑

* bit manipulation: usage of XOR, consider one bit, then the whole number
  - common trick: double XOR means nothing 
	- [single number](./singleNumber.cc)
	- [single numberII](./singleNumberII.cc)
	- [single numberIII](./singleNumberIII.cc)

* 分析结果的构成要素，逐个找到各个要素的求解方法

* Binary Tree Traversal, use O(1) space, no stack(morris traversal):
```
change the right child of predecessor to cur and change it back when get to it second time
rules:
  1. if the cur->left is NULL, cur = cur->right;
  2. if cur->left != NULL, find the predecessor(rightest of left subtree) 
    1) if predecessor->right == NULL, pre->right = cur, cur = cur->left
    2) if pre->right == cur, pre->right = NULL, cur = cur->right
  3. goto 1.
```             

* linked list cycle: 
	- two pointers: fast one and slow one, if the fast catches the slow then there is cycle
