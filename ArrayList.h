#include <iostream>

#define MAX_ARRAY_SIZE 100

using namespace std;

template<class T>
class ArrayList {
private:
    int length;
    T *element;
public:
    ArrayList();

    T get(int p);

    void add(T x, int p);

    void remove(int p);

    int find(T x);

    int next(int p);

    int first();

    bool empty();

    void show();

    int size();

    ~ArrayList();
};

template<class T>
ArrayList<T>::ArrayList() {
    length = 0;
    element = new T[MAX_ARRAY_SIZE];
}

template<class T>
T ArrayList<T>::get(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
    } else if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        return element[p];
    }
}

template<class T>
void ArrayList<T>::add(T x, int p) {
    if (p < 0 || p > length) {
        cout << "Invalid position." << endl;
    } else if (length == MAX_ARRAY_SIZE) {
        cout << "Memory overflow." << endl;
    } else if (length == 0 || length == p) {
        element[p] = x;
        length++;
    } else {
        for (int i = length - 1; i >= p; i--) {
            element[i + 1] = element[i];
        }
        element[p] = x;
        length++;
    }
}

template<class T>
void ArrayList<T>::remove(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
    } else if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        for (int i = p; i < length - 1; i++) {
            element[i] = element[i + 1];
        }
        length--;
    }
}

template<class T>
int ArrayList<T>::find(T x) {
    for (int i = 0; i < length; i++) {
        if (x == element[i])
            return i;
    }
    cout << "Item not found." << endl;
    return -1;
}

template<class T>
int ArrayList<T>::next(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
        return -1;
    } else {
        return (p + 1);
    }
}

template<class T>
int ArrayList<T>::first() {
    if (length == 0) {
        cout << "Empty list." << endl;
        return -1;
    } else {
        return 0;
    }
}

template<class T>
bool ArrayList<T>::empty() {
    if (length == 0) {
        return true;
    } else {
        return false;
    }
}

template<class T>
void ArrayList<T>::show() {
    if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        for (int i = 0; i < length; i++) {
            cout << element[i] << "\t";
        }
        cout << endl;
    }
}

template<class T>
int ArrayList<T>::size() {
    return length;
}

template<class T>
ArrayList<T>::~ArrayList() {
    delete[]element;
    length = 0;
}