/**
 * Problem - 3: Majority Element-I
 * ***************************************************************
 * 
 * Given an integer array nums of size n, return the majority element of the array.
 * The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.
 * 
 * eg:
 * Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]
 * Output: 7 -> (The number 7 appears 5 times in the 9 sized array)
 * ***************************************************************
 * 
 * Approach - 1: Brute Force:
 * we iterate the array for each element:
 * for every nums[i] == nums[j] we increase the count by 1 (count++)
 * after iteration for first element we check is (count > n/2) if yes then we return that element (nums[i])
 * otherwise we make count 0 (count = 0) and do again this process for next element and so on.
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * ***************************************************************
 * 
 * Approach - 2: Better (using hashing or map):
 * we iterate over the array and set element as key and their count as value in the map:
 * i.e., map[nums[i]]++;
 * now after iterating on the array we will iterate on the map and check if any elemene's count found greater then n/2 then we return that element.
 * 
 * TC -> O(n) -> in average case of unordered map
 * SC -> O(n)
 * **************************************************************
 * 
 * Approach -3: Optimal (Moore's Voting Algorithm):
 * in Morre's voting algorith we iterate over the array:
 * we create two variables freq = 0 (for frequency) and ans (for majority element)
 * if freq == 0 then put ans = nums[i]
 * and if (nums[i] == ans) increase frequency by 1 (freq++)
 * otherwise decrease frequency by 1 (freq--)
 * 
 * if element that is mojority in the array i.e., (element > n/2):
 * then the freq will not be zero for that element
 * 
 * for example: [7, 0, 0, 1, 7, 7, 2, 7, 7]
 * size of this array is 9.
 * the majority element must be greater then n/2 i.e., ( > 9/2 ≈ 4)
 * if any element that is greater than 4 let assume its frequency is 5 so remaining elements will be (9-5 = 4)
 * and freq = 5-4 = 1 which is not equal to zero.
 * 
 * TC O(n) + O(n) -> for checking the answer if array might not have majority element
 * SC O(1)
 * 
 */

 #include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;

 // Brute Force:
 int majorityElement1(vector<int> &v){
    int n = v.size();
    int count;

    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if(v[i] == v[j]) count++;
        }
        if(count > n/2) return v[i];
    }

    return -1;
 }

 // Better:
 int majorityElement2(vector<int> &v){
    int n = v.size();
    unordered_map<int, int> mp;
    
    for(auto elem: v){
        mp[elem]++;
    }

    for(const auto &x: mp){
        if(x.second > n/2) return x.first;
    }

    return -1;
 } 

 // Optimal (Moore's Voting Algorithm):
 int MVA(vector<int> &v){
    int n = v.size();
    int freq = 0;
    int ans;

    for(int i = 0; i < n; i++){
        if(0 == freq) ans = v[i];
        if(v[i] == ans) freq++;
        else freq--;
    }

    return ans;
 } 


 int main(){
    vector<int> nums = {7, 0, 0, 1, 7, 7, 2, 7, 7};

    // cout<<majorityElement1(nums)<<endl;
    // cout<<majorityElement2(nums)<<endl;
    cout<<MVA(nums)<<endl;

    return 0;
 }