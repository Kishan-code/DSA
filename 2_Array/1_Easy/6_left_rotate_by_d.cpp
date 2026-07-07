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
 * ********************************************************************
 * 
 * Approach -3: Optimal:
 * using reverse:
 * 1) reverse arr from 0th to (d-1)th index [d = 3] => [TC -> O(d)]
 *      [1,2,3,4,5,6,7] -> [3,2,1,4,5,6,7]
 * 2) reverse arr from dth to (n-1)th index [n=7] => [TC -> O(n-d)]
 *      [3,2,1,4,5,6,7] -> [3,2,1,7,6,5,4]
 * 3) reverse arr from 0th to (n-1)th index => [TC -> O(n)]
 *      [3,2,1,7,6,5,4] -> [4,5,6,7,1,2,3]
 * 
 * TC -> O(2n)
 * SC -> O(1)
 */

 #include<iostream>
 using namespace std;
 
 // Brute force:
 void leftRotate1(int* arr, int n, int d){
    for(int i = 0; i < d; i++){
        int temp = arr[0];
        for(int j = 0; j < n-1; j++){
            arr[j] = arr[j+1];
        }
        arr[n-1] = temp;
    }
 }
 
 // Better:
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

 // Optimal:
 void reverse(int* arr, int low, int high){
    while(low < high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
 }


 int main(){
    int n = 7, d = 4;
    int arr[n] = {1,2,3,4,5,6,7};

    // leftRotate1(arr, n, d);
    // leftRotate2(arr, n, d);

    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);

    for(auto x: arr)
        cout<<x<<" ";

    return 0;
 }