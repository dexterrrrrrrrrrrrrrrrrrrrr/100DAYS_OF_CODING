// Pattern Printing

/* *****
   *****
   *****
   *****
   ***** */


#include<iostream>
using namespace std;
 void print1( int n){
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j< n ; j++){
            cout<<"*";
        }cout<<endl;
    }
 }

/* 0000000
   1111111
   2222222
   3333333
   4444444
   5555555
   6666666 */


 void print2(int n ){
    for (int i = 0;i<n;i++){
        for (int j =0 ;j<n;j++){
            cout << i;
        }cout<<endl;
    }
 }

/*      *
       ***
      *****
     *******
    *********  */

 void print3(int n ){
    for (int i = 0;i<n;i++){
        for (int j = 0 ;j<n-i-1;j++){
            cout<<" ";
        }
        for (int j = 0 ; j<2*i+1 ; j++){
            cout<<"*";
        }
        for (int j = 0 ;j<n-i-1;j++){
            cout<<" ";
            
        }cout<<endl;
    }
 }

 int main(){
    int n;
    cin>>n;
    print1(n);
    cout<<"\n";
    print2(n);
    cout<<"\n";
    print3(n);
    return 0;   
 }