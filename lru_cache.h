#include "hash.h"

class LRUCache {
        private:
                unsigned maxSize, size;
                Node *most_recent, *least_recent;
                Hash hash;
        public:
                LRUCache (unsigned maxSize) : maxSize (maxSize), size (0), most_recent (nullptr), least_recent (nullptr) {}

                void insertKeyValuePair (string key, int value);

                int getValueFromKey (string key);

                string getMostRecentKey (); 

                string getLeastRecentKey (); 
};
