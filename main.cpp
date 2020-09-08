#include "lru_cache.h"

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
