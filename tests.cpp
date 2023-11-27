// tests.cpp
#include "PriorityQueue.h"
#include <gtest/gtest.h>
#include <string>

    TEST(Array, insert1){
        ArrayBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_EQ(std::string("1"), list.PrintPriorityQueue());
    }

    TEST(Array, insert2){
        ArrayBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_EQ(std::string("1, 2, 10"), list.PrintPriorityQueue());
    }

    TEST(Array, dequeue1){
        ArrayBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_TRUE(list.DeQueue());
        ASSERT_EQ(std::string("2, 10"), list.PrintPriorityQueue());
    }

    TEST(Array, dequeue2){
        ArrayBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_TRUE(list.DeQueue());
        ASSERT_TRUE(list.Insert(5));
        ASSERT_TRUE(list.Insert(8));
        ASSERT_TRUE(list.DeQueue());
        ASSERT_TRUE(list.DeQueue());
        ASSERT_EQ(std::string("8, 10"), list.PrintPriorityQueue());
    }

    TEST(Array, print1){
        ArrayBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_TRUE(list.DeQueue());
        ASSERT_TRUE(list.Insert(5));
        ASSERT_TRUE(list.Insert(8));
        ASSERT_EQ(std::string("2, 5, 8, 10"), list.PrintPriorityQueue());
    }

    TEST(Array, print2){
        ArrayBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_TRUE(list.Insert(5));
        ASSERT_TRUE(list.Insert(8));
        ASSERT_TRUE(list.Insert(1001));
        ASSERT_TRUE(list.Insert(3));
        ASSERT_TRUE(list.Insert(80));
        ASSERT_EQ(std::string("1, 2, 3, 5, 8, 10, 80, 1001"), list.PrintPriorityQueue());
    }

    TEST(Heap, insert1){
        HeapBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_EQ(std::string("1"), list.PrintPriorityQueue());
    }

    TEST(Heap, insert2){
        HeapBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_EQ(std::string("10, 1, 2"), list.PrintPriorityQueue());
    }

    TEST(Heap, dequeue1){
        HeapBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_TRUE(list.DeQueue());
        ASSERT_EQ(std::string("2, 1"), list.PrintPriorityQueue());
    }

    TEST(Heap, dequeue2){
        HeapBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_TRUE(list.DeQueue());
        ASSERT_TRUE(list.Insert(5));
        ASSERT_TRUE(list.Insert(8));
        ASSERT_TRUE(list.DeQueue());
        ASSERT_EQ(std::string("5, 1, 2"), list.PrintPriorityQueue());
    }

    TEST(Heap, print1){
        HeapBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_TRUE(list.DeQueue());
        ASSERT_TRUE(list.Insert(5));
        ASSERT_TRUE(list.Insert(8));
        ASSERT_EQ(std::string("8, 5, 2, 1"), list.PrintPriorityQueue());
    }

    TEST(Heap, print2){
        HeapBasedQueue list;

        ASSERT_TRUE(list.Insert(1));
        ASSERT_TRUE(list.Insert(10));
        ASSERT_TRUE(list.Insert(2));
        ASSERT_TRUE(list.Insert(5));
        ASSERT_TRUE(list.Insert(8));
        ASSERT_TRUE(list.Insert(1001));
        ASSERT_TRUE(list.Insert(3));
        ASSERT_TRUE(list.Insert(80));
        ASSERT_EQ(std::string("1001, 80, 10, 8, 5, 2, 3, 1"), list.PrintPriorityQueue());
    }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
