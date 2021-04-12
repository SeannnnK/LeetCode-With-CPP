/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
// bloomberg | microsoft
#include <stack>
#include <iostream>

using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!s2.empty()) {
            int res = s2.top();
            s2.pop();
            return res;
        } else {
            while (!s1.empty()) {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
            int res = s2.top();
            s2.pop();
            return res;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        } else {
            while (!s1.empty()) {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
            return s2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1, s2;
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(3);
    int param_2 = obj->pop();
    bool param_4 = obj->empty();
    cout << param_2 << " " << param_4 << endl;
    return 0;
}
 
// @lc code=end

