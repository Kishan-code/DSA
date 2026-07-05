/**
 * Problem - 3: check if the array is sorted or not.
 * *****************************************************************
 * 
 * Approach-1: (Brute force)
 * traverse the array and check elements with its next adjacent element:
 * if (arr[i] <= arr[i+1]) - (for ascending order)
 * then i++
 * otherwise the array is not sorted
 * TC - O(n)
 * SC - O(1)
 */

 #include<iostream>
 #include<vector>
 using namespace std;

 bool isArraySorted(vector<int>& arr){
    for(int i = 0; i < arr.size()-1; i++){
        if(arr[i] <= arr[i+1])
            continue;
        return false;
    }
    return true;
 }

 int main(){
    vector<int> arr = {3,4,5,5};
    cout<<isArraySorted(arr);
    return 0;
 }