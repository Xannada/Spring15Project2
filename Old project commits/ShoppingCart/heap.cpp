#include "heap.h"
#include "item.h"
// default constructor
template <class E, class C>
Heap<E, C>::Heap(){
    item nullitem;
    list.push_back(nullitem);
    sz = 0;
}

template <class E, class C>
Heap<E, C>::Heap(const Heap<E, C> &h){
    list = h.list;
    sz   = h.size();
    //return this;
}

template <class E, class C>
Heap<E, C> Heap<E, C>::operator =(const Heap<E, C> &h){
    list = h.list;
    sz   = h.size();
    return *this;
}

// destructor
template <class E, class C>
Heap<E, C>::~Heap(){
    sz = 0;
}

template <class E, class C>
void Heap<E, C>::populate(const Heap<E, C> &h){
    list = h.list;
    sz = h.size();
}

// return 1
template <class E, class C>
Position Heap<E, C>::root() const{
    return 1;
}

// return sz
template <class E, class C>
int Heap<E, C>::size() const{
    return sz;
}

// add elem to the heap
template <class E, class C>
void Heap<E, C>::insert(E elem, C compare){
    item i;
    i.set(elem, compare) ;
    list.push_back(i);
    sz++;
    upHeapBubble();
}

// returns the minumum value in the heap
template <class E, class C>
E Heap<E, C>::min(){
    return list.at(root()).element;
}

// removes the minimum value in the heap
template <class E, class C>
void Heap<E, C>::removeMin(){
    list[1] = list.back();
    list.pop_back();
    sz--;
    downHeapBubble();
}

// organizes the heap after a removal
template <class E, class C>
void Heap<E, C>::downHeapBubble(){
    Position i = root(); // used to iterate the heap
    // continue making swaps until i is at an external node or is properly
    // positioned
    while(!isExternal(i)){
        // if i is greater than its left child, make a swap
        if((list[i].compare > list[left(i)].compare) && (list[left(i)].compare < list[right(i)].compare)){
            item atI = list.at(i);
            item atLeft = list.at(left(i));
            list[i] = atLeft;
            list[left(i)] = atI;
            i = left(i);

        }
        // if i is greater than its right child, make a swap
        else if(list[i].compare > list[right(i)].compare){
            item atI = list.at(i);
            item atRight = list.at(right(i));
            list[i] = atRight;
            list[right(i)] = atI;
            i = right(i);

        }
        // end method if i is properly positioned
        else{
            return;
        }
    }

}

// organizes the heap after an insertion
template <class E, class C>
void Heap<E, C>::upHeapBubble(){
    Position j = sz; // used to iterate the heap
    // continue making swaps until j is at the root or is properly
    // positioned
    while(!isRoot(j)){
        // if j is less than its parent, make a swap
        if(list[j].compare < list[parent(j)].compare){
            item atJ = list.at(j);
            item atParent = list.at(parent(j));
            list[j] = atParent;
            list[parent(j)] = atJ;
            j = parent(j);

        }
        // if j is properly positioned, end method
        else{
            return;
        }
    }
}

// return true if sz is 0
template <class E, class C>
bool Heap<E, C>::empty() const{
    return sz == 0;
}

// return the height of the heap
template <class E, class C>
int Heap<E, C>::height(Position p, int h) const{
    // check if the iteration has reached the end of the list
    if(p <= sz){
        h++;
        return height(left(p), h);
    }
    // return h - 1
    else{
        return h - 1;
    }
}

// return the parent of the node at p
template <class E, class C>
Position Heap<E, C>::parent(Position p) const{
    // return p if there are no children
    // output error message
    if(sz <= 1){
        qDebug() << "Insufficient size\n";
        return p;
    }
    // return the position of the parent
    else{
        return p / 2;
    }
}

// return the sibling of the node at p
template <class E, class C>
Position Heap<E, C>::sibling(Position p) const{
    // return p if there are no children
    // output error message
    if(sz <= 1){
        qDebug() << "Insufficient size\n";
        return p;
    }
    // return the right node if p is the left
    else if(p % 2 == 0){
        return p + 1;
    }
    // return the left node if p is the right
    else{
        return p - 1;
    }
}

// return the position of p's left child
template <class E, class C>
Position Heap<E, C>::left(Position p) const{
    return p * 2;
}

// return the position of p's right child
template <class E, class C>
Position Heap<E, C>::right(Position p) const{
    return p * 2 + 1;
}

// check to see if p is at an external node
template <class E, class C>
bool Heap<E, C>::isExternal(Position p) const{
    return left(p) > sz;
}

// check to see if p is at the root
template <class E, class C>
bool Heap<E, C>::isRoot(Position p) const{
    return p == 1;
}

// print the element at p
template <class E, class C>
void Heap<E, C>::print_elem(Position p) const{
    qDebug() << list.at(p).compare;
}

// draw the heap as a vector
template <class E, class C>
void Heap<E, C>::draw(){
    qDebug() << '\n';
    while(sz > 0){
        qDebug() << min().type << " "
                 << min().stadium << " "
                 << min().price << " "
                 << min().quantity << "\n";
        removeMin();
    }
    qDebug() << '\n';
}

template class Heap<Item, QString>;
template class Heap<Item, float>;
template class Heap<Item, int>;
