// Programmer: Armand Agopian
// Programmer's ID: 1612964

#ifndef COMPSCISPRING2019_STACK_H
#define COMPSCISPRING2019_STACK_H

template <typename V>
class Stack {
    V *values;
    V dummy;
    int cap;
    int siz;
    void capacity(int);

public:
    Stack(int = 2);
    Stack(const Stack<V>&);
    ~Stack() {delete[] values;};
    Stack<V>& operator=(const Stack<V>&);
    void push(const V&);
    const V& peek() const;
    void pop() {if (siz > 0) --siz;};
    int size() const {return siz;};
    bool empty() const {return (siz == 0);};
    void clear() {siz = 0;};
};

template<typename V>
Stack<V>::Stack(int cap) {
    dummy = V();

    this->cap = cap;
    values = new V[cap];
    for (int i = 0; i < cap; i++) {
        values[i] = dummy;
    }

    siz = 0;
}

template<typename V>
Stack<V>::Stack(const Stack<V> &original) {
    cap = original.cap;
    values = new V[cap];

    for (int i = 0; i < cap; i++) {
        values[i] = original.values[i];
    }

    siz = original.siz;
}

template<typename V>
Stack<V> &Stack<V>::operator=(const Stack<V> &original) {
    if (this != &original) {
        delete[] values;

        cap = original.cap;
        values = new V[cap];

        for (int i = 0; i < cap; i++) {
            values[i] = original.values[i];
        }
    }

    siz = original.siz;

    return *this;
}

template <typename V>
void Stack<V>::push(const V& value)
{
    if (siz == cap) capacity(2 * cap);
    values[siz] = value;
    ++siz;
}

template<typename V>
const V &Stack<V>::peek() const {
    if ((siz - 1) < 0) {
        return dummy;
    }
    return values[siz - 1];
}

template<typename V>
void Stack<V>::capacity(int cap) {
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

#endif //COMPSCISPRING2019_STACK_H
