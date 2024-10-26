#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int fifoPageReplacement(vector<int> pages, int n, int capacity)
{
    unordered_set<int> st;
    queue<int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (st.find(pages[i]) == st.end())
        {
            if (st.size() == capacity)
            {
                int val = indexes.front();
                indexes.pop();
                st.erase(val);
            }
            st.insert(pages[i]);
            indexes.push(pages[i]);
            page_faults++;
        }
    }
    return page_faults;
}

int main(){
    vector<int> pages = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;
    cout << "Page sequence: ";
    for (int i = 0; i < n; i++) {
        cout << pages[i] << " ";
    }
    cout << "\nMemory capacity (frames): " << capacity << endl;

    int page_faults = fifoPageReplacement(pages, n, capacity);
    cout << "Number of page faults using FIFO: " << page_faults << endl;

    return 0;
}