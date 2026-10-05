#include<iostream>
using namespace std;

/*
Leetcode: Problem-125: Valid Palindrome
**************************************************************************************

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.


Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/

bool isPalinSent(string &s) {
    if(s.empty()) return true;
    
    int left = 0, right = s.length()-1;
    
    while(left < right){
        char leftChar = s[left];
        char rightChar = s[right];
        
        if(!isalnum(leftChar)) left++;
        else if(!isalnum(rightChar)) right--;
        else if(tolower(leftChar) != tolower(rightChar)) return false;
        else{
            left++;
            right--;
        }
    }
    
    return true;
}

// similar problem in GFG

/************************************************************************************ */

int main(void){
    string str = "A man, a plan, a canal: Panama";

    cout<<isPalinSent(str);
}