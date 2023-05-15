import random

def generate_random_sequence(n, start, end):
    return [random.randint(start, end) for _ in range(n)]


class BinomialHeap:
    def __init__(self):
        self.heap_list = [0]
        self.current_size = 0

    def sift_up(self, i):
        Stop = False
        while (i // 2 > 0) and Stop == False:
            if self.heap_list[i] < self.heap_list[i // 2]:
                self.heap_list[i], self.heap_list[i // 2] = self.heap_list[i // 2], self.heap_list[i]
            else:
                Stop = True
            i = i // 2

    def insert(self, k):
        self.heap_list.append(k)
        self.current_size += 1
        self.sift_up(self.current_size)

    def sift_down(self, i):
        while (i * 2) <= self.current_size:
            mc = self.min_child(i)
            if self.heap_list[i] > self.heap_list[mc]:
                self.heap_list[i], self.heap_list[mc] = self.heap_list[mc], self.heap_list[i]
            i = mc

    def min_child(self, i):
        if (i * 2) + 1 > self.current_size:
            return i * 2
        else:
            if self.heap_list[i*2] < self.heap_list[(i*2)+1]:
                return i * 2
            else:
                return (i * 2) + 1

    def delete_min(self):
        if len(self.heap_list) == 1:
            return 'Empty heap'
        root = self.heap_list[1]
        self.heap_list[1] = self.heap_list[self.current_size]
        self.heap_list.pop()
        self.current_size -= 1
        self.sift_down(1)
        return root
        
    def print_heap(self):
        level = 0
        level_len = 1
        i = 1
        while i <= self.current_size:
            row_items = self.heap_list[i:i+level_len]
            print("  " * (self.current_size - i), end="")
            print("  ".join(map(str, row_items)))
            i += level_len
            level_len <<= 1
            level += 1


h = BinomialHeap()
values = generate_random_sequence(10, 1, 100)
for val in values:
    h.insert(val)
h.print_heap()
h.delete_min()
print("after deleting min element")
h.print_heap()