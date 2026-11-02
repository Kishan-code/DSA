#include<iostream>
#include <vector>
#include <stack>
using namespace std;

/*
GFG: Stock Span Problem
*******************************************************************************************

The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.

Given an array arr[] representing daily stock prices, the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.

Examples:
Input: arr[] = [100, 80, 90, 120]
Output: [1, 1, 2, 4]
Explanation: Consider each day one by one:
Day 1 (100): Span = 1.
Day 2 (80): Span = 1 because the previous price (100) is greater than 80.
Day 3 (90): Span = 2 because 80 ≤ 90, but 100 > 90.
Day 4 (120): Span = 4 because 100, 80, and 90 are all less than or equal to 120.
Hence, the output is [1, 1, 2, 4].

Input: arr[] = [10, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Consider each day one by one:
Day 1 (10): Span = 1.
Day 2 (4): Span = 1 because the previous price (10) is greater than 4.
Day 3 (5): Span = 2 because 4 ≤ 5, but 10 > 5.
Day 4 (90): Span = 4 because 10, 4, and 5 are all less than or equal to 90.
Day 5 (120): Span = 5 because all previous prices are less than or equal to 120.
Day 6 (80): Span = 1 because the previous price (120) is greater than 80.
Hence, the output is [1, 1, 2, 4, 5, 1].


Constraints:
1 ≤ arr.size(), arr[i] ≤ 10^5
*/

vector<int> calculateSpan(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n,1);
    
    stack<int> st;
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            ans[i] += ans[st.top()];
            st.pop();
        }
        st.push(i);
    }
    
    return ans;
    
}

// similar problem on Leetcode

/**************************************************************************************** */

int main(void){
    vector<int> prices = {10, 4, 5, 90, 120, 80};

    vector<int> ans = calculateSpan(prices);

    for(auto x: ans) cout<<x<<" ";
}