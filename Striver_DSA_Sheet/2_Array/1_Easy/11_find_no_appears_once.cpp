/**
 * Problem - 11: Find the number that appears once, and other numbers twice.
 * ****************************************************************************
 * 
 * eg:  nums = [1, 2, 2, 4, 3, 1, 4] -> 3 appear only once
 * 
 * ****************************************************************************
 * 
 * Approach - 1: Brute Force (using linear search):
 * create a count variable
 * now create two nested loops
 * 1) for i = 0 -> n
 *      count = 0
 *      2) for j = 0 -> n
 *          if nums[i] == nums[j]
 *          then count++
 *      if(coutn == 1)
 *       then return nums[i]
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * **************************************************************************
 * 
 * Approach -2: Better (using hashing/ map):
 * create a map<int, int>
 * now iterate on the array and store elements of the array in the map as key
 * if map[nums[i]] exits
 * then map[nums[i]]++
 * otherwise
 * map[nums[i]] = 1;
 * 
 * now iterate on the map
 * and check which key has the value 1 and return that key
 * 
 * TC -> O(nlogm) + O(n/2 + 1) => m is the size of the map
 * SC -> O(n/2 + 1)
 * 
 * *************************************************************************
 * 
 * Approach -3: Optimal (using XOR):
 * use the properties of XOR (^) operator:
 * a ^ a = 0
 * 0 ^ a = a ^ 0 = a
 * 
 * create a variable ans = 0
 * iterate on the array and perform (ans = ans ^ nums[i])
 * return ans;
 * 
 * TC -> O(n)
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 #include<map>
 using namespace std;


 // Brute Force:
 int numAppearOnce1(vector<int> &v){
    int count;

    for(int i = 0; i < v.size(); i++){
        count = 0;
        for(int j = 0; j < v.size(); j++){
            if(v[i] == v[j]){
                count++;
            }
        }
        if(count == 1) return v[i];
    }
 }


 // Better:
  int numAppearOnce2(vector<int> &v){
    map<int, int> mp;

    for(auto x: v){
        if(mp.count(x)){
            mp[x]++;
        } else{
            mp[x] = 1;
        }
    }

    for(auto x: mp){
        if(x.second == 1)
         return x.first;
    }

 }

 // Optimal:
  int numAppearOnce3(vector<int> &v){
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        ans ^= v[i];
    }

    return ans;
 }



 int main(){
    vector<int> arr = {1,1,2,3,3,4,4,2,6};

    // cout<<numAppearOnce1(arr);
    // cout<<numAppearOnce2(arr);
    cout<<numAppearOnce3(arr);

    return 0;
 }