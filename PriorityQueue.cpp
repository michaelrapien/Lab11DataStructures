#include "PriorityQueue.h"
#include <iostream>

//Insipired by GeeksforGeeks code
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

ArrayBasedQueue::ArrayBasedQueue(void)
{
}

ArrayBasedQueue::~ArrayBasedQueue()
{
}

bool ArrayBasedQueue::Insert(const int val)
{
    if(queueCount == 0){
        queueArray[0] = val;
        queueCount++;
        return true;
    }

    else if (queueCount < 5001){
        for (int i = 0; i < queueCount + 1; i++){
            if (val > queueArray[i] && i < queueCount){
            }
            else{
                for (int j=queueCount; j > i; j--){
                    queueArray[j] = queueArray[j-1];
                }
                queueArray[i] = val;
                break;
            }
        }
        
        queueCount ++;
        return true;
    }

    else{
        return false;
    }
}

bool ArrayBasedQueue::DeQueue()
{
    if (isEmpty()){
        return false;
    }
    
    else{
        for (int i = 0; i < queueCount; i++){
            queueArray[i] = queueArray[i+1];
        }
        queueCount --;
        return true;
    }
}

std::string ArrayBasedQueue::PrintPriorityQueue()
{
    std::string str = "";

    for (int i = 0; i < queueCount; i++){
        str = str + std::to_string(queueArray[i]);
        if (i != (queueCount - 1)){
            str = str + ", ";
        }
    }
    std::cout<<str<<"\n";

    return str;
}

bool ArrayBasedQueue::isEmpty()
{
    if (queueCount == 0){
        return true;
    }
    
    else{
        return false;
    }
}

HeapBasedQueue::HeapBasedQueue(void)
{
}

HeapBasedQueue::~HeapBasedQueue()
{
}

//Inspired by the slide deck
bool HeapBasedQueue::Insert(const int val)
{
    queueHeap[queueHeapCount] = val;

    int newDataIndex = queueHeapCount;
    bool inPlace = false;
    while((newDataIndex >= 0) && !inPlace){
        int parentIndex = (newDataIndex - 1) / 2;
        if (queueHeap[newDataIndex] <= queueHeap[parentIndex]){
            inPlace = true;
        }
        else{
            int tempVal = queueHeap[newDataIndex];
            queueHeap[newDataIndex] = queueHeap[parentIndex];
            queueHeap[parentIndex] = tempVal;
            newDataIndex = parentIndex;
        }
    }

    queueHeapCount++;
    return inPlace;
}

bool HeapBasedQueue::DeQueue()
{
    if (isEmpty()){
        return false;
    }
    
    else{
        int lastElement = queueHeap[queueHeapCount - 1];
        queueHeap[0] = lastElement;
        int n = queueHeapCount - 1;
        heapify(queueHeap, n, 0);
        queueHeapCount --;
        return true;
    }
}

std::string HeapBasedQueue::PrintPriorityQueue()
{
    std::string str = "";

    for (int i = 0; i < queueHeapCount; i++){
        str = str + std::to_string(queueHeap[i]);
        if (i != (queueHeapCount - 1)){
            str = str + ", ";
        }
    }
    std::cout<<str<<"\n";

    return str;
}

bool HeapBasedQueue::isEmpty()
{
    if (queueHeapCount == 0){
        return true;
    }
    
    else{
        return false;
    }
}
