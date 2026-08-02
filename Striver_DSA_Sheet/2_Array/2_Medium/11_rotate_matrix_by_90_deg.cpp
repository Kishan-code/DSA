/**
 * Problem - 11: Rotate matrix by 90 degrees
 * *************************************************************************************
 * 
 * Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
 * The rotation must be done in place, meaning the input 2D matrix must be modified directly.
 * 
 * Example 1:
 * Input: matrix = |1  2  3|
 *                 |4  5  6|
 *                 |7  8  9|
 * 
 * Output: matrix = |7  4  1|
 *                  |8  5  2|
 *                  |9  6  3|
 * 
 * ****************************************************************************************
 * 
 * Approach -1: Brute Force
 * make a 2D array (ans[n][n]) for storing the answer
 * iterate over the matrix array:
 * row: i = 0 --> n-1
 * column: j = 0 --> n-1
 *  put ans[j][n-i-1] = matrix[i][j]
 * 
 * and return ans array
 * 
 * TC -> O(n²)
 * SC -> O(n²)
 * ****************************************************************************************
 * 
 * Approach -2: Optimal
 * 1) transpose of the matrix
 * 2) reverse each row of the matrix
 * 
 * TC -> O(n²)
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;

 // Brute Force
 vector<vector<int>> roatateMatrix(vector<vector<int>> &mt){
    int n = mt.size();
    vector<vector<int>> ans(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[j][n-i-1] = mt[i][j];
        }
    }
    return ans;
 }

 // Optimal
 void roatateMatrix1(vector<vector<int>> &mt){
    int n = mt.size();

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(mt[i][j], mt[j][i]);
        }
        reverse(mt[i].begin(), mt[i].end());
    }
 } 

 //or

/*
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        swap(mt[i][j], mt[j][i]);
    }
}

for(int i=0;i<n;i++){
    reverse(mt[i].begin(), mt[i].end());
}
*/


 /************************************************************************************* */

 int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    // vector<vector<int>> ans = roatateMatrix(matrix);
    roatateMatrix1(matrix);

    for(auto v: matrix){
        for(auto el: v){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    return 0;
 }