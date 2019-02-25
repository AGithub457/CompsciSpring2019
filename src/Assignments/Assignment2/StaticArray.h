// Programmer: Armand Agopian
// Programmer's ID: 1612964

#ifndef COMPSCISPRING2019_STATICARRAY_H
#define COMPSCISPRING2019_STATICARRAY_H

template<typename V, int CAP>
class StaticArray {
    V values[CAP];
    V dummy;

public:
    StaticArray();

    int capacity() const { return CAP; }
    V operator[](int) const;
    V &operator[](int);
};

template<typename V, int CAP>
StaticArray<V, CAP>::StaticArray() {
    dummy = V();

    for (int i = 0; i < CAP; i++) {
        values[i] = dummy;
    }
}

template<typename V, int CAP>
V &StaticArray<V, CAP>::operator[](int index) {
    if (index < 0) return dummy;
    if (index >= CAP) return dummy;
    return values[index];
}

template<typename V, int CAP>
V StaticArray<V, CAP>::operator[](int index) const {
    if (index < 0) return dummy;
    if (index >= CAP) return dummy;
    return values[index];
}

#endif //COMPSCISPRING2019_STATICARRAY_H
