// Programmer: Armand Agopian
// Programmer's ID: 1612964

#ifndef COMPSCISPRING2019_DYNAMICARRAY_H
#define COMPSCISPRING2019_DYNAMICARRAY_H

#include <algorithm>

template<typename V>
class DynamicArray {
    V *values;
    V dummy;
    int cap;

public:
    DynamicArray(int = 2);
    ~DynamicArray() { delete[] values; }

    int capacity() const { return cap; }
    void capacity(int);
    V operator[](int) const;
    V &operator[](int);
    DynamicArray(const DynamicArray<V> &);
    DynamicArray<V> &operator=(const DynamicArray<V> &);
};

template<typename V>
DynamicArray<V>::DynamicArray(int cap) {
    dummy = V();

    this->cap = cap;
    values = new V[cap];
    for (int i = 0; i < cap; i++) {
        values[i] = dummy;
    }
}

template<typename V>
void DynamicArray<V>::capacity(int cap) {
    V *temp = new V[cap];
    int limit = min(cap, this->cap);

    for (int i = 0; i < limit; i++) {
        temp[i] = values[i];
    }
    for (int i = limit; i < cap; i++) {
        temp[i] = V();
    }

    delete[] values;
    values = temp;
    this->cap = cap;
}

template<typename V>
V &DynamicArray<V>::operator[](int index) {
    if (index < 0) return dummy;
    if (index >= cap) capacity(2 * index);
    return values[index];
}

template<typename V>
V DynamicArray<V>::operator[](int index) const {
    if (index < 0) return dummy;
    if (index >= cap) return dummy;
    return values[index];
}

template<typename V>
DynamicArray<V>::DynamicArray(const DynamicArray<V> &original) {
    cap = original.cap;
    values = new V[cap];

    for (int i = 0; i < cap; i++) {
        values[i] = original.values[i];
    }
}

template<typename V>
DynamicArray<V> &DynamicArray<V>::operator=(const DynamicArray<V> &original) {
    if (this != &original) {
        delete[] values;

        cap = original.cap;
        values = new V[cap];

        for (int i = 0; i < cap; i++) {
            values[i] = original.values[i];
        }
    }

    return *this;
}

#endif //COMPSCISPRING2019_DYNAMICARRAY_H
