#include <bits/stdc++.h>
using namespace std;

class student{

    private:
        string name;
        int age;
        int height;

    public:
        int getAge(){
            return this->age;
        }

};

class Human{
    public:
        int height;
        int weight;
        int age;

    public:
        int getAge(){
            return this->age;
        }
        void setWeight(int w){
            this->weight = w;
        }
};

// class male:public Human{
//     public:
//         string color;
//         void sleep(){
//             cout << "Male is sleeping" << endl;
//         }
// };

class male: protected Human{
    public:
        string color;
        void sleep(){
            cout << "Male Sleeping" << endl;
        }

        int getheight()
        {
            return this->height;
        }
        int getAge()
        {
            return this->age;
        }
        int getweight()
        {
            return this->weight;
        }
        void setweight(int x)
        {
            this->weight = x;
        }
};
//-----------------------------------------------------MAIN FUNCTION--------------------------------------------//

int main()
{
    student s1;
    cout << "Sb ok ok Chl rha h...!!" << endl;

    male m1;
    // cout << m1.age << endl;
    // cout << m1.weight << endl;
    // cout << m1.height << endl;
    // cout << m1.color << endl;

    // m1.setWeight(85);
    // cout << m1.weight << endl;
    // m1.sleep();

//--------------------------------------------------------------------------------------------------------------//

    // cout << m1.getAge() << endl;
    // cout << m1.getheight() << endl;
    // m1.setweight(55);
    // cout << m1.getweight() << endl;

//--------------------------------------------------------------------------------------------------------------//

    return 0;
}