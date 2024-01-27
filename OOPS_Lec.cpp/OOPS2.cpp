#include <bits/stdc++.h>
using namespace std;
class info{
    private:
    int health;
    public:
    char level;
   
    int gethealth(){
        return health;
    }
    void sethealth(int h){
        health=h;
    }
}a;
int main(){


    
    //static allocation
   a.level='B';
   a.sethealth(80);
   cout<<a.gethealth()<<endl;
   cout<<a.level<<endl;



   //dynamically allocation
   info *b=new info;
   (*b).level='N';
   (*b).sethealth(90);
   cout<<b->gethealth()<<endl;
   cout<<b->level<<endl;

   //size
   cout<<sizeof(a.gethealth())<<endl;
   cout<<sizeof(b->gethealth())<<endl;
   cout<<sizeof(a.level)<<endl;
   cout<<sizeof(b->level)<<endl;
   cout<<sizeof(info)<<endl;
}