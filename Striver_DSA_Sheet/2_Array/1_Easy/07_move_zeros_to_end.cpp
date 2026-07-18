/**
 * Problem - 7: Move all zeros to the end of the array.
 * *************************************************************************
 * 
 * eg: [1,0,2,3,2,0,0,4,5,1] -> [1,2,3,2,4,5,1,0,0,0]
 * 
 * Approach -1: Brute Force:
 * put all non zero elements to another temp array of vector
 * now put temp all elements in arr from 0 to temp.size() and put 0 on the remaining index.
 * 
 * TC -> O(2n)
 * SC -> O(x) [x = no. of non zero elements]
 * ***********************************************************************
 * 
 * Approach -2: Optimal (Two pointer):
 * create two pointers i and j;
 * initialize j = 0
 * for(i = 0 ->  n)
 * if(arr[j] != 0) then j++
 * else if(arr[j] == 0 && arr[i] != 0) 
 *      then swap(arr[i], arr[j]) and j++;
 * 
 * TC -> O(n)
 * SC -> O(1)
 * 
 */

 #include<iostream>
 #include<vector>
 using namespace std;


 // Brute Force:
 void moveZeros1(vector<int> &v){
    vector<int> temp;

    // put non-zero elems to temp
    for(int i = 0; i < v.size(); i++){
        if(v[i] != 0){
            temp.push_back(v[i]);
        }
    }

    // put temp elements to v again from 0 to temp.size() otherwise put 0
    for(int i = 0; i < v.size(); i++){
        if(i < temp.size()){
            v[i] = temp[i];
        }
        else{
            v[i] = 0;
        }
    }
 }

 // Optimal:
 void moveZeros2(vector<int> &v){
    int i = 0, j = 0;
    while(i < v.size()){
        if(v[j] != 0){
            j++;
        }
        else if(v[j] == 0 && v[i] != 0){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            j++;
        }
        i++;
    }
 }

int main(){
    vector<int> arr = {1,0,2,3,2,0,0,4,5,1};

    moveZeros2(arr);

    for(auto x: arr)
        cout<<x<<" ";

    return 0;
}