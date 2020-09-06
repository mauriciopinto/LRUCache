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
