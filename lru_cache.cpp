#include "lru_cache.h"

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

int LRUCache::getValueFromKey (string key) {
	Node *node = hash.get_hash_node (key);
	return node->value;
}

string LRUCache::getMostRecentKey () {
	if (!most_recent)
        	return "none";
        return most_recent->key;
}

string LRUCache::getLeastRecentKey () {
        if (!least_recent)
		return "none";
	return least_recent->key;
}
