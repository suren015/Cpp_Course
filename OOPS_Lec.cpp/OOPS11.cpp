#include <bits/stdc++.h>
// #include "OOPS11_Hero.cpp"
using namespace std;

//-------------------------LOVE BABBAR LECTURE :: (1)------------------------------------//

class Hero
{
private:
    char level;

public:
    //Properties::
    char *name;
    int health;
    static int timetoComplete;

    //Constructor::
    Hero(){
        cout << "Constructor Call" << endl;
        name = new char[100];
    }

    //Parameterised Constructor::
    Hero(int health){
        this->health = health;     //this keyword::
    }

    Hero(int health,char level){
        this->health = health;
        this->level = level;
    }

    // Copy Constructor          //Pass by value stuck in infinite loop, So we use pass by reference
    Hero (Hero &suresh){
        char *tmp = new char[strlen(suresh.name) + 1];
        strcpy(tmp, suresh.name);
        this->name = tmp;
        this->health = suresh.health;
        this->level = suresh.level;
    }

    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void sethealth(int h){
        health = h;
    }
    void setlevel(char ch){
        level = ch;
    }
    void setname(char name[]){
        strcpy(this->name, name);
    }

    void print(){
        cout << endl;
        cout << "name: " << this->name << endl;
        cout << "health: " << this->health << endl;
        cout << "level: " << this->level << endl;
    }

    static void random(){
        cout << "Me Static Hu: " << timetoComplete << endl;
    }

    //Destructor ::
    ~Hero(){
        cout << "Destructor Bhai Called:: " << endl;
    }

};

int Hero ::timetoComplete = 5;

//----------------------------------------------MAIN FUNCTION--------------------------------------------//

int main()
 {
    //static allocation ::

    //class ka object::
    Hero h1; //h1 is a hero type datatype 
    cout << "size: " << sizeof(h1) << endl;

    Hero ramesh;
    ramesh.health = 70;
    cout << "health:" << ramesh.health << endl;

    //level is private so we cannot access this from outside class
    cout << "level: " << ramesh.getlevel() << endl;  //print garbage value
    ramesh.setlevel('B');
    cout << "level: " << ramesh.getlevel() << endl;

//----------------------------------------------------------------------------------//

    //dynammic allocation ::
    Hero *h2 = new Hero;   //creating a heap at some address
    cout << "health h2: " << (*h2).health << endl;

    (*h2).sethealth(90);
    (*h2).setlevel('C');

    cout << "health h2: " << (*h2).gethealth() << endl;
    cout << "level h2: " << (*h2).getlevel() << endl;

//----------------------------------------------------------------------------------//

    //Object create statically::
    Hero suren;    //constructor call Automatically which we create

    //Dynamically::
    Hero *s1 = new Hero;
    Hero *s2 = new Hero();

//----------------------------------------------------------------------------------//
    
    //Parameterised Constructor::
    Hero karan(15, 'F');
    cout << "health: " << karan.health << endl;
    cout << "level: " << karan.getlevel() << endl;

    //Copy Constructor::
    Hero suresh(25, 'K');
    cout << "health suresh: " << suresh.health << endl;
    cout << "level suresh: " << suresh.getlevel() << endl;

    Hero R(suresh);
    cout << "health R: " << R.health << endl;
    cout << "level R: " << R.getlevel() << endl;

//-----------------------------------------------------------------------------------//

    Hero d1;
    d1.sethealth(50);
    d1.setlevel('O');
    char name[10] = "Avenger";
    d1.setname(name);

    d1.print();

    //Shallow Constructor::
    //Use default copy constructor  :: for this u have to remove your own create copy constructor
    
    // Hero d2(d1);
    // d2.print();
    // // OR
    // Hero d3 = d1;
    // d3.print();

    // d1.name[0] = 'S';
    // d1.print();

    // d2.print();

//-----------------------------------------------------------------------------------//

    //Deep Constructor::
    //Use own Create Copy Constructor::

    Hero d4(d1);
    d4.print();

    d1.name[0] = 'S';
    d1.print();

    d4.print();

//----------------------------------------------------------------------------------//

    //Copy Assignment Operator::
    // Copy one object to other object
    Hero d5;
    char ch1[10] = "Rahul";
    d5.setname(ch1);
    d5.sethealth(70);
    d5.setlevel('A');

    Hero d6;
    char ch2[10] = "Ankit";
    d6.setname(ch2);
    d6.setlevel('K');
    d6.sethealth(99);

    cout << "Before Copy Assignment Operator Hero d5: " << endl;
    d5.print();
    cout << "Before Copy Assignment Operator Hero d6: " << endl;
    d6.print();

    d5 = d6;
    cout << "After Copy Assignment Operator Hero d5: " << endl;
    d5.print();
    cout << "After Copy Assignment Operator Hero d6: " << endl;
    d6.print();

//----------------------------------------------------------------------------------//

    //Destructor Function ::

    //static creating::   //Automatically call destructor
    Hero d7;

    //Dynammic Creation::   //Manually called Destructor
    Hero *d8 = new Hero();
    delete d8;

//----------------------------------------------------------------------------------//

    //static keyword::
    //create a type of data member which belongs to class not to object and we can access that without creating object.

    // Initialisation-> datatype className :: dataMemberName = value;

    cout << Hero::timetoComplete << endl;

    //access by creating an object
    Hero d9;
    cout << d9.timetoComplete << endl;

    d9.timetoComplete = 150;
    cout << d9.timetoComplete << endl;

//----------------------------------------------------------------------------------//

    // Static Function::       //Doesn't need to create object
                               // Doesn't have this keyword
                               //Only access static member

    Hero::random();

    return 0;
}
