/**
 * Problem - 2: Sort an array of 0's 1's and 2's:
 * ********************************************************************
 * 
 * Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.
 * The sorting must be done in-place, without making a copy of the original array.
 * eg:
 * Input: nums = [1, 0, 2, 1, 0]
 * Output: [0, 0, 1, 1, 2]
 * *******************************************************************
 * 
 * Approach - 1: Brute Force:
 * sort by using any sorting technique
 * i) Bubble Sort [TC -> O(n²), SC -> O(1)]
 * ii) Selection Sort [TC -> O(n²), SC -> O(1)]
 * iii) insertion Sort [TC -> O(n²), SC -> O(1)]
 * iii) Quic Sort [TC -> O(nlogn), SC -> O(1)]
 * iii) Merge Sort [TC -> O(nlogn), SC -> O(n)]
 * *****************************************************************
 * 
 * Approach -2: Better:
 * we find the count of 0's, 1's and 2's
 * now fill 0's in the nums array from 0 -> count_0
 * now fill 1's in the nums array from count_0 -> count_0 + count_1
 * now fill 2's in the nums array from count_0 + count_1 -> n
 * 
 * TC -> O(2n)
 * SC -> O(1)
 * ***************************************************************
 * 
 * Approach - 3: Optimal (Dutch National Flag Algorithm):
 * it works on three pointers: low, mid and high.
 * [0 -> low-1] -> 0 extreme left
 * [low -> mid-1] -> 1
 * [high+1 -> n-1] -> 2 extreme right
 * 
 * means range [mid -> high] is unsorted and we have to sort it.
 * put low = 0, mid = 0 and high = n-1
 * check if(nums[mid] == 0) then swap(nums[low], nums[mid]) and low++, mid++
 * check if(nums[mid] == 1) then only mid++
 * check if(num[mid] == 2) then swap(nums[mid], nums[high]) and high--
 *  do this until (mid <= high)
 * 
 * TC -> O(n)
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;

 // Better:
 void sorting1(vector<int> &v){
    int n = v.size();
    int i;
    int count_0 = 0, count_1 = 0, count_2 = 0;

    for(i = 0; i < n; i++){
        if(0 == v[i])
            count_0++;
        else if(1 == v[i])
            count_1++;
        else
            count_2++;
    }

    for(i = 0; i < count_0; i++) v[i] = 0;
    for(i = count_0; i < count_0 + count_1; i++) v[i] = 1;
    for(i = count_0 + count_1; i < n; i++) v[i] = 2;
 }

 // Optimal: (Dutch Nation flag also)
 void DNF(vector<int> &v){
    int n = v.size();
    int low = 0, mid = 0, high = n-1;

    while(mid <= high){
        if(v[mid] == 0){
            swap(v[low], v[mid]);
            low++;
            mid++;
        }
        else if(v[mid] == 2){
            swap(v[mid], v[high]);
            high--;
        }
        else{
            mid++;
        }
    }
 }


 int main(){
    vector<int> nums = {1,2,0,0,2,0,2,0,1,2,1,2,1,0};

    // sorting1(nums);
    DNF(nums);

    for(auto x: nums)
        cout<<x<<" ";

    return 0;
 }