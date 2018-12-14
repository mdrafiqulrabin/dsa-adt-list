#include <iostream>
#define MAX_ARRAY_SIZE 100

using namespace std;

template <class T>
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

template <class T>
ArrayList<T> :: ArrayList() {
    length = 0;
    element = new T[MAX_ARRAY_SIZE];
}

template <class T>
T ArrayList<T> :: get(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
    } else if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        return element[p];
    }
}

template <class T>
void ArrayList<T> :: add(T x, int p) {
    if (p < 0 || p > length) {
        cout << "Invalid position." << endl;
    } else if (length == MAX_ARRAY_SIZE) {
        cout << "Memory overflow." << endl;
    } else if (length == 0 || length == p) {
        element[p] = x;
        length++;
    } else {
        for (int i=length-1; i>=p; i--) {
            element[i+1] = element[i];
        }
        element[p] = x;
        length++;
    }
}

template <class T>
void ArrayList<T> :: remove(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
    } else if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        for (int i=p; i<length-1; i++) {
            element[i] = element[i+1];
        }
        length--;
    }
}

template <class T>
int ArrayList<T> :: find(T x) {
    for(int i=0; i<length; i++) {
        if (x == element[i])
            return i;
    }
    cout << "Item not found." << endl;
    return -1;
}

template <class T>
int ArrayList<T> :: next(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
        return -1;
    } else {
        return (p+1);
    }
}

template <class T>
int ArrayList<T> :: first() {
    if (length == 0) {
        cout << "Empty list." << endl;
        return -1;
    } else {
        return 0;
    }
}

template <class T>
bool ArrayList<T> :: empty() {
    if (length == 0) {
        return true;
    } else {
        return false;
    }
}

template <class T>
void ArrayList<T> :: show() {
    if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        for(int i=0; i<length; i++) {
            cout << element[i] << "\t";
        }
        cout << endl;
    }
}

template <class T>
int ArrayList<T> :: size() {
    return length;
}

template <class T>
ArrayList<T> :: ~ArrayList() {
    delete[]element;
    length = 0;
}

/*-------x-------x-------*/

template <class T>
struct node {
    T data;
    node<T> *next;
};

template <class T>
class LinkedList {
private:
    node<T> *head;
    int length;
public:
    LinkedList();
    T get(int p);
    void add(T x, int p);
    void add2(T x, int p);
    void remove(int p);
    int find(T x);
    int next(int p);
    int first();
    bool empty();
    void show();
    int size();
    ~LinkedList();
};

template <class T>
LinkedList<T> :: LinkedList() {
    head = NULL;
    length = 0;
}

template <class T>
T LinkedList<T> :: get(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
    } else if (length == 0) {
        cout << "Empty list." << endl;
    } else {
        node<T> *temp = new node<T>;
        temp = head;
        for (int i=0; i<length && temp != NULL; i++) {
            if (i == p) {
                return temp->data;
            }
            temp = temp->next;
        }
    }
    return -1;
}

