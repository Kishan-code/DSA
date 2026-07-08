/**
 * Problem - 9: Find missing number in an array:
 * ************************************************************************
 * Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.
 * 
 * eg-1:
 * arr =  [0, 2, 3, 1, 4]
 * missing no -> 5
 * eg-2:
 * arr = [0, 1, 2, 4, 5, 6]
 * missing no -> 3
 * 
 * Approach -1: Brute Force
 * first sort the array
 * and initialize a variable i = 0;
 * and compare i with each element of the array
 * if arr[i] == i
 * then i++
 * otherwise break the loop end return i;
 * 
 * TC -> if array is sorted then -> O(n) otherwise O(logn)+O(n)
 * SC -> O(1)
 */


 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;

 int findMissingNum(vector<int> &v){
    sort(v.begin(), v.end());

    int i = 0;
    while(i < v.size()){
        if(v[i] != i){
            break;
        }
        i++;
    }

    return i;
 }

 int main(){

    vector<int> arr = {0, 1, 2, 4, 5, 6};
    cout<<findMissingNum(arr);
    return 0;
 }