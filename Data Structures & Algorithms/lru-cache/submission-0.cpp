class LRUCache {
public:
    class Node{
    public:
        int key;
        Node* next;

    public:
        Node(int key){
            this->key = key;
            next = nullptr;
        }
    };

    public:
        int capacity;
        unordered_map<int, int> cache;
        Node* head = nullptr;
        Node* tail = head;
        Node* temp = head;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        if(tail!=nullptr && tail->key == key){
            return cache[key];
        }

        temp=head;
        Node* tempKaPrev = nullptr;

        while(temp!=nullptr && temp->key!=key){
            tempKaPrev = temp;
            temp = temp->next;
        }

        if(temp==head){
            head = head->next;
        }
        else{
            tempKaPrev->next = temp->next;
        }

        tail->next = temp;
        temp->next = nullptr;
        tail = temp;

        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            cache[key] = value;
            Node* nodeToInsert = new Node(key);

            if(head==nullptr){
                head = nodeToInsert;
                tail = nodeToInsert;
            }
            else{
                tail->next = nodeToInsert;
                tail = nodeToInsert;
            }

            if(cache.size() > capacity){
                cache.erase(head->key);
                Node* nodeToDelete = head;
                head = head->next;
                delete nodeToDelete;

                if(head==nullptr){
                    tail = nullptr;
                }
            }
        }

        else{
            cache[key] = value;
            temp = head;

            if(tail!=nullptr && tail->key == key){
                return;
            }

            Node* tempKaPrev = nullptr;

            while(temp!=nullptr && temp->key!=key){
                tempKaPrev = temp;
                temp = temp->next;
            }

            if(temp==head){
                head = head->next;
            }
            else{
                tempKaPrev->next = temp->next;
            }

            tail->next = temp;
            temp->next = nullptr;
            tail = temp;
        }
    }
};
