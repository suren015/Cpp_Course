// C++ program to demonstrate the
// continue statement
#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i < 10; i++) {
  
        if (i == 5)
            continue;   // 5 is not print and from here code will go to the 7th line
        cout << i << " ";
    }
    return 0;
}