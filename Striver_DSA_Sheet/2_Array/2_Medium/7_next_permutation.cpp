/**
 * Problem - 7: Next Permutation:
 * ************************************************************************
 * 
 * A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 * For example, for arr = [1,2,3]:
 * the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
 * 
 * The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
 * 
 * For example, the next permutation of arr = [1,2,3] is [1,3,2].
 * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 * While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
 * 
 * Given an array of integers nums, find the next permutation of nums.
 * *************************************************************************
 * 
 * Approach -1: Optimal
 * first iterate over the array in reverse and find the pivot.
 * pivot will be the point where nums[i] < nums[i+1] if we start i from n-2;
 * so  pivot = i
 * 
 * if pivot >= 0
 * then find the just greater number of nums[pivot] from j = n-1;
 * 
 * if we get both pivot and just greater number then swap them.
 * 
 * and reverse the array from (pivot+1, n-1)
 * and we get the next permutation
 * 
 * TC -> O (n)
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;

 void  nextPermutation(vector<int> &v){
    int n = v.size();

    int i = n-1;
    int j = n-1;

    while(i > 0){
        if(v[i-1] >= v[i]) i--;
        else break;
    }

    while(i > 0 && j > i-1){
        if(v[i-1] >= v[j]) j--;
        else{
            swap(v[i-1], v[j]);
            break;
        }
    }
    reverse(v.begin()+i, v.end());
 }

 int main(){
    vector<int> nums = {3,2,1};

    nextPermutation(nums);

    for(auto x: nums) cout<<x<<" ";

    return 0;
 }