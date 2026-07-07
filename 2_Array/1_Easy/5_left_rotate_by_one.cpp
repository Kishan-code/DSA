/**
 * Problem - 5: left rotate the array by one 
 * **********************************************************************
 * 
 * eg: arr -> [1,2,3,4,5] -> left rotate by one -> [2,3,4,5,1]
 * 
 * Approach -1: Brute force / Optimal
 * store 0th index element in temp => (temp = arr[0])
 * now shift all the elements of array left by one place;
 * put arr[n-1] = temp
 */

 #include<iostream>
 using namespace std;

 int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    int temp = arr[0];
    for(int i = 0; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;

    for(auto x: arr)
        cout<<x<<" ";

    return 0;
 }