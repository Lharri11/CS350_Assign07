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
    heapArray = newArray;
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
    if(leftIndex(idx) > heapSize)
    {
        return -1;
    }
    else
    {
        if(rightIndex(idx) <= heapSize)
        {
            if(heapArray[rightIndex(idx)] > heapArray[leftIndex(idx)])
            {
                return leftIndex(idx);
            }
            return rightIndex(idx);
        }
        return leftIndex(idx);
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
    int element = heapArray[1] = 0, mChild = minChild(1);

    heapArray[1] = heapArray[mChild];
    heapArray[mChild] = element;
    percolateDown(mChild);
    heapSize--;

    if(heapSize < maxSize/3)
    {
        resizeArray(maxSize/2);
        return *heapArray;
    }
    return *heapArray;
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
    int mChild = minChild(idx);

    while(mChild != -1 && idx <= heapSize && heapArray[idx] > heapArray[mChild])
    {
        int element =  heapArray[idx];
        heapArray[idx] = heapArray[mChild];
        heapArray[minChild(idx)] = element;
        idx = mChild;
        mChild = minChild(mChild);
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
