#include "PriorityQueue.h"
#include <string>
#include <chrono>
#include <iostream>
typedef std::chrono::high_resolution_clock Clock;
#include <iomanip>

std::string insertToArrayList(int size, int randomNumbers[5000]){
    ArrayBasedQueue insertList;
    auto t1 = Clock::now();

    for (int i = 0; i < size; i ++){
        insertList.Insert(randomNumbers[i]);
    }

    auto t2 = Clock::now();

    // returns in ms
	return std::to_string((std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count())/1000.0);
}

std::string insertToHeapList(int size, int randomNumbers[5000]){
    HeapBasedQueue insertList;
    auto t1 = Clock::now();

    for (int i = 0; i < size; i ++){
        insertList.Insert(randomNumbers[i]);
    }

    auto t2 = Clock::now();

    // returns in ms
	return std::to_string((std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count())/1000.0);
}

std::string removeToArrayList(int size, int randomNumbers[5000]){
    ArrayBasedQueue removeList;

    for (int i = 0; i < size; i ++){
        removeList.Insert(randomNumbers[i]);
    }

    auto t1 = Clock::now();

    for (int i= 0; i < size; i++){
        removeList.DeQueue();
    }

    auto t2 = Clock::now();

    // returns in ms
	return std::to_string((std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count())/1000.0);
}

std::string removeToHeapList(int size, int randomNumbers[5000]){
    HeapBasedQueue removeList;

    for (int i = 0; i < size; i ++){
        removeList.Insert(randomNumbers[i]);
    }

    auto t1 = Clock::now();

    for (int i = 0; i < size; i ++){
        removeList.Insert(randomNumbers[i]);
    }

    auto t2 = Clock::now();

    // returns in ms
	return std::to_string((std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count())/1000.0);
}

int main(){
    int randInts[5000];
    for (int i = 0; i < 5000; i++){
        randInts[i] = 1 + (rand() % 5000);
    }

    std::string outputInsertArray[3][5];
    outputInsertArray[0][0] = "Inseting!";
    outputInsertArray[0][1] = "500 Items";
    outputInsertArray[0][2] = "1000 Items";
    outputInsertArray[0][3] = "2000 Items";
    outputInsertArray[0][4] = "5000 Items";
    outputInsertArray[1][0] = "Array";
    outputInsertArray[2][0] = "Heap";

    outputInsertArray[1][1] = "\t" + insertToArrayList(500,randInts) + "ms";
    outputInsertArray[1][2] = insertToArrayList(1000,randInts) + "ms";
    outputInsertArray[1][3] = insertToArrayList(2000,randInts) + "ms";
    outputInsertArray[1][4] = insertToArrayList(5000,randInts) + "ms";

    outputInsertArray[2][1] = "\t" + insertToHeapList(500,randInts) + "ms";
    outputInsertArray[2][2] = insertToHeapList(1000,randInts) + "ms";
    outputInsertArray[2][3] = insertToHeapList(2000,randInts) + "ms";
    outputInsertArray[2][4] = insertToHeapList(5000,randInts) + "ms";

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            std::cout<<outputInsertArray[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl<<std::endl;

    std::string outputRemoveArray[3][5];
    outputRemoveArray[0][0] = "Removing!";
    outputRemoveArray[0][1] = "500 Items";
    outputRemoveArray[0][2] = "1000 Items";
    outputRemoveArray[0][3] = "2000 Items";
    outputRemoveArray[0][4] = "5000 Items";
    outputRemoveArray[1][0] = "Array";
    outputRemoveArray[2][0] = "Heap";

    outputRemoveArray[1][1] = "\t" + removeToArrayList(500,randInts) + "ms";
    outputRemoveArray[1][2] = removeToArrayList(1000,randInts) + "ms";
    outputRemoveArray[1][3] = removeToArrayList(2000,randInts) + "ms";
    outputRemoveArray[1][4] = removeToArrayList(5000,randInts) + "ms";

    outputRemoveArray[2][1] = "\t" + removeToHeapList(500,randInts) + "ms";
    outputRemoveArray[2][2] = removeToHeapList(1000,randInts) + "ms";
    outputRemoveArray[2][3] = removeToHeapList(2000,randInts) + "ms";
    outputRemoveArray[2][4] = removeToHeapList(5000,randInts) + "ms";

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            std::cout<<outputRemoveArray[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }

    return 0;
}