#include "lru_cache.h"

int main () {
	LRUCache lru (3);
	lru.insertKeyValuePair ("b", 2);
	lru.insertKeyValuePair ("a", 1);
	lru.insertKeyValuePair ("c", 3);
	cout << "most recent key: " << lru.getMostRecentKey () << endl;
	cout << "a: " << lru.getValueFromKey ("a") << endl;
	cout << "most recent key: " << lru.getMostRecentKey () << endl;
	lru.insertKeyValuePair ("d", 4);
	cout << "b: " << lru.getValueFromKey ("b") << endl;
	lru.insertKeyValuePair ("a", 5);
	cout << "a: " << lru.getValueFromKey ("a") << endl;
}
