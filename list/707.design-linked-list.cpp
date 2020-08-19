class MyLinkedList {
private:
    struct LinkedList {
        int val;
        LinkedList *next;
        LinkedList(int v): val(v), next(NULL) {}
    };
    LinkedList *_head, *_tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList(): _head(NULL), _tail(NULL) {}
    ~MyLinkedList() {
        LinkedList *p;
        while (_head) {
            p = _head;
            _head = _head->next;
            delete p;
        }
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        LinkedList *p = _head;
        while (p && index-- > 0) p = p->next;
        if (!p) return -1;
        else return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedList *p = new LinkedList(val);
        p->next = _head;
        _head = p;
        if (!_tail) _tail = p;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedList *p = new LinkedList(val);
        if (_tail) {
            _tail->next = p;
            _tail = p;
        } else _head = _tail = p;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        LinkedList dummy(0), *p = &dummy;
        dummy.next = _head;
        while (p && index-- > 0) p = p->next;
        if (!p) return;
        LinkedList *node = new LinkedList(val);
        node->next = p->next;
        p->next = node;
        _head = dummy.next;
        if (!_tail) _tail = _head;
        else if (_tail == p) _tail = node;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        LinkedList dummy(0), *p = &dummy, *tmp;
        dummy.next = _head;
        while (p && index-- > 0) p = p->next;
        if (!p || !p->next) return;
        tmp = p->next;
        p->next = tmp->next;
        _head = dummy.next;
        if (!_head) _tail = NULL;
        else if (_tail == tmp) _tail = p;
        delete tmp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

