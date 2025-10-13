#include<iostream>
using namespace std;
 void print1( int n){
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j< n ; j++){
            cout<<"*";
        }cout<<endl;
    }
 }


 void print2(int n ){
    for (int i = 0;i<n;i++){
        for (int j =0 ;j<n;j++){
            cout << i;
        }cout<<endl;
    }
 }
 int main(){
    int n;
    cin>>n;
    print1(n);
    print2(n);
    return 0;   
 }