# LRUCache
## Data structures:
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
The **hash function** used for generating keys was a simple `key mod (HASH_SIZE)`.

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
## Time Complexity
The time complexity for the `insertKeyValuePair`, `getValueFromKey` and `getMostRecentKey` methods is O(1). We start by defining the worst-case runtime for the `Hash` class' methods:
- The `hash` method receives a key and generates a hash value by adding the binary values of all the characters in the key, and then finding the remainder of this value divided by `HASH_SIZE`. This method takes **O (key.size)**, but for practical reasons we will assume small sizes for keys and approximate it to **O(1)**.
- The `get_hash_node`, `hash_insert` and `hash_delete` call the `hash` method and execute constant-time operations afterward, so the time complexity for these three methods is **O(1)**.
The worst-case runtime for the `LRUCache` class' methods is directly related to the worst-case runtimes of the `Hash` class' methods:
-The `insertKeyValuePair` method makes calls to the `get_hash_node`, `hash_insert` and `hash_delete` subroutines, which all run in **O(1)**.
-The `getValueFromKey` method makes a call to the `get_hash_node` subroutine, which runs in **O(1)**.
-All the `getMostRecentKey` method does is dereference the `most_recent` node and update some pointers. This takes constant time **O(1)**.
-All the `getLeastRecentKey` method does is dereference the `least_recent` node and update some pointers. This takes constant time **O(1)**.
## Compilation
The source code is compiled with GNU compiler collection's C++ compiler through the use of a makefile. Running the following commands on the source directory generates the corresponding object and executable files and runs the main tests.
```
make
./lru_cache_tests
```
Running `make clean` removes all object and executable files.
