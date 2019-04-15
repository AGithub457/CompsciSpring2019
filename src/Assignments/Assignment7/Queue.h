// Programmer: Armand Agopian
// Programmer's ID: 1612964

#ifndef COMPSCISPRING2019_QUEUE_H
#define COMPSCISPRING2019_QUEUE_H

template<typename V>
class Queue {
    struct Node {
        V value;
        Node *next;
    };

    Node *firstNode; // the head pointer
    Node *lastNode;
    int siz; // tracking the number of nodes

public:
    Queue(); // may have a defaulted parameter
    Queue(const Queue<V> &); // copy constructor
    ~Queue();
    Queue<V> &operator=(const Queue<V> &);
    void push(const V &);
    const V &front() const; // return an immutable reference to the oldest node
    const V &back() const; // return an immutable reference to the newest node
    void pop(); // remove the oldest node
    int size() { return siz; }
    const;
    bool empty() const;
    void clear();
    const V &peek() const;
};

template<typename V>
Queue<V>::Queue() {
    firstNode = 0;
    lastNode = 0;
    siz = 0;
};

template<typename V>
void Queue<V>::push(const V &value) {
    Node *temp = new Node{value}; // C++11
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
    ++siz;
}
template<typename V>
Queue<V>::~Queue() {
    while (firstNode) {
        Node *p = firstNode;
        firstNode = firstNode->next;
        delete p;
    }
}
template<typename V>
Queue<V>::Queue(const Queue<V> &original) {
    firstNode = 0;
    lastNode = 0; // temporary tail
    siz = original.siz;
    for (Node *p = original.firstNode; p; p = p->next) {
        Node *temp = new Node;
        temp->value = p->value;
        temp->next = 0;
        if (lastNode) lastNode->next = temp;
        else firstNode = temp;
        lastNode = temp;
    }
}
template<typename V>
Queue<V> &Queue<V>::operator=(const Queue<V> &original) {
    if (this != &original) {
        // deallocate existing list
        while (firstNode) {
            Node *p = firstNode;
            firstNode = firstNode->next;
            delete p;
        }

        // build new queue
        Node *lastNode = 0; // temporary tail
        for (Node *p = original.firstNode; p; p = p->next) {
            Node *temp = new Node;
            temp->value = p->value;
            temp->next = 0;
            if (lastNode) lastNode->next = temp;
            else firstNode = temp;
            lastNode = temp;
        }
        siz = original.siz;
    }
    return *this;
}
template<typename V>
void Queue<V>::clear() {
    while (firstNode) {
        Node *p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}
template<typename V>
void Queue<V>::pop() {
    if (firstNode) {
        Node *p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}
template<typename V>
const V &Queue<V>::peek() const {
    if (firstNode == 0) {
        return V();
    }
    return firstNode->value;
}

#endif //COMPSCISPRING2019_QUEUE_H
