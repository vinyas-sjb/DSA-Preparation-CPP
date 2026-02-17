# Stack (DSA)

## 📌 What is Stack?
- Linear data structure
- Follows **LIFO (Last In First Out)**
- Operations happen at one end (TOP)

---

## 🔧 Basic Operations
- Push
- Pop
- Top / Peek
- Empty

---

## 🏗 Stack Implementations
- Stack using Array
- Stack using Vector
- Stack using Linked List
- Stack using STL `list`

---

## 📂 Problems Covered
- Valid Parentheses
- Stock Span
- Next Greater Element

---

## ⏱ Time Complexity
| Operation | Complexity |
|---------|------------|
| Push | O(1) |
| Pop | O(1) |
| Top | O(1) |

---

## 🧠 Key Interview Points
- Stack behavior depends on operations, not storage
- Linked list + head operations = stack
- Monotonic stack solves range & span problems

---
## 🧠 Pattern Mapping
- | Parentheses / Undo | Stack |
- | Span / Range | Monotonic Stack |
- | Greater / Smaller | Monotonic Stack |
- | Histogram / Area | Stack + Indices |
---

## 🛠 Tools Used
- Language: C++
- IDE: VS Code

---




# LinkedList - Leetcode Problems

| Problem Name | Difficulty | Link |
| ------------- | ---------- | ---- |
| Valid Parenthesis | Easy | https://leetcode.com/problems/valid-parentheses/description/ |
| Stock Span | Medium | https://leetcode.com/problems/online-stock-span/description/ |
| Next Greater Element1 | Easy | https://leetcode.com/problems/next-greater-element-i/description/ |


# Stack Data Structure (Monotonic Stack Patterns)
## 📘 Monotonic Stack – Complete Cheat Sheet

### 🔹 Monotonic Increasing Stack
**Meaning**
- Elements increase from bottom to top
- Stack keeps only smaller elements

**Pop Rule**
- Pop while `stack.top() >= current`

**Used For**
- Previous Smaller Element
- Next Smaller Element
- Largest Rectangle in Histogram

**Why**
- Bigger elements are removed as they are not useful
- Stack top always gives nearest smaller element

---

### 🔹 Monotonic Decreasing Stack
**Meaning**
- Elements decrease from bottom to top
- Stack keeps only greater elements

**Pop Rule**
- Pop while `stack.top() <= current`

**Used For**
- Next Greater Element
- Previous Greater Element
- Stock Span Problem

**Why**
- Smaller elements are removed as they are not useful
- Stack top always gives nearest greater element

---

### 🔁 Direction Rule
- **Left side traversal → Previous element**
- **Right side traversal → Next element**

---

### 🧠 Memory Trick
- Smaller → Increasing Stack  
- Greater → Decreasing Stack  
- Previous → Left traversal  
- Next → Right traversal  

---

### 🎯 Interview One-Liner
> *“Monotonic stack removes useless elements so the stack top always gives the required answer in O(n).”*