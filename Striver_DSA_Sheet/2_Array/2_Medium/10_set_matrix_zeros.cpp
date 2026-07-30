/**
 * Problem - 10: Set Matrix Zeroes
 * *********************************************************************************
 * 
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0. You must do it in place.
 * 
 * eg:
 * Input: matrix = |1  1  1|
 *                 |1  0  1|
 *                 |1  1  1|
 * 
 * Output: |1  0  1|
 *         |0  0  0|
 *         |1  0  1|
 * 
 * Explanation: Element at position (1,1) is 0, so set entire row 1 and column 1 to 0.
 * **********************************************************************************
 * 
 * Approach -1: Brute Force
 * in brute force we will convert 0 element's entire row and column to -1
 * and after this we convert all elements -1 to 0
 * 
 * |1  1  1|     |1  -1  1|     |1  0  1|
 * |1  0  1| --> |-1 -1 -1| --> |0  0  0|
 * |1  1  1|     |1  -1  1|     |1  0  1|
 * 
 * TC -> O((n*m)*(n*m)+(n*m)) ≃ O(x³)
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 using namespace std;

 // Brute force
 void markRow(vector<vector<int>> &a, int r){
    for(int j = 0; j < a[0].size(); j++){
        if(a[r][j] != 0) a[r][j] = -1;
    }
 }

 void markCol(vector<vector<int>> &b, int c){
    for(int i = 0; i < b.size(); i++){
        if(b[i][c] != 0) b[i][c] = -1;
    }
 }

 void setMatrixZeros1(vector<vector<int>> &v){
    int rows = v.size();
    int cols = v[0].size();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(v[i][j] == 0){
                markRow(v,i);
                markCol(v,j);
            }
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(v[i][j] == -1) v[i][j] = 0;
        }
    }
 }

 //****************************************************************************** */

 int main(){
    vector<vector<int>> matrix ={{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    setMatrixZeros1(matrix);

    for(auto &x: matrix){
        for(auto el: x)
            cout<<el<<" ";
        cout<<endl;
    }

    return 0;
 }