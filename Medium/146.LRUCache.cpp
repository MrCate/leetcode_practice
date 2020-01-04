class LRUCache {
public:
    LRUCache(int capacity):capacity_(capacity) {
        
    }
    
    int get(int key) {
        if(hash_.find(key) == hash_.end()) //如果哈希表里没有键为key的 返回-1
            return -1;      
        else{
            int value = hash_[key]->second;//把哈希表的value值赋给value变量
            ls_.erase(hash_[key]);//断开双向链表中键为key的节点
            ls_.push_front(make_pair(key, value));//再把这个节点push到双向链表的头部
            hash_[key] = ls_.begin();
            return value;
        }
    }
    
    void put(int key, int value) {
        if(hash_.find(key) != hash_.end()) //如果访问的key在哈希表里，直接把这个节点释放，并放到双向链表头部
            ls_.erase(hash_[key]);
        else if(ls_.size()>=capacity_){ //如果当前cache数量不小于容量，把最不常使用的节点，即双向链表尾节点释放，并把当前访问的cache放在双向链表头部
            hash_.erase(ls_.back().first);
            ls_.pop_back();
        }
        ls_.push_front(make_pair(key, value));
        hash_[key] = ls_.begin();
    }
private:
    int capacity_;
    list<pair<int, int>> ls_; //双向链表
    unordered_map<int, list<pair<int, int>>::iterator>hash_; //哈希表
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */