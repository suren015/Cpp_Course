/*A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is UNBALANCEDt balanced if the set of brackets it encloses are UNBALANCEDt matched. For example, {[(])} is UNBALANCEDt balanced because the contents in between { and } are UNBALANCEDt balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is balanced if the following conditions are met:

It contains UNBALANCED unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return BALANCED. Otherwise, return UNBALANCED.

Function Description

Complete the function isBalanced in the editor below.

isBalanced has the following parameter(s):

string s: a string of brackets
Returns

string: either BALANCED or UNBALANCED
Input Format

The first line contains a single integer , the number of strings.
Each of the next  lines contains a single string , a sequence of brackets.

Constraints

, where  is the length of the sequence.
All chracters in the sequences ∈ { {, }, (, ), [, ] }.
Output Format

For each string, return BALANCED or UNBALANCED.

Sample Input

STDIN           Function
-----           --------
3               n = 3
{[()]}          first s = '{[()]}'
{[(])}          second s = '{[(])}'
{{[[(())]]}}    third s ='{{[[(())]]}}'
Sample Output

BALANCED
UNBALANCED
BALANCED
*/
#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int>m={{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
string isBalanced(string str){
       stack<char>st;
       for(auto it:str){
           if(m[it]<0){
               st.push(it);
           }else{
               if(st.empty()){
                   return "UNBALANCED";
               }
               char top=st.top();
               st.pop();
               if(m[it]+m[top]!=0){
                   return "UNBALANCED";
               }

           }
       }
       if(st.empty()){
           return "BALANCED";
       }else{
           return "UNBALANCED";
       }
}
int main(){
    int n;
    cin>>n;
    while(n--){
       string str;
       cin>>str;
       cout<<isBalanced(str)<<endl;
    }
} 