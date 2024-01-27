#include <bits/stdc++.h>
using namespace std;
class info{
    private:
    int health;
    char level;
    public:
    int gethealth(){
        return health; 
    }
    char getlevel(){
        return level;
    }
    void sethealth(int h){
        health=h;
    }
    void setlevel(char ch){
        level=ch;
    }

}i;
int main(){
    
    cout<<sizeof(i)<<endl;
    i.sethealth(70);
    cout<<i.gethealth()<<endl;
    i.setlevel('A');
    cout<<i.getlevel()<<endl;
}    