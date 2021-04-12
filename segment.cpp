#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> arr;
    vector<int> segment_tree;

public:
    SegmentTree(vector<int>& arr_, int n) : arr(arr_), segment_tree(n, 0)
    {
        buildSegmentTree(0, 0, arr.size() - 1);
    }

    void buildSegmentTree(int node, int start, int end)
    {
        cout << "start " << start << " end " << end << endl;
        if (start == end) {
            segment_tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        buildSegmentTree(left_node, start, mid);
        buildSegmentTree(right_node, mid + 1, end);
        segment_tree[node] = segment_tree[left_node] + segment_tree[right_node];
    }

    int query(int node, int start, int end, int L, int R)
    {
        if (end < L || R < start) {
            return 0;
        }
        if (L <= start && end <= R) {
            return segment_tree[node];
        }

        int mid = start + (end - start) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        return query(left_node, start, mid, L, R) +
               query(right_node, mid + 1, end, L, R);
    }

    void update(int node, int start, int end, int idx, int val)
    {
        int diff = val - arr[idx];
        arr[idx] = val;
        updateAux(node, start, end, idx, diff);
    }

    void printSegmentTree()
    {
        for (int i = 0; i < segment_tree.size(); ++i) {
            cout << "segment_tree[" << i << "] " << segment_tree[i] << endl;
        }
        cout << endl;
    }

private:
    void updateAux(int node, int start, int end, int idx, int diff)
    {
        if (idx < start || idx > end) {
            return;
        }
        segment_tree[node] += diff;
        if (start != end) {
            int mid = start + (end - start) / 2;
            updateAux(2 * node + 1, start, mid, idx, diff);
            updateAux(2 * node + 2, mid + 1, end, idx, diff);
        }
    }
};

int main()
{
    vector<int> nums{1, 3, 5, 7, 9, 11};
    int x = (int)(ceil(log2(nums.size())));
    int sz = 2 * pow(2, x) - 1;

    SegmentTree s = SegmentTree(nums, sz);
    s.printSegmentTree();
    cout << s.query(0, 0, nums.size() - 1, 2, 4) << endl;

    s.update(0, 0, nums.size() - 1, 4, 6);
    s.printSegmentTree();
    cout << s.query(0, 0, nums.size() - 1, 2, 4) << endl;

    return 0;
}
