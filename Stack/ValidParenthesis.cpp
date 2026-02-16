/*
Problem : Valid Parentheses
Rule:
• Follows LIFO

Approach:
• Opening bracket → push
• Closing bracket → check top & pop
• Mismatch or empty stack → invalid
• Stack empty at end → valid

Matching:
• ')' → '('
• '}' → '{'
• ']' → '['

Complexity:
• Time: O(n)
• Space: O(n)
*/

#include<iostream>
#include<stack>
using namespace std;
bool isvalid(string str){
    stack<char>st;

    for(int i=0;i<str.size();i++){

        if(str[i]=='(' || str[i]=='{' || str[i]=='['){ //Opening cases //
            st.push(str[i]);
        }
        else{ //Closing cases //

            if(st.size() == 0) return false;

            if(st.top()=='(' && str[i]==')' || st.top()=='{' && str[i]=='}' || st.top()=='[' && str[i]==']'){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.size()==0;
}

int main(){
    //given quesion of string //
    string str = {'(','{','[',']','}',')'};
    // int check = isvalid(str);
    if(isvalid(str)){
        cout<<"is validParenthesis";
    }else{
        cout<<"is not validParanthesis";
    }

}