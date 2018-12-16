#include <iostream>

using namespace std;

template<class T>
struct node {
    T data;
    node<T> *next;
};

template<class T>
class LinkedList {
private:
    node<T> *head;
    int length;
public:
    LinkedList();

    T get(int p);

    void add(T x, int p);

    void remove(int p);

    int find(T x);

    int next(int p);

    int first();

    bool empty();

    void show();

    int size();

    ~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    length = 0;
}

template<class T>
T LinkedList<T>::get(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
    } else if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        node<T> *temp = new node<T>;
        temp = head;
        for (int i = 0; i < length && temp != NULL; i++) {
            if (i == p) {
                return temp->data;
            }
            temp = temp->next;
        }
    }
    return -1;
}

template<class T>
void LinkedList<T>::add(T x, int p) {
    if (p < 0 || p > length) {
        cout << "Invalid position." << endl;
    } else {
        if (p == 0) { // add at start
            node<T> *temp = new node<T>;
            temp->data = x;
            temp->next = head;
            head = temp;
            temp = NULL;
        } else if (p == length) { // add at end
            node<T> *temp1 = new node<T>;
            temp1 = head;
            while (temp1 != NULL && temp1->next != NULL) {
                temp1 = temp1->next;
            }
            node<T> *temp2 = new node<T>;
            temp2->data = x;
            temp2->next = NULL;
            temp1->next = temp2;
            temp1 = NULL;
            temp2 = NULL;
        } else { // add at pos
            node<T> *prev = new node<T>;
            node<T> *curr = new node<T>;
            node<T> *temp = new node<T>;
            curr = head;
            for (int i = 0; i < p; i++) {
                prev = curr;
                curr = curr->next;
            }
            temp->data = x;
            prev->next = temp;
            temp->next = curr;
        }
        length++;
    }
}

template<class T>
void LinkedList<T>::remove(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
    } else {
        node<T> *temp = new node<T>;
        if (p == 0) { // delete at start
            temp = head;
            head = head->next;
        } else { // delete at pos
            node<T> *curr = new node<T>;
            node<T> *prev = new node<T>;
            curr = head;
            for (int i = 0; i < p; i++) {
                prev = curr;
                curr = curr->next;
            }
            temp = curr;
            prev->next = curr->next;
        }
        delete temp;
        length--;
    }
}

template<class T>
int LinkedList<T>::find(T x) {
    node<T> *temp = new node<T>;
    temp = head;
    for (int i = 0; i < length && temp != NULL; i++) {
        if (temp->data == x) {
            return i;
        }
        temp = temp->next;
    }
    cout << "Item not found." << endl;
    return -1;
}

template<class T>
int LinkedList<T>::next(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
        return -1;
    } else {
        return (p + 1);
    }
}

template<class T>
int LinkedList<T>::first() {
    if (length == 0 || head == NULL) {
        return -1;
    } else {
        return 0;
    }
}

template<class T>
bool LinkedList<T>::empty() {
    if (length == 0) {
        return true;
    } else {
        return false;
    }
}

template<class T>
void LinkedList<T>::show() {
    if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        node<T> *temp = new node<T>;
        temp = head;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}

template<class T>
int LinkedList<T>::size() {
    return length;
}

template<class T>
LinkedList<T>::~LinkedList() {
    delete head;
    length = 0;
}
