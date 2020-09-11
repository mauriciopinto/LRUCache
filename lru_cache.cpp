#include "lru_cache.h"

/* Inserts a key value pair into the LRUCache instance. Takes
 * O(1) times, as it calls the get_hash_node (), hash_insert () and
 * hash_delete () subroutines, which all take O(1). It then verifies 
 * certain conditions to reorganize the data. */
void LRUCache::insertKeyValuePair (string key, int value) {
	Node *new_node = hash.get_hash_node (key);
        if (new_node) {                                 // If key exists
        	new_node->value = value;                // Update value
        	if (new_node == most_recent)            // If same key as most recent, return
                	return;
                if (new_node == least_recent)                   // If key is least recent, prev
                	least_recent = least_recent->prev;      // becomes least recent
                if (new_node->prev)                             // If key is within the middle of
                        new_node->prev->next = new_node->next;  // list, update prev and next pointer
                if (new_node->next)
                        new_node->next->prev = new_node->prev;
                new_node->next = most_recent;                   // most recent becomes the key's next
                most_recent->prev = new_node;                   // most recent prev becomes key
                most_recent = new_node;                         // new key becomes most recent
                return;
	}
        // If key does not yet exist
        new_node = new Node;                    // Create node for key          
        new_node->key = key;
        new_node->value = value;

        if (size != 0) {                        // If cache is not empty, most recent becomes key's
        	new_node->next = most_recent;   // next and key becomes most recent's prev
                most_recent->prev = new_node;
        } else least_recent = new_node;           // If cache is empty, least recent is set to key

        if (size < maxSize)
        	size++;
        else {                                          // If cache if full
        	hash.hash_delete (least_recent);        // Delete least recent from hash table
                least_recent = least_recent->prev;      // Least recent's prev becomes least recent
                least_recent->next = nullptr;           // Least recent becomes list's tail
        }

       	hash.hash_insert (new_node);            // Insert into hash table
        most_recent = new_node;                 // Key becomes most recent
}


/* Searches for the node corresponding to KEY and
 * returns its value. As it only calls for the
 * get_hash_node procedure, which takes O(key.size),
 * we can say it takes O(1) time. */
int LRUCache::getValueFromKey (string key) {
	Node *node = hash.get_hash_node (key);
	if (!node)
		return -1;
	if (node != most_recent) {
        	if (node == least_recent)                   // If key is least recent, prev
        		least_recent = least_recent->prev;      // becomes least recent
        	if (node->prev)                             // If key is within the middle of
        		node->prev->next = node->next;  // list, update prev and next pointer
        	if (node->next)
                	node->next->prev = node->prev;
        	node->next = most_recent;                   // most recent becomes the key's next
        	most_recent->prev = node;                   // most recent prev becomes key
        	most_recent = node;                         // new key becomes most recent
	}
	return node->value;
}

/* Returns most recent key. Takes O(1) because we are 
 * saving the most recent key in a pointer variable. */
string LRUCache::getMostRecentKey () {
	if (!most_recent)
        	return "none";
        return most_recent->key;
}

/* Optional functionality. Returns least recent key. */
string LRUCache::getLeastRecentKey () {
        if (!least_recent)
		return "none";
	return least_recent->key;
}
