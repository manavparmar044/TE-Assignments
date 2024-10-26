#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int pageFaults(vector<int> &pages,int n,int capacity){
    unordered_map<int,int> mpp;
    unordered_set<int> st;

    int page_faults = 0;
    for(int i = 0;i<n;i++){
        if(st.size()<capacity){
            if(st.find(pages[i]) == st.end()){
                st.insert(pages[i]);
                page_faults++;
            }
            mpp[pages[i]] = i;
        }
        else{
            if(st.find(pages[i]) == st.end()){
                int lru = INT_MAX;
                int val = 0;
                for(auto it = st.begin();it!=st.end();it++){
                    if(lru>mpp[*it]){
                        lru = mpp[*it];
                        val = *it;
                    }
                }
                st.erase(val);
                st.insert(pages[i]);
                page_faults++;
            }
            mpp[pages[i]] = i;
        }
    }
    return page_faults;
}

int main(){
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; 
    int capacity = 4; 
    cout << "Number of page faults: " << pageFaults(pages,pages.size(), capacity) << endl; 
    return 0; 
}