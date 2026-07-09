/**
 * Problem - 10: Maximum consecutive ones:
 * *********************************************************************
 * eg: arr = [0,0,1,1,0,1,1,1,1,0,0,1,1] -> max consecutive ones -> 4
 * 
 * **********************************************************************
 * 
 * Approach - 1:
 * make a maxCount and count variable and initialize them with 0.
 * now iterate over array and check each element:
 * if(arr[i] == 1)
 * then count++
 * otherwise check if (count > maxCount)
 * then put count into maxCount and make count = 0
 * do this until all elements are traversed
 * and return maxCount.
 * 
 * TC - > O(n)
 * SC -> O(1)
 * 
 */

 #include<iostream>
 #include<vector>
 using namespace std;

 int maxOnes(vector<int> &v){
    int maxCount = 0, count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 1){
            count++;
        } else{
            if(count > maxCount)
                maxCount = count;
            count = 0;
        }
    }
    return maxCount;
 }

 int main(){

    vector<int> arr = {0,0,1,1,0,1,1,1,1,0,0,1,1};

    cout<<maxOnes(arr);

    return 0;
 }