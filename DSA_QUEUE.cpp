/*
-> Queue known as FIFO{ first in first out} data
-> push from back side and pop from front sidesf
-> Queue in respect of STL only 3 operation are there:- 1)push operation{queue ke end me element daalega}
                                                        2)pop operation{front se element niklega}
                                                        3)front operation{front waale element ko dekhna, uski value pta krna}
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string>q;
    q.push("abc");
    q.push("dfc");
    q.push("afrg");
    q.push("thuj");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}

