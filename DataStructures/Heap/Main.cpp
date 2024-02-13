#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Heap/MinHeap.cpp"
#include "/Users/michallejza/CLionProjects/Everything/Algorytmy/PrintHeap.hpp"

int main()
{
    auto *heap = new Heap::MinHeap<int>();
    heap -> slowConstruct({9,2,6,12,1,4,8,7,5,10,11});
    heap -> printArray();
    print(heap);
    heap -> minDelete();
    heap -> printArray();
    print(heap);
    heap -> minDelete();
    heap -> printArray();
    print(heap);
    heap -> clear();
    delete heap;

    return 0;
}
