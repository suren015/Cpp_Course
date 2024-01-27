/*
-> Stack is known aas LIFO {last in first out} data structure
-> We can access only two elements from stack 1) top element and 2) size
-> 1st operation{push operation}==Stack me element daalna{hmesaa top me dlegaa}
-> 2nd operation{pop operation}==Stack se elements nikalna{hmesaa top element hi niklega}
-> 3rd operation{top element ko dekhna(top operation)}==we can combine top and pop operation
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int>s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
