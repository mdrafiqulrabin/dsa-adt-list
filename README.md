# DSA-ADT-Lists
Programming Assignment: 2018FA-COSC6320-Data Structures & Algorithms \
Task: Implement linear lists (ArrayList and LinkedList) in C++.

- - -

# Guidelines:

- Write two implementations of linear lists (ArrayList and LinkedList) in C++. They should be interchangeable,  i.e., use the data structure in an application, without knowing how it is implemented. 
- To test them, write two algorithms (such as purge and maxSum) that use the implementations. Saying purge/maxSum, the function should be able to run with either implementation of the list.
- Define a 'position' that works for both cases and an 'elemType' first before the list class.
- Include following ADT Functions: ('p' is a position, 'list' is a list, 'x' is an element)
    - list.get(p) returns the element if p is a valid position;
    - list.add(x, p) add x to the list at position p (if p is a valid position);
    - list.remove(p) delete element at position p (if p is a valid position);
    - list.find(x) returns a position of x if it is in the list;
    - list.next(p): returns the next position of p;
    - list.first(): returns the first position of the list;
    - list.empty(): is list empty?
- As for the 'elemType', try to generalize it to any types (i.e. int, char).
- Add additional functions and definitions if needed, with one design that can be implemented in both cases.

- - -

# Sample Input/Output:

> run main.cpp

```
Test arrayList for Int:
add      : 0 1  2 -3 4 5	
remove 0 : 1 2 -3  4 5	
add  5,5 : 1 2 -3  4 5 5	
purge    : 1 2 -3  4 5	
maxSum   : 9

Test arrayList for Char:
add      : d c b a	
remove 2 : d c a	
add  a,2 : d c a a	
purge    : d c a	

Test linkedList for Int:
add      : 0 1 2 -3  4 5	
remove 5 : 0 1 2 -3  4	
add  0,0 : 0 0 1  2 -3 4	
purge    : 0 1 2 -3  4	
maxSum   : 4

Test linkedList for Char:
add      : d c b a	
remove 2 : d c a	
add  a,2 : d c a a	
purge    : d c a	
```

# References:

- Abstract Data Type (ADT)
- Templates in C++
