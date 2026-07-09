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
 * TC -> if array is sorted then -> O(n) otherwise O(nlogn)+O(n)
 * SC -> O(1)
 * ************************************************************************
 * 
 * Approach -2: Better (using hashmap):
 * create a map and store all the element as: map[arr[i]] = arr[i];
 * here key and value is same.
 * now iterate the map and form j = 0 to j = n
 * if map[j] is present then j++
 * otherwise break the loop
 * and return j;
 * 
 * TC -> O(2n)
 * SC -> O(n)
 * *********************************************************************
 * 
 * Approach -3: Optimal:
 * get the exact sum of n number using formula: n(n+1)/2
 * and get the sum of all numbers present in the array
 * if exact sum is equal to array sum then retrun 0
 * otherwise return (exact sum) - (array sum)
 * 
 * TC -> O(n)
 * SC -> O(1)
 */


 #include<iostream>
 #include<vector>
 #include<map>
 #include<algorithm>
 using namespace std;

 // Brute force:
 int findMissingNum1(vector<int> &v){
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

 // Better (using hash map):
 int findMissingNum2(vector<int> &v){
    map<int, int> mp;

    for(int i = 0; i < v.size(); i++){
        mp[v[i]] = v[i];  
    }

    int j = 0;
    while(j < v.size()){
        if(!mp.count(j)){
            break;
        }
        j++;
    }
    
    return j;
 }

 // Optimal (using sum):
 int findMissingNum3(vector<int> &v){
    int arrSum = 0, exactSum = 0;
    int n = v.size();

    exactSum = (n*(n+1))/2;

    for(auto x: v){
        arrSum += x;
    }

    if(arrSum == exactSum) return 0;
    else return exactSum - arrSum;
 }

 int main(){

    vector<int> arr = {0, 1, 2, 4, 5, 6};
    // cout<<findMissingNum1(arr);
    // cout<<findMissingNum2(arr);
    cout<<findMissingNum3(arr);
    return 0;
 }