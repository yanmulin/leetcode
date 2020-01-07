/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNodeComparator {
    int operator()(const ListNode *a, const ListNode *b) {
        if (a->val > b->val) return 1;
        else if (a->val < b->val) return -1;
        else return 0;
    }
};

template<typename T, typename Comparator>
class MinHeap {
private:
    T *_arr;
    size_t _n, _size;
    Comparator _comp;

    void sink(size_t i);
    void swim(size_t i);
    void resize(size_t n);
    void exch(size_t i, size_t j);
public:
    MinHeap();
    ~MinHeap();

    void insert(T e);
    T delMin();
    T min();
    size_t size();
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) return NULL;
        if (size == 1) return lists[0];
        ListNode dumy(0), *p = &dumy;
        MinHeap<ListNode*, ListNodeComparator> mh;
        for (int i=0;i<size;i++) {
            if (lists[i]) mh.insert(lists[i]);
        }
        while (mh.size() != 0) {
            ListNode *node = mh.delMin();
            p->next = new ListNode(node->val);
            p = p->next;
            if (node->next) mh.insert(node->next);
        }
        return dumy.next;
    }
};

template<typename T, typename Comparator>
MinHeap<T, Comparator>::MinHeap():_n(0), _size(1) {
    _arr = new T[1];
}
template<typename T, typename Comparator>
MinHeap<T, Comparator>::~MinHeap() { delete [] _arr; }

template<typename T, typename Comparator>
void MinHeap<T, Comparator>::insert(T e) {
    if (_n >= _size - 1) resize(_size * 2);
    _arr[++_n] = e;
    swim(_n);
}

template<typename T, typename Comparator>
T MinHeap<T, Comparator>::delMin() {
    T e = _arr[1];
    exch(1, _n--);
    sink(1);
    if (_n < _size / 4) resize(_size / 2);
    return e;
}

template<typename T, typename Comparator>
T MinHeap<T, Comparator>::min() {
    if (_n == 0) throw runtime_error("Empty heap");
    return _arr[1];
}

template<typename T, typename Comparator>
size_t MinHeap<T, Comparator>::size() {
    return _n;
}

// private
template<typename T, typename Comparator>
void MinHeap<T, Comparator>::resize(size_t n) {
    T *old = _arr;
    _arr = new T[n];
    memcpy(_arr, old, (_n+1) * sizeof(T));
    _size = n;
    delete [] old;
}

// private
template<typename T, typename Comparator>
void MinHeap<T, Comparator>::sink(size_t i) {
    while (i * 2 <= _n ) {
        size_t j = i * 2;
        if (j < _n && _comp(_arr[j + 1], _arr[j]) < 0) j++;
        if (_comp(_arr[i], _arr[j]) < 0) break;
        exch(i, j);
        i = j;
    }
}

// private
template<typename T, typename Comparator>
void MinHeap<T, Comparator>::swim(size_t i) {
    while (i > 1 && _comp(_arr[i], _arr[i/2]) < 0) {
        exch(i, i/2);
        i /= 2;
    }
}

// private
template<typename T, typename Comparator>
void MinHeap<T, Comparator>::exch(size_t i, size_t j) {
    T e = _arr[i];
    _arr[i] = _arr[j];
    _arr[j] = e;
}