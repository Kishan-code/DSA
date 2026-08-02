/**
 * Problem - 12: Spiral Matrix:
 * *************************************************************************************
 * 
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * Example 1:
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * ← → ↑ ↓
 * 1 → 2 → 3  →  4
 *               ↓
 * 5 → 6 → 7     8
 * ↑             ↓
 * 9 ← 10 ← 11 ← 12
 */

 #include<iostream>
 #include<vector>
 using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> res;

    int left = 0, right = cols-1;
    int top = 0, bottom = rows-1;

    while(left <= right && top <= bottom){
        for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
        top++;
        for(int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
        right--;
        if(top <= bottom){
            for(int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
            bottom--;
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;        
}

// TC -> O(n * m)
// SC -> O(n * m)

/************************************************************************************ */

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    vector<int> ans = spiralOrder(matrix);

    for(auto x: ans) cout<<x<<" ";
    return 0;
}