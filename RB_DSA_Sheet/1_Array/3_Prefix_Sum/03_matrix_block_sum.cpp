#include<iostream>
#include<vector>
using namespace std;

/*
Leetcode: Problem-1314: Matrix Block Sum
*********************************************************************************************

Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100
*/

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j<= cols; j++){
            prefix[i][j]
            = prefix[i-1][j]
            + prefix[i][j-1]
            + mat[i-1][j-1]
            - prefix[i-1][j-1];
        }
    }

    vector<vector<int>> ans(rows, vector<int>(cols,0));
    int r,r1,c,c1;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            r = max(1, i-k);
            c = max(1, j-k);
            r1 = min(rows, i + k);
            c1 = min(cols, j + k);

            ans[i-1][j-1]
            = prefix[r1][c1]
            - prefix[r1][c-1]
            - prefix[r-1][c1]
            + prefix[r-1][c-1];
        }
    }

    return ans;
}

/*
GFG: 2D Submatrix Sum Queries
********************************************************************************************

Given a 2D integer matrix mat[][] and a list of queries queries[][], your task is to answer a series of submatrix sum queries.

Each query is represented as a list [r1, c1, r2, c2], where:

(r1, c1) is the top-left coordinate of the submatrix
(r2, c2) is the bottom-right coordinate of the submatrix (both inclusive)
Your task is to return a list of integers, the sum of elements within the specified submatrix for each query.

Examples: 
Input: mat[][] = [[1, 2, 3], queries[][] = [[0, 0, 1, 1], [1, 0, 2, 2]]
                [1, 1, 0],
                [4, 2, 2]]
Output: [5, 10]
Explanation: 
Query 1 selects submatrix [[1, 2], [1, 1]] → sum = 5.
Query 2 selects submatrix [[1, 1, 0], [4, 2, 2]] → sum = 10.

Input: mat[][] = [[1, 1, 1], queries[][] = [[1, 1, 2, 2], [0, 0, 2, 2], [0, 2, 2, 2]]
                [1, 1, 1],
                [1, 1, 1]]
Output: [4, 9, 3]
Explanation: 
Query 1 selects submatrix [[1, 1], [1, 1]] → sum = 4.
Query 2 selects submatrix [[1, 1, 1], [1, 1, 1], [1, 1, 1]] → sum = 9.
Query 3 selects submatrix [[1], [1], [1]] → sum = 3.


Constraints:
1 ≤ n × m, q ≤ 10⁵
0 ≤ mat[i][j] ≤ 10⁴
0 ≤ r1 ≤ r2 ≤ n - 1
0 ≤ c1 ≤ c2 ≤ m - 1
*/

vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
    int rows = mat.size();
    int cols = mat[0].size();
    int n = queries.size();
    
    vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));
    
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            prefix[i][j]
            = mat[i-1][j-1]
            + prefix[i][j-1]
            + prefix[i-1][j]
            - prefix[i-1][j-1];
        }
    }
    
    vector<int> ans(n, 0);
    
    for(int i = 0; i < n; i++){
        int r1 = queries[i][0];
        int c1 = queries[i][1];
        int r2 = queries[i][2];
        int c2 = queries[i][3];
        
        r1++;
        c1++;
        r2++;
        c2++;
        
        ans[i]
        = prefix[r2][c2]
        - prefix[r2][c1-1]
        - prefix[r1-1][c2]
        + prefix[r1-1][c1-1];
    }
    return ans;
}

/************************************************************************************ */

int main(void){
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int k = 1;

    vector<vector<int>> queries = {
        {0,0,1,1},
        {1,0,2,2}
    };

    vector<vector<int>> ans1 = matrixBlockSum(mat, k);
    vector<int> ans2 = prefixSum2D(mat, queries);

    for(auto v: ans1){
        for(auto x: v){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    cout<<"************************************************************"<<endl;

    for(auto x: ans2)
        cout<<x<<" ";
}