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

    heapArray = new int[maxSize+1];
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
bool BinHeap<T>::isEmpty()
{
    return (heapSize == 0);
}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
template <class T>
void BinHeap<T>::makeEmpty()
{
    delete[] heapArray;

    heapSize = 0; maxSize = 1;

    heapArray = new int[maxSize];
    heapArray[0] = -1;
}
#endif

/* **************************************************************** */

#if RESIZEARRAY || ALL
// TODO: resizeArray() method
template <class T>
void BinHeap<T>::resizeArray(int newSize)
{
    T* newArray = new int[newSize+1];
    newArray[0] = -1;

    for(int i=1; i<=heapSize; i++)
    {
        newArray[i] = heapArray[i];
    }
    delete[] heapArray;
    maxSize = newSize;
}
#endif

/* **************************************************************** */

#if LEFTINDEX || ALL
// TODO: leftIndex() method
template <class T>
int BinHeap<T>::leftIndex(int idx)
{
    return 2*idx;
}
#endif

/* **************************************************************** */

#if RIGHTINDEX || ALL
// TODO: rightIndex() method
template <class T>
int BinHeap<T>::rightIndex(int idx)
{
    return 2*idx + 1;
}
#endif

/* **************************************************************** */

#if PARENTINDEX || ALL
// TODO: parentIndex() method
template <class T>
int BinHeap<T>::parentIndex(int idx)
{
    return idx/2;
}
#endif

/* **************************************************************** */

#if MINCHILD || ALL
// TODO: minChild() method
template <class T>
int BinHeap<T>::minChild(int idx)
{
    if(leftIndex(idx) == NULL && rightIndex(idx) == NULL)
    {
        return -1;
    }
    else
    {
        if(rightIndex(idx) > leftIndex(idx))
        {
            return leftIndex(idx);
        }

        return rightIndex(idx);
    }
}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
template <class T>
void BinHeap<T>::insert(const T & x)
{
    if(heapSize == maxSize)
    {
        resizeArray(maxSize*2);
    }

    heapSize++;
    heapArray[heapSize] = x;
    percolateUp(heapSize);
}
#endif

/* **************************************************************** */

#if REMOVEMIN || ALL
// TODO: removeMin() method
template <class T>
T BinHeap<T>::removeMin()
{

}
#endif

/* **************************************************************** */

#if PERCOLATEUP || ALL
// TODO: percolateUp() method
template <class T>
void BinHeap<T>::percolateUp(int idx)
{
    while(idx > 0 && heapArray[parentIndex(idx)] > heapArray[idx])
    {
        int element =  heapArray[idx];
        heapArray[idx] = heapArray[parentIndex(idx)];
        heapArray[parentIndex(idx)] = element;
        idx = idx/2;
    }
}
#endif

/* **************************************************************** */

#if PERCOLATEDOWN || ALL
// TODO: percolateDown() method
template <class T>
void BinHeap<T>::percolateDown(int idx)
{
    while(idx <= heapSize && heapArray[idx] > heapArray[leftIndex(idx)] && heapArray[idx] > heapArray[rightIndex(idx)])
    {
        int element =  heapArray[idx];

        if(minChild(idx) == leftIndex(idx))
        {
            heapArray[idx] = heapArray[leftIndex(idx)];
            heapArray[leftIndex(idx)] = element;
            idx = 2*idx;
        }
        else if(minChild(idx) == rightIndex(idx))
        {
            heapArray[idx] = heapArray[rightIndex(idx)];
            heapArray[rightIndex(idx)] = element;
            idx = 2*idx + 1;
        }
    }
}
#endif

/* **************************************************************** */

#if BUILDHEAP || ALL
// TODO: buildHeap() method
template <class T>
void BinHeap<T>::buildHeap(const T* arr, int size)
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
