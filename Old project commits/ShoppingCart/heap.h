/*************************************************************************
*AUTHOR         : Steven Grenrock
*STUDENT ID     : 816976
*Assignement 7  : Heaps
*CLASS 		    : CS1D
*SECTION 		: T/Th 5:30p - 7:20p
*DUE DATE 		: 03/10/2015
*************************************************************************/

#ifndef HEAP_H_
#define HEAP_H_
#include <vector>
#include <math.h>
#include <QDebug>
using namespace std;


template <class E, class C>
struct Container{
    E element;
    C compare;
    set(E e, C c){
        element = e;
        compare = c;
    }

};
typedef int Position;


// This class defines a vector-based heap
template <class E, class C>
class Heap{
    public:
        typedef Container<E, C> item;

    public:
        Heap();
            // default construtor
        Heap(const Heap &h);
            // copy constructor
        ~Heap();
            // destructor
        Heap operator=(const Heap& h);
            // overloading = operator
        void populate(const Heap& h);
            // populates the using the information in h
        Position root() const;
            // returns 1
        int size() const;
            // returns sz
        void insert(E, C);
            // adds a new element to the heap
        E min();
            // returns the minimum value in the heap
        item minItem();
            // return the item with the minimum value
        void removeMin();
            // removes the minimum value in the heap
        void downHeapBubble();
            // reorganizes the heap after a removal
        void upHeapBubble();
            // reorganizes the heap after an insertion
        bool empty() const;
            // returns true if size == 0
        int height(Position p = 1, int h = 0) const;
            // returns the height of the heap
        Position parent(Position p) const;
            // returns the position of p's parent
        Position sibling(Position p) const;
            // returns the position of p's sibling
        Position left(Position p) const;
            // returns the position of p's left child
        Position right(Position p) const;
            // returns the position of p's right child
        bool isExternal(Position p) const;
            // returns true if p is at an external node
        bool isRoot(Position p) const;
            // returns true if p is 1
        void print_elem(Position p) const;
            // outputs the element at p
        void draw();
            // outputs the heap
    private:
        int sz;
            // size of the heap
        vector<item> list;
            // container for the elements
};


#endif /* HEAP_H_ */
