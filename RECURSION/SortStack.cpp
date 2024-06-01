#include <iostream>
#include <stack>

using namespace std;

class SortStack {
public:
    stack<int> s;

    void sortedInsert(int x) {
        if (s.empty() || x > s.top()) {
            s.push(x);
            return;
        }

        int temp = s.top();
        s.pop();
        sortedInsert(x);

        s.push(temp);
    }

    void sort() {
        if (!s.empty()) {
            int x = s.top();
            s.pop();
            sort();

            sortedInsert(x);
        }
    }
};

int main() {
    SortStack ss;
    ss.s.push(30);
    ss.s.push(20);
    ss.s.push(50);
    ss.s.push(10);

    cout << "Stack before sorting: ";
    stack<int> tempStack = ss.s;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    ss.sort();

    cout << "Stack after sorting: ";
    tempStack = ss.s;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
