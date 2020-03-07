# Implementation-of-LRU

Statement:​ Design and implement a data structure for LRU (Least
Recently Used) cache. It should support the following operations:

○ get(key) - Get the value (will always be positive) of the key if the key
exists in the cache, otherwise return -1.
○ set(key, value) - Set or insert the value if the key is not already
present. When the cache reaches its capacity, it should invalidate the
least recently used item before inserting the new item.

The LRU Cache will be initialized with an integer corresponding to its
capacity in the constructor. Capacity indicates the maximum number
of unique keys it can hold at a time.

Definition of “least recently used”: An access to an item is defined as a
get or a set operation of the item. “Least recently used” item is the one
with the oldest access time. You are free to use any data structure for
the problem.

Evaluation parameters​ : Efficiency and accuracy.
