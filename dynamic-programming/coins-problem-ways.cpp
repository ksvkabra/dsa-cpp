#include<iostream>
#include<climits>
#include<vector>

using namespace std;
int countWays(vector<int> arr, int range, int n) {
    vector<vector<int>> t(n+1, vector<int>(range+1, INT_MAX));
    for (int j=0; j<range+1; j++) {
        t[0][j] = 0;
    }
    for (int i=0; i<n+1; i++) {
        t[i][0] = 1;
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<range+1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j] + t[i][j- arr[i-1]];
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
        cout<<endl;
    }
    for (vector<int> i: t) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return t[n][range];
}
int main() {
    vector<int> coins{ 1, 2, 3 };
    int sum = 5;
    cout<<countWays(coins, sum, 3)<<endl;
    return 0;
}