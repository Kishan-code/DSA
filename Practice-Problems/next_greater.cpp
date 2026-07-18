#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &v){
    vector<int> nge(v.size(), -1);
    stack<int> st;
    for(int i = 0; i < v.size();i++){
        while(!st.empty() && v[st.top()] < v[i]){
            nge[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;
}

int main(){
    /**
     * [4,5,2,25,7,8]
     * 4 -> next greater -> 5
     * 5 -> next greater -> 25
     * 2 -> next greater -> 25
     * 25 -> next greater -> -1 (no element present in the right side of 25 in array that is greater than 25)
     * 7 -> next greater -> 8
     * 8 -> next greater -> -1 (no element present in the right side of 8 int array that is greater than 8)
     */
    vector<int> v = {4,5,2,25,7,8};

    vector<int> ans = NGE(v);

    for(int i = 0; i < ans.size(); i++){
        cout<<v[i]<<" ->  "<<ans[i]<<endl;
    }

    return 0;
}