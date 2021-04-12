/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
// bloomberg
#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
    MyStack* obj = new MyStack();
    int x = 3, y = 6;
    obj->push(x);
    obj->push(y);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout << param_2 << " " << param_3 << " " << param_4 << endl;
    return 0;
}
// @lc code=end