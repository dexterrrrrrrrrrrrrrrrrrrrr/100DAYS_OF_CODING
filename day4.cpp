#include<iostream>

using namespace std;

void printF(int ind , vector<int> &ds , int arr[] , int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    ds.push_back(arr[ind]);
    printF(ind + 1 , ds , arr , n);

    ds.pop_back();
    printF(ind + 1 , ds , arr , n);
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> ds;
    cout << "All subsets of the array are:\n";
    printF(0 , ds , arr , n);

    return 0;
}