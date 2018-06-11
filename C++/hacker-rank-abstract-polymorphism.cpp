class LRUCache : public Cache {
    public:
        LRUCache(int c) { cp = c;}
        void set(int key, int value){
            Node * node;
            // Empty Map
            if(mp.empty()){
                node = new Node(key, value);
                head = tail = node;
                mp[key] = node;
            }
            auto it = mp.find(key);
            // This exists, so we need to re-set it to something
            if(it != mp.end()){
                it->second ->value = value;
                if(head == it->second) return;
                // This node should become the new head
                 it->second->prev->next = it->second->next;
                if(tail == it->second) //tail?
                    tail = tail->prev;
                else                   //in between?
                    it->second->next->prev = it->second->prev;

                it->second->next = head;
                it->second->prev = NULL;
                head->prev = it->second;
                head = it->second;
            } else {
            // Completely new node (insert to the head (FIFO))
                node = new Node(head->prev, head, key, value);
                head->prev = node;
                head = node;
                mp[key] = node;
                if(mp.size() > cp){
                    tail = tail->prev;
                    mp.erase(tail->next->key);
                    delete(tail->next);
                    tail->next = NULL;
                }
            }
        }
        int get(int key){
             auto it = mp.find(key);
             if(it != mp.end())
                return it->second->value;
             return -1;
        }
};
