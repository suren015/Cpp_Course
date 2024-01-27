#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //for lower bound and upper bound array should be sorted so that time complexity be log(n)
    //lower bound ke liye jis element ka lower bound nikalna h agr wo array me present 
    //hua to wo hi output aa jaayega nhi to array me se usse bda no. output aa jaayega but upper bound ke case me only bda no.
    sort(a,a+n);

// upper_bound(f_element,l_element,no.);
//f_element==jha se start krna h chek krna
//l_element==jha tk chek krna h usse ek value aage tk
//no.==jis value ka upper bound niklna h

    //LOWER BOUND:-
    int *ptr=lower_bound(a,a+n,5);
    if(ptr==a+n){
        cout<<"Not Found"<<endl;
        return 0;
    }
    cout<<(*ptr)<<endl;

    //UPPER BOUND:-
    int *ptr1=upper_bound(a,a+n,5);
    if(ptr1==a+n){
        cout<<"Not Found"<<endl;
        return 0;
    }
    cout<<(*ptr1)<<endl;

    //for vector;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    auto it=upper_bound(v.begin(),v.end(),5);
    if(it==v.end()){
        cout<<"Not Found"<<endl;
        return 0;
    }
    cout<<(*it)<<endl; 

}