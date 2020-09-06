#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int subSetSum(vector<int> arr, int sum, int n) {
    vector<vector<int>> t(n+1, vector<int>(sum+1, INT_MAX));
    for (int i=0; i<sum+1; i++) {
        t[0][i] = 0;
    }
    for (int i=0; i<n+1; i++) {
        t[i][0] = 1;
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<sum+1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    for (vector<int> i: t) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return t[n][sum];
}

int main() {
    vector<int> arr{ 2, 3, 7, 8, 10 };
    int sum = 20;
    cout<<subSetSum(arr, sum, 5);
    return 0;
}