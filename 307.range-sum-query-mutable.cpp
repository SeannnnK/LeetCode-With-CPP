// Unknown
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) : nums(nums) {
        int n = (int)ceil(log2(nums.size()));
        int m = pow(2, n);
        int segmentTreeSize = 2 * m - 1;
        segmentTree.reserve(segmentTreeSize);
        segmentTree.assign(segmentTreeSize, 0);
        buildTree(0, nums.size() - 1, 0);
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateAux(0, nums.size() - 1, 0, index, diff);
    }
    
    int sumRange(int left, int right) {
        return sumRangeAux(0, nums.size() - 1, left, right, 0);
    }

private:
    void buildTree(int start, int end, int node) {
        if (start == end) {
            segmentTree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        buildTree(start, mid, leftNode);
        buildTree(mid + 1, end, rightNode);
        segmentTree[node] = segmentTree[leftNode] + segmentTree[rightNode];
        return;
    }

    int sumRangeAux(int start, int end, int left, int right, int node) {
        if (right < start || left > end) {
            return 0;
        }
        if (left <= start && end <= right) {
            return segmentTree[node];
        }
        if (left == right) {
            return nums[left];
        }
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        return sumRangeAux(start, mid, left, right, leftNode) + sumRangeAux(mid + 1, end, left, right, rightNode);
    }

    void updateAux(int start, int end, int node, int index, int diff) {
        if (index < start || index > end) {
            return;
        }
        segmentTree[node] += diff;
        if (start != end) {
            int mid = start + (end - start) / 2;
            updateAux(start, mid, 2 * node + 1, index, diff);
            updateAux(mid + 1, end, 2 * node + 2, index, diff);
        }
    }

private:
    vector<int> nums;
    vector<int> segmentTree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main()
{
    vector<int> nums{0, 9, 5, 7, 3};
    NumArray* obj = new NumArray(nums);
    int param_1 = obj->sumRange(4, 4);
    obj->update(1, 7);
    int param_2 = obj->sumRange(1, 4);
    obj->update(0, 8);
    int param_3 = obj->sumRange(3, 3);
    int param_4 = obj->sumRange(4, 5);
    cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << endl;
    return 0;
}
