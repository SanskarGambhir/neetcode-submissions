class LRUCache {
public:
    class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

    public:
        Node(int key, int value){
            this->key = key;
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    public:
        int capacity;
        unordered_map<int, Node*> cache;
        Node* head = nullptr;
        Node* tail = head;
        Node* temp = head;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            temp = cache[key];

            if(temp==tail){
                return temp->value;
            }
            else if(temp == head){
                head = head->next;
                head->prev = nullptr;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            temp->next = nullptr;
            return temp->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            Node* nodeToInsert = new Node(key, value);
            cache[key] = nodeToInsert;

            if(head==nullptr){
                head = nodeToInsert;
                tail = nodeToInsert;
            }
            else{
                tail->next = nodeToInsert;
                nodeToInsert->prev = tail;
                tail = nodeToInsert;
            }

            if(cache.size() > capacity){
                cache.erase(head->key);
                Node* nodeToDelete = head;
                head = head->next;
                head->prev = nullptr;
                delete nodeToDelete;
            }
        }
        else{
            temp = cache[key];
            temp->value = value;

            if(temp==tail){
                return;
            }
            else if(temp==head){
                head = head->next;
                head->prev = nullptr;
            }
            else{
                temp->prev->next = temp->next;

                temp->next->prev = temp->prev;
            }

            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            temp->next = nullptr;
        }
    }
};
