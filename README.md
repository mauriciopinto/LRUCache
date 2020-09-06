# LRUCache
##Data structures:
LRU Cache was implemented as the `LRUCache` class:
```
class LRUCache {
        private:
                unsigned maxSize, size;
                Node *most_recent, *least_recent;
                Hash hash;
                ...
```
It uses a very basic _hash table_ implementation for storing and accessing data in O(1) time complexity. It can store up to `HASH_SIZE` "key-value" pairs. I have been initially defining `HASH_SIZE`'s value as 1000. This hash table was implemented as the `Hash` class:
```
class Hash {
        private:
                unsigned size;
                Node *nodes_ptr[HASH_SIZE];
        ...
```
The `LRUCache` class also makes use of a _doubly-linked_ list