template <class T>
void LinkedList<T> :: add(T x, int p) {
    if (p < 0 || p > length) {
        cout << "Invalid position." << endl;
    } else {
        if (p == 0) { //add at start
            node<T> *temp = new node<T>;
            temp -> data = x;
            temp -> next = head;
            head = temp;
            temp = NULL;
        } else if (p == length) { //add at end
            node<T> *temp1 = new node<T>;
            temp1 = head;
            while (temp1 != NULL && temp1 -> next != NULL) {
                temp1 = temp1 -> next;
            }
            node<T> *temp2 = new node<T>;
            temp2 -> data = x;
            temp2 -> next = NULL;
            temp1 -> next = temp2;
            temp1 = NULL;
            temp2 = NULL;
        } else { //add at pos
            node<T> *prev  = new node<T>;
            node<T> *curr  = new node<T>;
            node<T> *temp = new node<T>;
            curr = head;
            for (int i=0; i<p; i++) {
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

template <class T>
void LinkedList<T> :: remove(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
    } else {
        node<T> *temp = new node<T>;
        if (p==0) {//delete at start
            temp = head;
            head = head->next;
        } else {//delete at pos
            node<T> *curr = new node<T>;
            node<T> *prev = new node<T>;
            curr = head;
            for (int i=0; i<p; i++) {
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

template <class T>
int LinkedList<T> :: find(T x) {
    node<T> *temp = new node<T>;
    temp = head;
    for (int i=0; i<length && temp != NULL; i++) {
        if (temp->data == x) {
            return i;
        }
        temp = temp->next;
    }
    cout << "Item not found." << endl;
    return -1;
}

template <class T>
int LinkedList<T> :: next(int p) {
    if (p < 0 || p >= length) {
        cout << "Invalid position." << endl;
        return -1;
    } else {
        return (p+1);
    }
}

template <class T>
int LinkedList<T> :: first() {
    if (length == 0 || head == NULL) {
        return -1;
    } else {
        return 0;
    }
}

template <class T>
bool LinkedList<T> :: empty() {
    if (length == 0) {
        return true;
    } else {
        return false;
    }
}

template <class T>
void LinkedList<T> :: show() {
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

template <class T>
int LinkedList<T> :: size() {
    return length;
}

template <class T>
LinkedList<T> :: ~LinkedList() {
    delete head;
    length = 0;
}

/*-------x-------x-------*/

template <class T>
void purge(T &list) {
    int p,q;
    p = list.first();
    while (p != list.size()) {
        q = list.next(p);
        while (q != list.size()) {
            if (list.get(p) == list.get(q)) {
                list.remove(q);
            } else {
                q = list.next(q);
            }
        }
        p = list.next(p);
    }
}

template <class T>
int getMaxSum(T &list) {
    int n = list.size();
    int maxSum = 0;
    for (int lb=0; lb<n; lb++) {
        for(int ub=lb; ub<n; ub++) {
            int sum = 0;
            for (int i=lb; i<=ub; i++) {
                sum += list.get(i);
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

/*-------x-------x-------*/

void testArrayListForInt();
void testArrayListForChar();
void testLinkedListForInt();
void testLinkedListForChar();

int main() {
    //Test arrayList for Int and Char
    testALWInt();
    testALWChar();

    //Test linkedList for Int and Char
    testLLWInt();
    testLLWChar();

    return 0;
}

/*-------x-------x-------*/

void testArrayListForInt() {
    cout << endl << "Test arrayList for Int:" << endl;

    ArrayList<int> llist;

    llist.add(0,0);
    llist.add(1,1);
    llist.add(2,2);
    llist.add(-33,3);
    llist.add(4,4);
    llist.add(5,5);
    cout<<"add     : ";
    llist.show();

    llist.remove(0);
    cout<<"remove 0: ";
    llist.show();
    llist.add(5,5);
    cout<<"add  5,5: ";
    llist.show();

    purge(llist);
    cout<<"purge   : ";
    llist.show();

    cout<<"maxSum = " << getMaxSum(llist) << endl;
}

void testArrayListForChar() {
    cout << endl << "Test arrayList for Char:" << endl;

    ArrayList<char> clist;

    clist.add('a',0);
    clist.add('b',0);
    clist.add('c',0);
    clist.add('d',0);
    cout<<"add     : ";
    clist.show();

    clist.remove(2);
    cout<<"remove 2: ";
    clist.show();
    clist.add('a',2);
    cout<<"add  a,2: ";
    clist.show();

    purge(clist);
    cout<<"purge   : ";
    clist.show();
}

void testLinkedListForInt() {
    cout << endl << "Test linkedList for Int:" << endl;

    LinkedList<int> llist;

    llist.add(0,0);
    llist.add(1,1);
    llist.add(2,2);
    llist.add(-33,3);
    llist.add(4,4);
    llist.add(5,5);
    cout<<"add     : ";
    llist.show();

    llist.remove(5);
    cout<<"remove 5: ";
    llist.show();
    llist.add(0,0);
    cout<<"add  0,0: ";
    llist.show();

    purge(llist);
    cout<<"purge   : ";
    llist.show();

    cout<<"maxSum = " << getMaxSum(llist) << endl;
}

void testLinkedListForChar() {
    cout << endl << "Test linkedList for Char:" << endl;

    LinkedList<char> clist;

    clist.add('a',0);
    clist.add('b',0);
    clist.add('c',0);
    clist.add('d',0);
    cout<<"add     : ";
    clist.show();

    clist.remove(2);
    cout<<"remove 2: ";
    clist.show();
    clist.add('a',2);
    cout<<"add  a,2: ";
    clist.show();

    purge(clist);
    cout<<"purge   : ";
    clist.show();
}