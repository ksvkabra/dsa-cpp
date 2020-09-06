#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int minNumberOfCoins(vector<int> coins, int range, int n) {
    vector<vector<int>> t(n+1, vector<int>(range+1, INT_MAX));
    for (int i=0; i<range+1; i++) {
        t[0][i] = INT_MAX-1;
    }
    for (int i=0; i<n+1; i++) {
        t[i][0] = 0;
    }

    for (int i=1; i<range+1; i++) {
        if (i%coins[0] == 0) {
            t[1][i] = i/coins[0];
        }
        else {
            t[1][i] = INT_MAX;
        }
    }

    for (int i=2; i<n+1; i++) {
        for (int j=1; j<range+1; j++) {
            if (coins[i-1] <=j) {
                cout<<j<<coins[i-1]<<i<<t[i][j-coins[i-1]]<< t[i-1][j]<<endl;
                t[i][j] = min(t[i][j-coins[i-1]]+1, t[i-1][j]);
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
    return t[n][range];
}
int main() {
    vector<int> coins{ 1, 2, 3 };
    int sum = 5;
    cout<<minNumberOfCoins(coins, sum, 3)<<endl;
    return 0;
    return 0;
}