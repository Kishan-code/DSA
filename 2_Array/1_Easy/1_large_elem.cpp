/**
 * Problem - 1: find largest element in array.
 *********************************************************************************************************
 * 
 * Approach-1: (Brute force)
 * sort the array in ascending order and last indexed (n-1) element will be the largest.
 * time-complexity(TC) - O(nlogn)
 * space-complexity(SC) - O(1)
 * 
 ********************************************************************************************************* 
 *
 * Approach-2: (Optimal)
 * take a max variable with minimum or arr[0] value, traverse the array, compare each element with max:
 * if element is greater then max
 * then update (max = arr[i])
 * otherwise move next (i++)
 * (TC) - O(n)
 * (SC) - O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force:
int largeElem1(vector<int>  arr){
    sort(arr.begin(), arr.end());
    return arr.at(arr.size()-1);
}

// Optimal:
int largeElem2(vector<int> arr){
    int maxElem = arr[0];
    for(int i = 0; i < arr.size(); i++){
        if(maxElem < arr[i]){
            maxElem = arr[i];
        }
    }
    return maxElem;
}

int main(){
    vector<int> arr = {4,3,8,2,9,1};
    cout<<largeElem1(arr)<<endl;
    cout<<largeElem2(arr)<<endl;
    return 0;
}