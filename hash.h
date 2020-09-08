#include "node.h"
class Hash {
        private:
                unsigned size;
                Node *nodes_ptr[HASH_SIZE];
	protected:	
		unsigned long hash (string key);
		Node *get_hash_node (string key);
        public:
                Hash () : size (0) {
                        for (int i = 0; i < HASH_SIZE; i++)
                                nodes_ptr[i] = new Node;
                }

                void hash_insert (Node *node);

                void hash_delete (Node *node);
	
	friend class LRUCache;
};
