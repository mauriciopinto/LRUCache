#include "hash.h"

/* Generates a secret key through a hash function. This
 * function sums the binary values of each character in KEY
 * and obtains returns the remainder. As it iterates through
 * KEY, this procedure takes O(key.size) time, which, for practical
 * reasons, we will approximate to O(1).*/
unsigned long Hash::hash (string key) {
	unsigned long bitset_sum = 0;			// Takes key and generates an unsigned long based on
        for (int i = 0; i < key.size (); i++) {		// its bits. Then returns that value mod (HASH_SIZE)
        	bitset<8> temp (key[i]);
                bitset_sum += temp.to_ulong ();
        }
        return bitset_sum % HASH_SIZE;
}

/* Returns the node corresponding to KEY. Takes
 * O(1) as it only calls the hash () subroutine. */
Node *Hash::get_hash_node (string key) {		// Finds the hash value for the key and returns
        size_t key_hash = hash (key);			// respective node
        Node *hash_node = nodes_ptr[key_hash];
        if (hash_node->active)
        	return hash_node;
	return nullptr;
};

/* Inserts NODE into the Hash instance. Takes O(1)
 * as it only calls the hash () subroutine */
void Hash::hash_insert (Node *node) {			// Finds the hash value for the key and inserts the
        node->active = true;				// node into the respective position
        int key_hash = hash (node->key);
        if (!nodes_ptr[key_hash]->active)
        	size++;
	nodes_ptr[key_hash] = node;
}

/* Deletes NODE from the Hash instance. Takes O(1)
 * as it only calls the hash () subroutine */
void Hash::hash_delete (Node *node) {			// Finds the hash value for the key and deletes the node
        int key_hash = hash (node->key);		// in the respective position
        nodes_ptr[key_hash]->active = false;
	size--;
}
