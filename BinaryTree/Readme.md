# Binary Tree (DSA)

## 📌 What is Binary Tree?

* A **hierarchical data structure**
* Each node has **at most two children**
* Children are called **left child** and **right child**

---

## 🔧 Basic Terminology

* Root
* Parent
* Child
* Leaf Node
* Subtree
* Height
* Depth

---

## 🔁 Tree Traversals

### Depth First Traversal (DFS)

* Preorder (Root → Left → Right)
* Inorder (Left → Root → Right)
* Postorder (Left → Right → Root)

### Breadth First Traversal (BFS)

* Level Order Traversal

---

## 📂 Problems Covered

* Build Binary Tree (Preorder sequence)
* Height of Binary Tree
* Count Number of Nodes
* Sum of Nodes
* Diameter of Binary Tree
* Identical Trees
* Subtree of Another Tree
* Lowest Common Ancestor (LCA)
* Level Order Traversal
* Top View of Binary Tree
* Binary Tree Paths
* Transform to Sum Tree
* Build Tree from Preorder + Inorder

---

# BinaryTree - LeetCode Problems

| Problem Name | Difficulty | Link |
|-------------|------------|------|
| Maximum Depth of Binary Tree (Height) | Easy | https://leetcode.com/problems/maximum-depth-of-binary-tree/ |
| Count Complete Tree Nodes | Easy | https://leetcode.com/problems/count-complete-tree-nodes/ |
| Diameter of Binary Tree | Easy | https://leetcode.com/problems/diameter-of-binary-tree/ |
| Same Tree (Identical Trees) | Easy | https://leetcode.com/problems/same-tree/ |
| Subtree of Another Tree | Easy | https://leetcode.com/problems/subtree-of-another-tree/ |
| Lowest Common Ancestor of a Binary Tree | Medium | https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/ |
| Binary Tree Level Order Traversal | Medium | https://leetcode.com/problems/binary-tree-level-order-traversal/ |
| Binary Tree Paths | Easy | https://leetcode.com/problems/binary-tree-paths/ |
| Construct Binary Tree from Preorder and Inorder Traversal | Medium | https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ |
| Binary Tree Maximum Width | Medium | https://leetcode.com/problems/maximum-width-of-binary-tree/ |

---

## ⏱ Time Complexity

| Operation            | Complexity |
| -------------------- | ---------- |
| Traversal            | O(n)       |
| Height Calculation   | O(n)       |
| Count Nodes          | O(n)       |
| Diameter (Optimized) | O(n)       |

---

## 🧠 Key Interview Points

* Most Binary Tree problems use **recursion**
* Tree recursion usually processes **left subtree and right subtree**
* Many problems follow **postorder traversal pattern**
* Tree height and subtree results are often returned from recursion

---

## 🧠 Pattern Mapping

| Problem Type         | Pattern                  |
| -------------------- | ------------------------ |
| Height / Count / Sum | Recursion                |
| Diameter             | Recursion + Height       |
| LCA                  | Divide & Conquer         |
| Top View             | BFS + Map                |
| Tree Paths           | Recursion + Backtracking |
| Build Tree           | Traversal + Recursion    |

---

## 🧠 Common Recursion Pattern

```id="t2z4ok"
if(root == NULL)
    return base_value;

left = solve(root->left);
right = solve(root->right);

return combine(left, right);
```

---

## 🛠 Tools Used

* Language: C++
* IDE: VS Code
* Practice Platforms: LeetCode, GeeksforGeeks

---

## 🎯 Learning Goal

* Understand recursion patterns in trees
* Practice common Binary Tree interview problems
* Strengthen DSA problem solving

---

## 🧠 Pattern Mapping

| Problem Type                    | Pattern Used                |
| ------------------------------- | --------------------------- |
| Height / Count / Sum of Nodes   | Simple Recursion            |
| Diameter of Binary Tree         | Recursion + Height          |
| Identical Trees                 | Tree Comparison             |
| Subtree of Another Tree         | Traversal + Tree Comparison |
| Lowest Common Ancestor (LCA)    | Divide & Conquer            |
| Level Order Traversal           | BFS + Queue                 |
| Top View of Binary Tree         | BFS + Map                   |
| Binary Tree Paths               | Recursion + Backtracking    |
| Transform to Sum Tree           | Postorder Traversal         |
| Build Tree (Preorder + Inorder) | Traversal + Recursion       |

---

## 🌳 Recursion Patterns in Binary Trees

### 🔹 Return Value Recursion

**Meaning**

* Function returns value from left and right subtree

**Example Use**

* Height of Binary Tree
* Count Nodes
* Sum of Nodes

**Pattern**

```cpp
if(root == NULL)
    return 0;

int left = solve(root->left);
int right = solve(root->right);

return left + right + 1;
```

---

### 🔹 Compare Left & Right Subtrees

**Meaning**

* Solve both subtrees and combine result

**Example Use**

* Height of Binary Tree
* Diameter of Binary Tree

**Pattern**

```cpp
int left = height(root->left);
int right = height(root->right);

return max(left, right) + 1;
```

---

### 🔹 Modify Tree While Traversing

**Meaning**

* Update node value using results from subtrees

**Example Use**

* Transform to Sum Tree
* Flatten Binary Tree

**Pattern**

```cpp
int left = transform(root->left);
int right = transform(root->right);

root->data = left + right;
```

---

### 🔁 Traversal Direction Guide

| Traversal   | Order               |
| ----------- | ------------------- |
| Preorder    | Root → Left → Right |
| Inorder     | Left → Root → Right |
| Postorder   | Left → Right → Root |
| Level Order | BFS using Queue     |

---

### 🎯 Interview One-Liner

> *“Most Binary Tree problems are solved using recursion where we process left subtree, right subtree, and then combine the results.”*
