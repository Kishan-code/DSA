/**
 * Problem - 2: find second largest element in array.
 * **********************************************************************
 * 
 * Approach-1 Brute force
 * sort the array in ascending order and check form (n-2)th index element is not equal to (n-1)th element:
 * if yes then it is second largest 
 * otherwise (n-3) and so on...
 * TC (sort) - O(nlogn)
 * TC (find second element) - O(n)
 * space-complexity(SC) - O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force:
int secondLargeElem1(vector<int>  arr){
    sort(arr.begin(), arr.end());
    int i = arr.size()-2;
    while(i >= 0){
        if(arr[i] != arr[i+1]){
            return arr[i];
        }
        i--;
    }
    return arr[0];
}

int main(){
    vector<int> arr = {9,9,9,9,9,9};
    cout<<secondLargeElem1(arr)<<endl;
    return 0;
}