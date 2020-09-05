#include <bits/stdc++.h>
#include <cstring>

using namespace std;

struct Node {
	string key;
	int value;
	Node *next;
};

class Hash {
	private:
		unsigned maxSize, size;
		Node *nodes;
	public:
		Hash (unsigned maxSize) : maxSize (maxSize) {
			nodes = new Node[maxSize];
		}

		Node *get_hash_node (string key) {
			if (size == 0)
				return nullptr;
			size_t key_hash = atoi (key.c_str ()) % maxSize;
			return &nodes[key_hash];
		};

		void hash_insert (Node *node) {
			int key_hash = atoi (node->key.c_str ()) % maxSize;
			nodes[key_hash] = *node;
			size++;
		}

		void hash_delete (Node *node) {
			int key_hash = atoi (node->key.c_str ()) % maxSize;
			size--;
		}
};

class LRUCache {
	private:
		unsigned maxSize, size;
		Node *most_recent;
		Hash hash{maxSize};
	public:
		LRUCache (unsigned maxSize) : maxSize (maxSize) {}

		void insertKeyValuePair (string key, int value) {
			Node *new_node = hash.get_hash_node (key);
			if (new_node) {
				new_node->value = value;
				return;
			}

			new_node = new Node;
			new_node->key = key;
			new_node->value = value;

			if (size < maxSize) {
				hash.hash_insert (new_node);
				new_node->next = most_recent;
				most_recent = new_node;
				size++;
			}
			else {
				hash.hash_insert (new_node);
			}
		}

		int getValueFromKey (string key) {
			Node *node = hash.get_hash_node (key);
			return node->value;
		}

		string getMostRecentKey () {
			return most_recent->key;
		}
};

int main () {
	LRUCache c = LRUCache (3);
	c.insertKeyValuePair ("b", 2);
	c.getMostRecentKey ();
	c.getValueFromKey ("b");
}
