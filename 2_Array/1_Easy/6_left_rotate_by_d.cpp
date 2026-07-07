/**
 * Problem - 6: left rotate the array by d places.
 * ***************************************************************
 * 
 * eg: d = 2
 * arr -> [1,2,3,4,5,6,7] -> left rotate by d(3) places -> [3,4,5,6,7,1,2]
 * 
 * Approach -1: Brute Force:
 * use two nested loops
 * 1) i = 0 -> i < d
 *      => store temp = arr[0]
 *      2) j = 0 -> j < n-1
 *          => arr[j] = arr[j+1]
 *      arr[n-1] = temp
 * 
 * TC -> O(d*n)
 * SC -> O(1)
 * ******************************************************************
 * 
 * Approach -2: Better:
 * create a temp array of size d
 * put first d elements of arr in temp array => [TC -> O(d)]
 * now shift remaining elements in arr from dth index as: (dth -> 0th), ((d+1)th -> th) and so on. => [TC -> O(n-d)]
 * now put temp array elements back to arr form index (n-d) to (n-1). => [TC -> O(d)]
 * 
 * TC  -> O(d+n)
 * SC -> O(d)
 */

 #include<iostream>
 using namespace std;

 void leftRotate1(int* arr, int n, int d){
    for(int i = 0; i < d; i++){
        int temp = arr[0];
        for(int j = 0; j < n-1; j++){
            arr[j] = arr[j+1];
        }
        arr[n-1] = temp;
    }
 }

 void leftRotate2(int* arr, int n, int d){
    int temp[d];
    int i;
    // putting arr -> tmep
    for(i = 0; i < d; i++){
        temp[i] = arr[i];
    }

    //shifting
    for(i = d; i < n; i++){
        arr[i-d] = arr[i];
    }


    //putting temp -> arr
    for(i = n-d; i < n; i++){
        arr[i] = temp[i-(n-d)];
    }
 }


 int main(){
    int n = 7, d = 3;
    int arr[n] = {1,2,3,4,5,6,7};
    leftRotate2(arr, n, d);

    for(auto x: arr)
        cout<<x<<" ";

    return 0;
 }