# LRUCache
# # Data structures:
LRU Cache was implemented as the `LRUCache` class:
```
class LRUCache {
        private:
                unsigned maxSize, size;
                Node *most_recent, *least_recent;
                Hash hash;
                ...
```
It uses a very basic **hash table** implementation for storing and accessing data in O(1) time complexity. It can store up to `HASH_SIZE` "key-value" pairs. I have been initially defining `HASH_SIZE`'s value as 1000. This hash table was implemented as the `Hash` class:
```
class Hash {
        private:
                unsigned size;
                Node *nodes_ptr[HASH_SIZE];
        ...
```
The `LRUCache` class also makes use of a **doubly-linked** list, keeping track of the `least_recent` and `most_recent` nodes. These were used to implement its LRU eviction policy. `most_recent` served as the list's head and `least_recent`as the list's tail.

The `Node` structured served as both hash table nodes (pairs) and linked list nodes (elements). It was implemented as follows:
```
struct Node {
        bool active = false;
        string key;
        int value;
        Node *next = nullptr;
        Node *prev = nullptr;
};
```
The `active` attribute was used to keep track of which nodes were actually being used, in case collision ever occurs between distinct hash keys. This way, all the `hash_delete` method does is change this value to zero.
