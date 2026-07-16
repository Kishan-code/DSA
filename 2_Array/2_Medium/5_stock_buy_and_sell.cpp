/**
 * Problem - 5: Best time to buy and sell stock:
 * ****************************************************************
 * 
 * Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock at most once. 
 * The stock should be purchased before selling it, and both actions cannot occur on the same day.
 * 
 * eg:
 * Input: arr = [10, 7, 5, 8, 11, 9]
 * Output: 6 ---> Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit = 11 - 5 = 6.
 * ****************************************************************
 * 
 * Approach -1: Brute Force:
 * finding the all possible profits.
 * 
 * profit that is maximum among all the profits, we will return it.
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * 
 */

 #include<iostream>
 #include<vector>
 using namespace std;


 // Brute Force:
 int stockBuyAndSell(vector<int> &v){
    int n = v.size();
    int maxProfit = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(maxProfit < v[j]-v[i]){
                maxProfit = v[j] - v[i];
            }
        }
    }

    return maxProfit;
 }

 int main(){
    vector<int> prices = {10, 7, 5, 8, 11, 9};

    cout<<stockBuyAndSell(prices)<<endl;

    return 0;
 }