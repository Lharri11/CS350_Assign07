//
//  BinHeap.cpp
//

#include "BinHeap.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
template <class T>
BinHeap<T>::BinHeap()
{
    // TODO: Allocate initial heap array and store sentinel value
    heapSize = 0; maxSize = 1;

    heapArray = new int[maxSize];
    heapArray[0] = -1;

}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
template <class T>
BinHeap<T>::~BinHeap()
{
    delete[] heapArray;
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
// TODO: isEmpty() method
template <class T>
bool BinHeap::isEmpty()
{

}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
template <class T>
void BinHeap::makeEmpty()
{

}
#endif

/* **************************************************************** */

#if RESIZEARRAY || ALL
// TODO: resizeArray() method
void BinHeap::resizeArray(int newSize)
{

}
#endif

/* **************************************************************** */

#if LEFTINDEX || ALL
// TODO: leftIndex() method
int BinHeap::leftIndex(int idx)
{

}
#endif

/* **************************************************************** */

#if RIGHTINDEX || ALL
// TODO: rightIndex() method
int BinHeap::rightIndex(int idx)
{

}
#endif

/* **************************************************************** */

#if PARENTINDEX || ALL
// TODO: parentIndex() method
int BinHeap::parentIndex(int idx)
{

}
#endif

/* **************************************************************** */

#if MINCHILD || ALL
// TODO: minChild() method
int BinHeap::minChild(int idx)
{

}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
template <class T>
void BinHeap::insert(const T & x)
{

}
#endif

/* **************************************************************** */

#if REMOVEMIN || ALL
// TODO: removeMin() method
template <class T>
T BinHeap::removeMin()
{

}
#endif

/* **************************************************************** */

#if PERCOLATEUP || ALL
// TODO: percolateUp() method
void BinHeap::percolateUp(int idx)
{

}
#endif

/* **************************************************************** */

#if PERCOLATEDOWN || ALL
// TODO: percolateDown() method
void BinHeap::percolateDown(int idx)
{

}
#endif

/* **************************************************************** */

#if BUILDHEAP || ALL
// TODO: buildHeap() method
template <class T>
void BinHeap::buildHeap(const T* arr, int size)
{

}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
template <class T>
void BinHeap<T>::printHeap()
{
    std::stringstream ss;
    printHeapToStream(ss);
    std::cout << ss.str();
}


template <class T>
void BinHeap<T>::printHeapToStream(std::stringstream& ss)
{
    ss << "  Current array size: " << maxSize << std::endl;
    ss << "  Current heap size: " << heapSize << std::endl;
    
    if (!isEmpty()) {
        ss << "  Heap Elements: ";
        // Print heap array
        for (int i = 1; i <= heapSize; i++) {
            ss << heapArray[i] << " ";
        }
    }
    else {
        ss << "  Heap is empty";
    }
    ss << std::endl << std::endl;
}
#endif

template class BinHeap<int>;
