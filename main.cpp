#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"
#include "Function.h"

using namespace std;

void testArrayListForInt();

void testArrayListForChar();

void testLinkedListForInt();

void testLinkedListForChar();

int main() {
    // test arrayList for Int and Char
    testArrayListForInt();
    testArrayListForChar();

    // test linkedList for Int and Char
    testLinkedListForInt();
    testLinkedListForChar();

    return 0;
}

void testArrayListForInt() {
    cout << endl << "Test arrayList for Int:" << endl;

    ArrayList<int> arrayList;

    arrayList.add(0, 0);
    arrayList.add(1, 1);
    arrayList.add(2, 2);
    arrayList.add(-3, 3);
    arrayList.add(4, 4);
    arrayList.add(5, 5);
    cout << "add      : ";
    arrayList.show();

    arrayList.remove(0);
    cout << "remove 0 : ";
    arrayList.show();
    arrayList.add(5, 5);
    cout << "add  5,5 : ";
    arrayList.show();

    purge(arrayList);
    cout << "purge    : ";
    arrayList.show();

    cout << "maxSum   : " << getMaxSum(arrayList) << endl;
}

void testArrayListForChar() {
    cout << endl << "Test arrayList for Char:" << endl;

    ArrayList<char> arrayList;

    arrayList.add('a', 0);
    arrayList.add('b', 0);
    arrayList.add('c', 0);
    arrayList.add('d', 0);
    cout << "add      : ";
    arrayList.show();

    arrayList.remove(2);
    cout << "remove 2 : ";
    arrayList.show();
    arrayList.add('a', 2);
    cout << "add  a,2 : ";
    arrayList.show();

    purge(arrayList);
    cout << "purge    : ";
    arrayList.show();
}

void testLinkedListForInt() {
    cout << endl << "Test linkedList for Int:" << endl;

    LinkedList<int> linkedList;

    linkedList.add(0, 0);
    linkedList.add(1, 1);
    linkedList.add(2, 2);
    linkedList.add(-3, 3);
    linkedList.add(4, 4);
    linkedList.add(5, 5);
    cout << "add      : ";
    linkedList.show();

    linkedList.remove(5);
    cout << "remove 5 : ";
    linkedList.show();
    linkedList.add(0, 0);
    cout << "add  0,0 : ";
    linkedList.show();

    purge(linkedList);
    cout << "purge    : ";
    linkedList.show();

    cout << "maxSum   : " << getMaxSum(linkedList) << endl;
}

void testLinkedListForChar() {
    cout << endl << "Test linkedList for Char:" << endl;

    LinkedList<char> linkedList;

    linkedList.add('a', 0);
    linkedList.add('b', 0);
    linkedList.add('c', 0);
    linkedList.add('d', 0);
    cout << "add      : ";
    linkedList.show();

    linkedList.remove(2);
    cout << "remove 2 : ";
    linkedList.show();
    linkedList.add('a', 2);
    cout << "add  a,2 : ";
    linkedList.show();

    purge(linkedList);
    cout << "purge    : ";
    linkedList.show();
}
