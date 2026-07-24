/**
 * Problem - 1: Two Sum:
 * *****************************************************************
 * Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.
 * Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in any order.
 * 
 * eg:
 * Input: nums = [1, 6, 2, 10, 3], target = 7
 * Output: [0, 1] ----> nums[0] + nums[1] = 1 + 6 = 7
 * 
 * **************************************************************
 * 
 * Approach -1: Brute Force:
 * we check for all possible combination of two elements in the array
 * and if we get two elements not having same index and their sum (nums[i]+nums[j] == target) 
 * then we return array of indices [i,j]
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * ************************************************************
 * 
 * Approach - 2: Better (Hashing or map):
 * we use hashmap -> unordered map for getting two sum:
 * we store element as key and its index as value in the map.
 * we check (target - nums[i]) key present in the map:
 * [
 *  -> nums = [1,6,2,10,3] and target = 7
 *  -> so nums[i] + nums[j] = target (true atmost once)
 *  -> let assume nums[i] is our current element and if we want to know nums[j] then we simply caluculate [target - current]
 *  -> means nums[j] = target - nums[i]
 *  -> and we are storing elements in the map as key, so we can just find it in the map using as key (if exists)
 * ]
 * if present then we return {map[target-nums[i]], i}
 * else we store map[nums[i]] = i
 * 
 * TC -> O(n)
 * SC -> O(n)
 * ***********************************************************
 * 
 * Approach - 3: Optimal (using two pointers):
 * for using two pointers in two sum it is necessary that the array is sorted:
 * if we sort the array then the sequesnce is disturbed and pair of index will not be as according to the original array:
 * (so it is not better if we have to return pair of index but for checking it is optimat)
 * 
 * we take two pointers i = 0 and j = n-1
 * now get the sum = nums[i]+nums[j]
 * if sum < target
 *  then increase i by 1 (i++)
 * if sum > target
 *  then decrease j by 1 (j--)
 * if sum == target
 *  then return [i, j]
 * 
 * TC -> O(n) + O(logn) for sorting
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 #include<unordered_map>
 #include<algorithm>
 using namespace std;

 // Brute Force:
 vector<int> twoSum1(vector<int> &v, int t){
    vector<int> ans(2,-1);
    int n = v.size();

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if((v[i] + v[j]) == t){
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
 }

 // Better:
 vector<int> twoSum2(vector<int> &v, int t){
    vector<int> ans(2,-1);
    int n = v.size();

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++){
        if(mp.count(t-v[i])){
            ans[0] = mp[t-v[i]];
            ans[1] = i;
            return ans;
        }
        mp[v[i]] = i;
    } 
    return ans;   
 }

 // Optimal:
 vector<int> twoSum3(vector<int> &v, int t){
    vector<int> ans(2,-1);
    int n = v.size();
    int i = 0, j = n-1;
    int sum = 0;

    // we need to sort the array
    sort(v.begin(), v.end());

    while(i < j){
        sum = v[i]+v[j];
        if(sum < t)
            i++;
        else if(sum > t)
            j--;
        else{
            ans[0] = i;
            ans[1] = j;
            return ans;
        }
    }
    return ans;   
 }

 int main(){
    vector<int> nums = {1, 3, 5, -7, 6, -3};
    int target = 0;

    // vector<int> ans = twoSum1(nums, target);
    // vector<int> ans = twoSum2(nums, target);
    vector<int> ans = twoSum3(nums, target);

    for(auto x: ans)
        cout<<x<<" : "<<nums[x]<<endl;
    return 0;
 }