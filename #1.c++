#include<iostream>
using namespace std;

template <class T> T maxi(T a,T b){
   if(a > b){
    return a;
   }
   else{
    return b;
   }
}
int main(){
    int a,b;cin >> a >> b;
    float c,d;cin >> c >> d;
    char e,f;cin >> e >> f;

    cout << maxi<int>(a,b) << endl;
    cout << maxi<float>(c,d) << endl;
    cout << maxi<char>(e,f) << endl; 
    return 0;
}