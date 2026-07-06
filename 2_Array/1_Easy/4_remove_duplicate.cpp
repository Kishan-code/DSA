/**
 * Problem - 4: Remove duplicates from sorted array.
 * *********************************************************************
 * 
 * Approach -1: using two pointer
 * keep two pointers i = 0 and j = 0;
 * if (arr[i] == arr[j])
 * then j++
 * otherwise i++ and put arr[i] = arr[j]
 * and repeat until (j < n)
 * return i+1
 */

 #include<bits/stdc++.h>
 using namespace std;

 int removeDuplicates(vector<int>& arr){
    int i = 0, j = 0;
    while(j < arr.size()){
        if(arr[i] == arr[j]){
            j++;
        }
        else{
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
 }

 int main(){
    vector<int> arr = {-2, 2, 4, 4, 4, 4, 5, 5};
    int n = removeDuplicates(arr);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    return 0;
 }