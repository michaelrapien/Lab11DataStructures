#include <memory>
#include <string>

class IPriorityQueue
{
    public:

    virtual bool Insert(const int val) = 0;
    virtual bool DeQueue() = 0;
    virtual std::string PrintPriorityQueue() = 0;
    virtual bool isEmpty() = 0;

    protected:
};


class ArrayBasedQueue : IPriorityQueue
{
    public:
        ArrayBasedQueue(void);
        virtual ~ArrayBasedQueue();
        bool Insert(const int val) override;
        bool DeQueue() override;
        std::string PrintPriorityQueue() override;
        bool isEmpty() override;

    private:
        int queueArray[5000];
        int queueCount = 0;

};


class HeapBasedQueue : IPriorityQueue
{
    public:
        HeapBasedQueue(void);
        virtual ~HeapBasedQueue();
        bool Insert(const int val) override;
        bool DeQueue() override;
        std::string PrintPriorityQueue() override;
        bool isEmpty() override;

    private:
        int queueHeap[5000];
        int queueHeapCount = 0;
};
