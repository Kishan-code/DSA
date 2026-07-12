#include <bits/stdc++.h>
using namespace std;


string isBalanced(string s) {
    unordered_map<char, int> brackets = {{'[', -1},{'{', -2},{'(', -3},{']', 1},{'}', 2},{')', 3}};
    stack<char> ch;
    
    for(auto bracket: s){
        if(brackets[bracket] < 0){
            ch.push(bracket);
        }else{
            if(ch.empty()) return "NO";
            char top = ch.top();
            if((brackets[bracket] + brackets[top]) != 0) return "NO";
            else ch.pop();
        }
    }
    if(ch.empty()) return "YES";
    return "NO";
}

int main()
{
    string str = "{{[[(())]]}}";
    cout<<isBalanced(str);

    return 0;
}
