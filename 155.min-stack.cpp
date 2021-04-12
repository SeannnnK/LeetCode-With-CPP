/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
// amazon | bloomberg | google | snapchat | uber | zenefits
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        s1.push(val);
        if (!s2.empty()) {
            if (val < s2.top()) {
                s2.push(val);
            } else {
                s2.push(s2.top());
            }
        } else {
            s2.push(val);
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};

int main()
{
    MinStack* obj = new MinStack();
    obj->push(3);
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    obj->pop();
    cout << param_3 << " " << param_4 << endl;
}
// @lc code=end
