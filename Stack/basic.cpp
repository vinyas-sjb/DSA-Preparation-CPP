/*
================ STACK – QUICK INTERVIEW NOTES ================

STACK:
• LIFO (Last In First Out)
• Operations at ONE END (TOP)

------------------------------------------------
STACK USING ARRAY
------------------------------------------------
• Storage: Contiguous
• Push: arr[++top]        → O(1)
• Pop : top--             → O(1)
• Top : arr[top]          → O(1)
• Overflow: top == size-1
• Underflow: top == -1

------------------------------------------------
STACK USING VECTOR
------------------------------------------------
• Dynamic array
• Push: vector.push_back() → O(1) amortized
• Pop : vector.pop_back()  → O(1)
• Top : vector.back()      → O(1)

------------------------------------------------
STACK USING LINKED LIST
------------------------------------------------
• Dynamic nodes + pointers
• Push: insert at head     → O(1)
• Pop : delete head        → O(1)
• Top : head->data         → O(1)
• No overflow

------------------------------------------------
STACK USING STL list
------------------------------------------------
• Doubly Linked List
• Push: list.push_front() → O(1)
• Pop : list.pop_front()  → O(1)
• Top : list.front()      → O(1)

------------------------------------------------
ARRAY vs LINKED LIST STACK
------------------------------------------------
• Array: Faster, fixed size
• LL   : Dynamic size, extra memory

================================================
*/