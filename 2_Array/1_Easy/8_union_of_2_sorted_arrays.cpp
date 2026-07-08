/**
 * Problem - 8: Union of two sorted arrays:
 * *********************************************************************
 * 
 * eg: 
 * arr1[] = {1,1,2,3,4,5}
 * arr2[] = {2,3,4,4,5}
 * union[] = arr1 U arr2 = [1,2,3,4,5]
 * ******************************************************************
 * 
 * Approach -1: Brute force:
 * create a set - st
 * iterate first array and add its elements to the set: st.insert(arr1[i]) => [TC -> O(n1logn)]: n1 -> size of arr1, n -> size of set
 * iterate second array and add its elements to the set: st.insert(arr2[i]) => [TC -> O(n2logn)]: n2 -> size of arr2, n -> size of set
 * now we get all unique elements in the set
 * now iterate the set and add all elements in the temp array and return it. => [TC -> O(n1+n2)]: if all elements are unique in both array.
 * 
 * TC -> O(n1logn + n2logn) + O(n1 + n2)
 * SC -> O(n1 + n2) + O(n1 + n2)
 * ********************************************************************
 * 
 * Approach -2: Optimal (using two pointer);
 * create two pointers i and j
 * initialize i = 0, j = 0
 * now compare if arr1[i] <= arr2[j]
 * then check, arr1[i] is present in union array if not then store it (temp.push_back(arr1[i]));
 * and i++;
 * else
 * check, arr2[j] is present in union array if not then store it (temp.push_back(arr2[j]));
 * and j++;
 * do it unitl any of the array is exhausted
 * repeat the process for the unexhausted array seperately
 * 
 * TC -> O(n1 + n2)
 * SC -> O(n1 + n2) for returning the answer
 * 
 */

 #include<iostream>
 #include<vector>
 #include<set>
 using namespace std;

 // Brute force:
 vector<int> union1(vector<int> &a, vector<int> &b){
    set<int> st;
    vector<int> temp;

    for(int i = 0; i < a.size(); i++){
        st.insert(a[i]);
    }
    for(int i = 0; i < b.size(); i++){
        st.insert(b[i]);
    }

    for(auto x: st){
        temp.push_back(x);
    }

    return temp;
 }

 // Optimal:
 vector<int> union2(vector<int> &a, vector<int> &b){
    vector<int> temp;
    int i = 0, j = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            if(temp.size() == 0 || temp.back() != a[i]){
                temp.push_back(a[i]);
            }
            i++;
        }
        else{
            if(temp.size() == 0 || temp.back() != b[j]){
                temp.push_back(b[j]);
            }
            j++;
        }
    }

    while(i < a.size()){
        if(temp.size() == 0 || temp.back() != a[i]){
            temp.push_back(a[i]);
        }
        i++;        
    }

    while(j < b.size()){
        if(temp.size() == 0 || temp.back() != b[j]){
            temp.push_back(b[j]);
        }
        j++;        
    }

    return temp;
 }

 int main(){
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5,6};

    // vector<int> unionArr = union1(arr1, arr2);
    vector<int> unionArr = union2(arr1, arr2);

    for(auto x: unionArr)
        cout<<x<<" ";

 }