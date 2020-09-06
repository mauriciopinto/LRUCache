#include <bits/stdc++.h>
#include <cstring>

#define HASH_SIZE 1000

using namespace std;

struct Node {
	bool active = false;
	string key;
	int value;
	Node *next = nullptr;
	Node *prev = nullptr;
};

class Hash {
	private:
		unsigned size;
		Node *nodes_ptr[HASH_SIZE];
	public:
		Hash () : size (0) {
			for (int i = 0; i < HASH_SIZE; i++)
				nodes_ptr[i] = new Node;
		}
		
		unsigned long hash (string key) {
			unsigned long bitset_sum = 0;
			for (int i = 0; i < key.size (); i++) {
				bitset<8> temp (key[i]);	
				bitset_sum += temp.to_ulong ();
			}
			return bitset_sum % HASH_SIZE;
		}

		Node *get_hash_node (string key) {
			if (size == 0)
				return nullptr;
			size_t key_hash = hash (key);
			Node *hash_node = nodes_ptr[key_hash];
			if (hash_node->active)
				return hash_node;
			return nullptr;
		};

		void hash_insert (Node *node) {
			node->active = true;
			int key_hash = hash (node->key);
			if (!nodes_ptr[key_hash]->active)
				size++;
			nodes_ptr[key_hash] = node;
		}

		void hash_delete (Node *node) {
			int key_hash = hash (node->key);
			nodes_ptr[key_hash]->active = false;
			size--;
		}
};

class LRUCache {
	private:
		unsigned maxSize, size;
		Node *most_recent, *least_recent;
		Hash hash;
	public:
		LRUCache (unsigned maxSize) : maxSize (maxSize), size (0), most_recent (nullptr), least_recent (nullptr) {}

		void insertKeyValuePair (string key, int value) {
			Node *new_node = hash.get_hash_node (key);
			if (new_node) {
				new_node->value = value;
				if (new_node == most_recent) return;
				if (new_node == least_recent) least_recent = least_recent->prev;
				if (new_node->prev)
					new_node->prev->next = new_node->next;
				if (new_node->next)
					new_node->next->prev = new_node->prev;
				new_node->next = most_recent;
				most_recent = new_node;
				return;
			}

			new_node = new Node;
			new_node->key = key;
			new_node->value = value;

			if (size < maxSize) {
				if (size == 0) {
					least_recent = new_node;
				}
				else {
					new_node->next = most_recent;
					most_recent->prev = new_node;
				}
				hash.hash_insert (new_node);
				most_recent = new_node;
				size++;
			}
			else {
				hash.hash_delete (least_recent);
				least_recent = least_recent->prev;
				least_recent->next = nullptr;
				hash.hash_insert (new_node);
				new_node->next = most_recent;
				most_recent = new_node;
			}
		}

		int getValueFromKey (string key) {
			Node *node = hash.get_hash_node (key);
			return node->value;
		}

		string getMostRecentKey () {
			if (!most_recent)
				return "none";
			return most_recent->key;
		}

		string getLeastRecentKey () {
			if (!least_recent)
				return "none";
			return least_recent->key;
		}
};

int main () {
	LRUCache lru (3);
	lru.insertKeyValuePair ("b", 2);
	lru.insertKeyValuePair ("c", 3);
	lru.insertKeyValuePair ("a", 1);
	lru.insertKeyValuePair ("a", 5);
	lru.insertKeyValuePair ("f", 1);
	lru.insertKeyValuePair ("c", 4);
	lru.insertKeyValuePair ("f", 2);
	lru.insertKeyValuePair ("c", 7);
	cout << lru.getMostRecentKey () << endl;
	cout << lru.getLeastRecentKey () << endl;
}
