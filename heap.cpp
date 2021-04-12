#include <vector>

using namespace std;

class Myheap {
    vector<int> heap;
public:
    void push(int x) {
        heap.push_back(x);
        swim(heap.size() - 1);
    }

    void pop() {
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        sink(0);
    }

private:
    void swim(int pos) {
        while (pos > 1 && heap[pos / 2] < heap[pos]) {
            swap(heap[pos / 2], heap[pos]);
            pos = pos / 2;
        }
    }

    void sink(int pos) {
        while (2 * pos <= heap.size()) {
            int i = 2 * pos;
            if (i < heap.size() && heap[i] < heap[i + 1]) {
                ++i;
            }
            if (heap[pos] > heap[i]) {
                break;
            }
            swap(heap[pos], heap[i]);
            pos = i;
        }
    }
};
