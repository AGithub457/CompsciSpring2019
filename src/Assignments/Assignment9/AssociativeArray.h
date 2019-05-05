// Programmer: Armand Agopian
// Programmer's ID: 1612964

#ifndef COMPSCISPRING2019_ASSOCIATIVEARRAY_H
#define COMPSCISPRING2019_ASSOCIATIVEARRAY_H

#include <queue>

using namespace std;

template<typename K, typename V>
class AssociativeArray {
    struct Node {
        K key;
        V value;
        bool inUse;
    };

    Node *values;
    int siz = 0;
    int cap = 0;
    void capacity(int);

public:
    AssociativeArray(int = 2);
    AssociativeArray(const AssociativeArray<K, V> &);
    AssociativeArray<K, V> &operator=(const AssociativeArray<K, V> &);
    ~AssociativeArray() { clear(); }
    V &operator[](const K &) const;
    V &operator[](const K &);
    bool containsKey(const K &) const;
    void deleteKey(const K &);
    queue<K> keys() const;
    int size() const { return siz; }
    void clear();
};

template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(int cap) {
    this->cap = cap;
    values = new Node[cap];
    for (int i = 0; i < cap; i++)
        values[i].inUse = false;
}

template<typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V> &original) {
    siz = original.siz;
    values = new Node[cap];
    for (int i = 0; i < cap; i++) {
        values[i] = original.values[i];
    }
}

template<typename K, typename V>
V &AssociativeArray<K, V>::operator[](const K &key) {
    int indexOfFirstUnusedKey = cap;
    for (int index = 0; index < cap; index++) {
        if (values[index].inUse) {
            if (values[index].key == key) {
                return values[index].value;
            }
        } else {
            indexOfFirstUnusedKey = index;
            break;
        }
    }


    if (indexOfFirstUnusedKey == cap) {
        capacity(2 * cap);
    }
    values[indexOfFirstUnusedKey].key = key;
    values[indexOfFirstUnusedKey].value = V();
    values[indexOfFirstUnusedKey].inUse = true;
    ++siz;
    return values[indexOfFirstUnusedKey].value;
}

template<typename K, typename V>
queue<K> AssociativeArray<K, V>::keys() const {
    queue<K> k_queue;
    for (int i = 0; i < cap; ++i) {
        if (values[i].inUse) {
            k_queue.push(values[i].key);
        }
    }
    return k_queue;
}



template<typename K, typename V>
AssociativeArray<K, V> &AssociativeArray<K, V>::operator=(const AssociativeArray<K, V> &original) {
    if (this != &original) {
        delete[] values;
        cap = original.cap;
        siz = original.siz;
        values = new Node[cap];
        for (int i = 0; i < cap; i++)
            values[i] = original.values[i];
    }
    return *this;
}

template<typename K, typename V>
V &AssociativeArray<K, V>::operator[](const K &key) const {
    for (int i = 0; i < cap; ++i) {
        if (values[i].inUse && values[i].key == key) {
            return values[i].value;
        }
    }
    return V();
}

template<typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K &key) const {
    for (int i = 0; i < cap; i++) {
        if (values[i].inUse && values[i].key == key) {
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K &key) {
    for (int i = 0; i < cap; i++) {
        if (values[i].key == key) {
            values[i].inUse = false;
            siz--;
            return;
        }
    }
}

template<typename K, typename V>
void AssociativeArray<K, V>::clear() {
    for (int i = 0; i < cap; i++) {
        values[i].inUse = false;
    }
    siz = 0;
    delete[] values;
}

template<typename K, typename V>
void AssociativeArray<K, V>::capacity(int cap) {
    Node *temp = new Node[cap];
    int limit;
    if (cap < this->cap) {
        limit = cap;
    } else {
        limit = this->cap;
    }
    for (int i = 0; i < limit; i++) {
        temp[i] = values[i];
    }
    for (int i = limit; i < cap; i++) {
        temp[i].inUse = false;
        temp[i].key = K();
        temp[i].value = V();
    }
    this->cap = cap;
    delete[] values;
    values = temp;
}

#endif //COMPSCISPRING2019_ASSOCIATIVEARRAY_H
