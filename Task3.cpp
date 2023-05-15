#include <iostream>
#include <climits>
#include "core.h"
using namespace std;
 
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
class BinaryHeap
{
    int *harr;
    int capacity;
    int heap_size; 
public:
    BinaryHeap(int capacity);
    
    void printHeap();
 
    void MinHeapify(int);
 
    int parent(int i) { return (i-1) / 2; }
 
    int left(int i) { return (2*i + 1); }
 
    int right(int i) { return (2*i + 2); }
 
    int extractMin();

    int getMin() { return harr[0]; }
 
    void insertKey(int k);
};
 
BinaryHeap::BinaryHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
void BinaryHeap::printHeap() {
    int n = capacity;
    int row = 0;
    int level_len = 1;
    int i = 0;
    while (i < n)
    {
        for (int j = 0; j < level_len && i < n; j++)
        {
            std::cout << harr[i] << " ";
            i++;
        }
        row++;
        level_len *= 2;
        std::cout << std::endl;
    }

}

void BinaryHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
 
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
int BinaryHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}
void BinaryHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

 
int main()
{
    auto values = generate_random_sequence(9, 1, 100);
    BinaryHeap h(10);
    for(auto val: values) {
        h.insertKey(val);
    }
    h.printHeap();
    h.insertKey(25);
    std::cout << "After inserting" << std::endl;
    h.printHeap();
    std::cout << "After deleting" << std::endl;
    h.extractMin();
    h.printHeap();
    return 0;
}