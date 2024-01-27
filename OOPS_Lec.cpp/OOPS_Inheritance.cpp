#include <bits/stdc++.h>
using namespace std;
class human{
    public:
    string name;
    int height;
    int age;
    int weight;
    int getweight(int w){
        weight = w;
        return w;
    }
}h1;

class male:public human{
    public:
    string colour;
    void sleep(){
        cout<<"Man is sleeping"<<endl;
    }

}m1;
int main(){
    m1.name="Surendra";
    m1.height=157;
    m1.age= 18;
    m1.colour="blue";
    cout<<m1.name<<" "<<m1.height<<" "<<m1.age<<" "<<m1.colour<<endl;
    m1.sleep();
    cout<<m1.getweight(45)<<endl;


}