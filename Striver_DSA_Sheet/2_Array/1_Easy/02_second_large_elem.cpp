/**
 * Problem - 2: find second largest element in array.
 * **********************************************************************
 * 
 * Approach-1: (Brute force)
 * sort the array in ascending order and check form (n-2)th index element is not equal to (n-1)th element:
 * if yes then it is second largest 
 * otherwise (n-3) and so on...
 * TC (sort) - O(nlogn)
 * TC (find second element) - O(n)
 * space-complexity(SC) - O(1)
 * 
 * ***********************************************************************
 * 
 * Approach-2: (Optimal)
 * get the largest element by traversing:
 * if largest variable updates
 * then the previous largest value becomes the second largest.
 * TC - O(n)
 * SC - O(1)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force:
int secondLargeElem1(vector<int>&  arr){
    if(arr.size() < 2)
        throw invalid_argument("Second largest does not exist.");

    sort(arr.begin(), arr.end());
    int i = arr.size()-2;
    while(i >= 0){
        if(arr[i] != arr[i+1]){
            return arr[i];
        }
        i--;
    }

    throw invalid_argument("Second largest does not exist.");
}

// Optimal:
int secondLargeElem2(vector<int>&  arr){
    if(arr.size() < 2)
        throw invalid_argument("Second largest does not exist.");

    int secondLargest = -1; // put negative infinite if negative values are allowed
    int largest = arr[0];
    bool flag = false;

    for(int i = 1; i < arr.size(); i++){
        if(largest < arr[i]){
            secondLargest = largest;
            largest = arr[i];
            flag = true;
        }
        else if(secondLargest < arr[i] && arr[i] < largest){
            secondLargest = arr[i];
            flag = true;
        }
    }
    if(flag){
        return secondLargest;
    }
    else{
        throw invalid_argument("Second largest does not exist.");
    }
}

int main(){
    vector<int> arr = {7,7};
    cout<<secondLargeElem2(arr)<<endl;
    return 0;
}